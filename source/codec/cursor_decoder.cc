//
// PROJECT:         Aspia Remote Desktop
// FILE:            codec/cursor_decoder.cc
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#include "codec/cursor_decoder.h"
#include "base/logging.h"

namespace aspia {

bool CursorDecoder::DecompressCursor(const proto::CursorShape& cursor_shape, uint8_t* image)
{
    const uint8_t* src = reinterpret_cast<const uint8_t*>(cursor_shape.data().data());
    const int src_size = cursor_shape.data().size();
    const int row_size = cursor_shape.width() * sizeof(uint32_t);

    // Consume all the data in the message.
    bool decompress_again = true;
    int used = 0;

    int row_y = 0;
    int row_pos = 0;

    while (decompress_again && used < src_size)
    {
        if (row_y > cursor_shape.height() - 1)
        {
            LOG(ERROR) << "Too much data is received for the given rectangle";
            return false;
        }

        int written = 0;
        int consumed = 0;

        decompress_again = decompressor_.Process(src + used,
                                                 src_size - used,
                                                 image + row_pos,
                                                 row_size - row_pos,
                                                 &consumed,
                                                 &written);
        used += consumed;
        row_pos += written;

        if (row_pos == row_size)
        {
            ++row_y;
            row_pos = 0;
            image += row_size;
        }
    }

    decompressor_.Reset();

    return true;
}

std::shared_ptr<MouseCursor> CursorDecoder::Decode(const proto::CursorShape& cursor_shape)
{
    size_t cache_index;

    if (cursor_shape.flags() & proto::CursorShape::CACHE)
    {
        // Bits 0-4 contain the cursor position in the cache.
        cache_index = cursor_shape.flags() & 0x1F;
    }
    else
    {
        DesktopSize size(cursor_shape.width(), cursor_shape.height());

        if (size.Width()  <= 0 || size.Width()  > (std::numeric_limits<int16_t>::max() / 2) ||
            size.Height() <= 0 || size.Height() > (std::numeric_limits<int16_t>::max() / 2))
        {
            LOG(ERROR) << "Cursor dimensions are out of bounds for SetCursor: "
                       << size.Width() << "x" << size.Height();
            return nullptr;
        }

        size_t image_size = size.Width() * size.Height() * sizeof(uint32_t);
        std::unique_ptr<uint8_t[]> image = std::make_unique<uint8_t[]>(image_size);

        if (!DecompressCursor(cursor_shape, image.get()))
            return nullptr;

        std::unique_ptr<MouseCursor> mouse_cursor =
            MouseCursor::Create(std::move(image),
                                size,
                                DesktopPoint(cursor_shape.hotspot_x(),
                                             cursor_shape.hotspot_y()));

        if (cursor_shape.flags() & proto::CursorShape::RESET_CACHE)
        {
            size_t cache_size = cursor_shape.flags() & 0x1F;

            if (!MouseCursorCache::IsValidCacheSize(cache_size))
                return nullptr;

            cache_ = std::make_unique<MouseCursorCache>(cache_size);
        }

        if (!cache_)
        {
            LOG(ERROR) << "Host did not send cache reset command";
            return nullptr;
        }

        cache_index = cache_->Add(std::move(mouse_cursor));
    }

    return cache_->Get(cache_index);
}

} // namespace aspia

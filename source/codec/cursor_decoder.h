//
// PROJECT:         Aspia Remote Desktop
// FILE:            codec/cursor_decoder.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_CODEC__CURSOR_DECODER_H
#define _ASPIA_CODEC__CURSOR_DECODER_H

#include "base/macros.h"
#include "codec/decompressor_zlib.h"
#include "desktop_capture/mouse_cursor_cache.h"
#include "proto/desktop_session_message.pb.h"

namespace aspia {

class CursorDecoder
{
public:
    CursorDecoder() = default;
    ~CursorDecoder() = default;

    std::shared_ptr<MouseCursor> Decode(
        const proto::CursorShape& cursor_shape);

private:
    bool DecompressCursor(const proto::CursorShape& cursor_shape,
                          uint8_t* image);

    std::unique_ptr<MouseCursorCache> cache_;
    DecompressorZLIB decompressor_;

    DISALLOW_COPY_AND_ASSIGN(CursorDecoder);
};

} // namespace aspia

#endif // _ASPIA_CODEC__CURSOR_DECODER_H

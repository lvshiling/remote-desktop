//
// PROJECT:         Aspia Remote Desktop
// FILE:            ui/file_transfer/file_list_ctrl.cc
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#include "ui/file_transfer/file_list_ctrl.h"
#include "ui/file_transfer/file_manager_helpers.h"
#include "ui/resource.h"
#include "base/version_helpers.h"
#include "base/strings/unicode.h"
#include "base/logging.h"

#include <uxtheme.h>

namespace aspia {

bool FileListCtrl::CreateFileList(HWND parent, int control_id)
{
    const DWORD style = WS_CHILD | WS_VISIBLE | WS_TABSTOP | LVS_REPORT | LVS_SHOWSELALWAYS;

    if (!Create(parent, CWindow::rcDefault, nullptr, style, WS_EX_CLIENTEDGE, control_id))
    {
        DLOG(ERROR) << "Unable to create file list window: " << GetLastSystemErrorString();
        return false;
    }

    DWORD ex_style = LVS_EX_FULLROWSELECT;

    if (IsWindowsVistaOrGreater())
    {
        ::SetWindowTheme(*this, L"explorer", nullptr);
        ex_style |= LVS_EX_DOUBLEBUFFER;
    }

    SetExtendedListViewStyle(ex_style);

    if (imagelist_.Create(GetSystemMetrics(SM_CXSMICON),
                          GetSystemMetrics(SM_CYSMICON),
                          ILC_MASK | ILC_COLOR32,
                          1, 1))
    {
        SetImageList(imagelist_, LVSIL_SMALL);
    }

    return true;
}

void FileListCtrl::Read(std::shared_ptr<proto::FileList> list)
{
    DeleteAllItems();
    imagelist_.RemoveAll();
    DeleteAllColumns();

    ModifyStyle(LVS_SINGLESEL, LVS_EDITLABELS);

    AddNewColumn(IDS_FT_COLUMN_NAME, 180);
    AddNewColumn(IDS_FT_COLUMN_SIZE, 70);
    AddNewColumn(IDS_FT_COLUMN_TYPE, 100);
    AddNewColumn(IDS_FT_COLUMN_MODIFIED, 100);

    list_.swap(list);

    // All directories have the same icon.
    CIcon icon(GetDirectoryIcon());

    int icon_index = imagelist_.AddIcon(icon);
    const int object_count = list_->item_size();

    CString file_folder;
    file_folder.LoadStringW(IDS_FT_FILE_FOLDER);

    // Enumerate the directories first.
    for (int object_index = 0; object_index < object_count; ++object_index)
    {
        const proto::FileList::Item& item = list_->item(object_index);

        if (!item.is_directory())
            continue;

        FilePath name = std::experimental::filesystem::u8path(item.name());

        const int item_index = AddItem(GetItemCount(), 0, name.c_str(), icon_index);
        SetItemData(item_index, object_index);
        SetItemText(item_index, 2, file_folder);
        SetItemText(item_index, 3, TimeToString(item.modification_time()).c_str());
    }

    // Enumerate the files.
    for (int object_index = 0; object_index < object_count; ++object_index)
    {
        const proto::FileList::Item& object = list_->item(object_index);

        if (object.is_directory())
            continue;

        FilePath name = std::experimental::filesystem::u8path(object.name());

        icon = GetFileIcon(name);
        icon_index = imagelist_.AddIcon(icon);

        const int item_index = AddItem(GetItemCount(), 0, name.c_str(), icon_index);

        SetItemData(item_index, object_index);
        SetItemText(item_index, 1, SizeToString(object.size()).c_str());
        SetItemText(item_index, 2, GetFileTypeString(name));
        SetItemText(item_index, 3, TimeToString(object.modification_time()).c_str());
    }
}

void FileListCtrl::Read(const proto::DriveList& list)
{
    DeleteAllItems();
    imagelist_.RemoveAll();
    DeleteAllColumns();

    ModifyStyle(LVS_EDITLABELS, LVS_SINGLESEL);

    AddNewColumn(IDS_FT_COLUMN_NAME, 130);
    AddNewColumn(IDS_FT_COLUMN_TYPE, 150);
    AddNewColumn(IDS_FT_COLUMN_TOTAL_SPACE, 80);
    AddNewColumn(IDS_FT_COLUMN_FREE_SPACE, 80);

    list_.reset();

    const int object_count = list.item_size();

    for (int object_index = 0; object_index < object_count; ++object_index)
    {
        const proto::DriveList::Item& object = list.item(object_index);

        const CIcon icon(GetDriveIcon(object.type()));
        const int icon_index = imagelist_.AddIcon(icon);

        const CString display_name(GetDriveDisplayName(object));

        const int item_index = AddItem(GetItemCount(), 0, display_name, icon_index);
        SetItemData(item_index, object_index);
        SetItemText(item_index, 1, GetDriveDescription(object.type()));

        if (object.total_space())
            SetItemText(item_index, 2, SizeToString(object.total_space()).c_str());

        if (object.free_space())
            SetItemText(item_index, 3, SizeToString(object.free_space()).c_str());
    }
}

bool FileListCtrl::HasFileList() const
{
    return list_ != nullptr;
}

const proto::FileList::Item& FileListCtrl::Object(int object_index) const
{
    DCHECK(HasFileList());
    DCHECK(IsValidObjectIndex(object_index));

    return list_->item(object_index);
}

FilePath FileListCtrl::ObjectName(int object_index) const
{
    DCHECK(HasFileList());
    DCHECK(IsValidObjectIndex(object_index));

    return std::experimental::filesystem::u8path(list_->item(object_index).name());
}

bool FileListCtrl::IsDirectoryObject(int object_index) const
{
    DCHECK(HasFileList());
    DCHECK(IsValidObjectIndex(object_index));

    return list_->item(object_index).is_directory();
}

proto::FileList::Item* FileListCtrl::FirstSelectedObject() const
{
    const int selected_item = GetNextItem(-1, LVNI_SELECTED);
    if (selected_item == -1)
        return nullptr;

    const int object_index = GetItemData(selected_item);

    if (!IsValidObjectIndex(object_index))
        return nullptr;

    return list_->mutable_item(object_index);
}

void FileListCtrl::AddDirectory()
{
    if (!HasFileList())
        return;

    const CIcon folder_icon(GetDirectoryIcon());
    const int icon_index = imagelist_.AddIcon(folder_icon);

    CString folder_name;
    folder_name.LoadStringW(IDS_FT_NEW_FOLDER);

    SetFocus();

    const int item_index = AddItem(GetItemCount(), 0, folder_name, icon_index);
    SetItemData(item_index, kNewFolderObjectIndex);
    EditLabel(item_index);
}

int FileListCtrl::GetColumnCount() const
{
    CHeaderCtrl header(GetHeader());

    if (!header)
        return 0;

    return header.GetItemCount();
}

void FileListCtrl::DeleteAllColumns()
{
    int count = GetColumnCount();

    while (--count >= 0)
        DeleteColumn(count);
}

void FileListCtrl::AddNewColumn(UINT string_id, int width)
{
    CString text;
    text.LoadStringW(string_id);

    const int column_index = AddColumn(text, GetColumnCount());
    SetColumnWidth(column_index, width);
}

bool FileListCtrl::IsValidObjectIndex(int object_index) const
{
    if (!list_)
        return false;

    if (object_index >= 0 && object_index < list_->item_size())
        return true;

    return false;
}

FileListCtrl::Iterator::Iterator(const FileListCtrl& list, Mode mode)
    : list_(list),
      mode_(mode)
{
    item_index_ = list.GetNextItem(-1, mode_);
}

bool FileListCtrl::Iterator::IsAtEnd() const
{
    return item_index_ == -1;
}

void FileListCtrl::Iterator::Advance()
{
    item_index_ = list_.GetNextItem(item_index_, mode_);
}

const proto::FileList::Item& FileListCtrl::Iterator::Object() const
{
    static const proto::FileList::Item empty_item;

    if (item_index_ == -1)
        return empty_item;

    const int object_index = list_.GetItemData(item_index_);

    if (!list_.IsValidObjectIndex(object_index))
        return empty_item;

    return list_.list_->item(object_index);
}

int FileListCtrl::GetObjectUnderMousePointer() const
{
    LVHITTESTINFO hti;
    memset(&hti, 0, sizeof(hti));

    if (!GetCursorPos(&hti.pt))
        return kInvalidObjectIndex;

    if (!ScreenToClient(&hti.pt))
        return kInvalidObjectIndex;

    hti.flags = LVHT_ONITEMICON | LVHT_ONITEMLABEL;
    const int item_index = HitTest(&hti);
    if (item_index == -1)
        return kInvalidObjectIndex;

    return GetItemData(item_index);
}

} // namespace aspia

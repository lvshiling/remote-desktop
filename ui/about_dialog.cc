//
// PROJECT:         Aspia Remote Desktop
// FILE:            ui/about_dialog.cc
// LICENSE:         See top-level directory
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#include "ui/about_dialog.h"
#include "ui/resource.h"
#include "base/logging.h"

#include <windowsx.h>
#include <shellapi.h>

namespace aspia {

INT_PTR UiAboutDialog::DoModal(HWND parent)
{
    return Run(UiModule::Current(), parent, IDD_ABOUT);
}

INT_PTR UiAboutDialog::OnMessage(UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            icon_ = Module().Icon(IDI_MAIN, 48, 48, LR_CREATEDIBSECTION);
            Static_SetIcon(GetDlgItem(IDC_ABOUT_ICON), icon_);

            SetWindowTextW(GetDlgItem(IDC_ABOUT_EDIT),
                           Module().String(IDS_ABOUT_STRING).c_str());

            SetFocus(GetDlgItem(IDC_DONATE_BUTTON));
        }
        break;

        case WM_COMMAND:
        {
            switch (LOWORD(wparam))
            {
                case IDOK:
                    EndDialog();
                    break;

                case IDC_DONATE_BUTTON:
                {
                    ShellExecuteW(nullptr,
                                  L"open",
                                  Module().String(IDS_DONATE_LINK).c_str(),
                                  nullptr,
                                  nullptr,
                                  SW_SHOWNORMAL);
                }
                break;

                case IDC_SITE_BUTTON:
                {
                    ShellExecuteW(nullptr,
                                  L"open",
                                  Module().String(IDS_SITE_LINK).c_str(),
                                  nullptr,
                                  nullptr,
                                  SW_SHOWNORMAL);
                }
                break;
            }
        }
        break;

        case WM_CLOSE:
            EndDialog();
            break;
    }

    return 0;
}

} // namespace aspia

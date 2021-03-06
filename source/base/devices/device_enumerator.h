//
// PROJECT:         Aspia Remote Desktop
// FILE:            base/devices/device_enumerator.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_BASE__DEVICES__DEVICE_ENUMERATOR_H
#define _ASPIA_BASE__DEVICES__DEVICE_ENUMERATOR_H

#include "base/macros.h"

#include <setupapi.h>
#include <string>

namespace aspia {

class DeviceEnumerator
{
public:
    DeviceEnumerator();
    ~DeviceEnumerator();

    bool IsAtEnd() const;
    void Advance();

    std::string GetFriendlyName() const;
    std::string GetDescription() const;
    std::string GetDriverVersion() const;
    std::string GetDriverDate() const;
    std::string GetDriverVendor() const;
    std::string GetDeviceID() const;

private:
    std::wstring GetDriverRegistryValue(const WCHAR* key_name) const;

    HDEVINFO device_info_;
    mutable SP_DEVINFO_DATA device_info_data_;
    DWORD device_index_ = 0;

    DISALLOW_COPY_AND_ASSIGN(DeviceEnumerator);
};

} // namespace aspia

#endif // _ASPIA_BASE__DEVICES__DEVICE_ENUMERATOR_H

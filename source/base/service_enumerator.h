//
// PROJECT:         Aspia Remote Desktop
// FILE:            base/service_enumerator.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_BASE__SERVICE_ENUMERATOR_H
#define _ASPIA_BASE__SERVICE_ENUMERATOR_H

#include "base/scoped_object.h"

#include <memory>
#include <string>

namespace aspia {

class ServiceEnumerator
{
public:
    enum class Type { SERVICES = 0, DRIVERS = 1 };

    ServiceEnumerator(Type type);
    ~ServiceEnumerator() = default;

    bool IsAtEnd() const;
    void Advance();

    std::string GetName() const;
    std::string GetDisplayName() const;
    std::string GetDescription() const;

    enum class Status
    {
        UNKNOWN          = 0,
        CONTINUE_PENDING = 1,
        PAUSE_PENDING    = 2,
        PAUSED           = 3,
        RUNNING          = 4,
        START_PENDING    = 5,
        STOP_PENDING     = 6,
        STOPPED          = 7
    };

    Status GetStatus() const;

    enum class StartupType
    {
        UNKNOWN      = 0,
        AUTO_START   = 1,
        DEMAND_START = 2,
        DISABLED     = 3,
        BOOT_START   = 4,
        SYSTEM_START = 5
    };

    StartupType GetStartupType() const;
    std::string GetBinaryPath() const;
    std::string GetStartName() const;

private:
    ENUM_SERVICE_STATUS_PROCESS* GetCurrentService() const;
    SC_HANDLE GetCurrentServiceHandle() const;
    LPQUERY_SERVICE_CONFIG GetCurrentServiceConfig() const;

    mutable ScopedScHandle manager_handle_;

    std::unique_ptr<uint8_t[]> services_buffer_;
    DWORD services_count_ = 0;

    mutable ScopedScHandle current_service_handle_;
    mutable std::unique_ptr<uint8_t[]> current_service_config_;
    DWORD current_service_index_ = 0;

    DISALLOW_COPY_AND_ASSIGN(ServiceEnumerator);
};

} // namespace aspia

#endif // _ASPIA_BASE__SERVICE_ENUMERATOR_H

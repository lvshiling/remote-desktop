//
// PROJECT:         Aspia Remote Desktop
// FILE:            base/service_enumerator.cc
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#include "base/service_enumerator.h"
#include "base/strings/unicode.h"
#include "base/logging.h"

namespace aspia {

ServiceEnumerator::ServiceEnumerator(Type type)
{
    manager_handle_.Reset(OpenSCManagerW(nullptr, nullptr, SC_MANAGER_ENUMERATE_SERVICE));
    if (!manager_handle_.IsValid())
        return;

    DWORD bytes_needed = 0;
    DWORD resume_handle = 0;

    if (EnumServicesStatusExW(manager_handle_,
                              SC_ENUM_PROCESS_INFO,
                              type == Type::SERVICES ? SERVICE_WIN32 : SERVICE_DRIVER,
                              SERVICE_STATE_ALL,
                              nullptr,
                              0,
                              &bytes_needed,
                              &services_count_,
                              &resume_handle,
                              nullptr)
        || GetLastError() != ERROR_MORE_DATA)
    {
        LOG(ERROR) << "Unexpected return value: " << GetLastSystemErrorString();
        return;
    }

    services_buffer_ = std::make_unique<uint8_t[]>(bytes_needed);

    if (!EnumServicesStatusExW(manager_handle_,
                               SC_ENUM_PROCESS_INFO,
                               type == Type::SERVICES ? SERVICE_WIN32 : SERVICE_DRIVER,
                               SERVICE_STATE_ALL,
                               services_buffer_.get(),
                               bytes_needed,
                               &bytes_needed,
                               &services_count_,
                               &resume_handle,
                               nullptr))
    {
        LOG(ERROR) << "EnumServicesStatusExW() failed: " << GetLastSystemErrorString();
        services_buffer_.reset();
        services_count_ = 0;
    }
}

bool ServiceEnumerator::IsAtEnd() const
{
    return current_service_index_ >= services_count_;
}

void ServiceEnumerator::Advance()
{
    current_service_handle_.Reset();
    current_service_config_.reset();
    ++current_service_index_;
}

ENUM_SERVICE_STATUS_PROCESS* ServiceEnumerator::GetCurrentService() const
{
    if (!services_buffer_ || !services_count_ || IsAtEnd())
        return nullptr;

    ENUM_SERVICE_STATUS_PROCESS* services =
        reinterpret_cast<ENUM_SERVICE_STATUS_PROCESS*>(services_buffer_.get());

    return &services[current_service_index_];
}

SC_HANDLE ServiceEnumerator::GetCurrentServiceHandle() const
{
    if (!current_service_handle_.IsValid())
    {
        ENUM_SERVICE_STATUS_PROCESS* services =
            reinterpret_cast<ENUM_SERVICE_STATUS_PROCESS*>(services_buffer_.get());

        const DWORD desired_access =
            SERVICE_QUERY_CONFIG | SERVICE_QUERY_STATUS | SERVICE_ENUMERATE_DEPENDENTS;

        current_service_handle_.Reset(OpenServiceW(manager_handle_,
                                                   services[current_service_index_].lpServiceName,
                                                   desired_access));
    }

    return current_service_handle_;
}

LPQUERY_SERVICE_CONFIG ServiceEnumerator::GetCurrentServiceConfig() const
{
    if (!current_service_config_)
    {
        SC_HANDLE service_handle = GetCurrentServiceHandle();

        DWORD bytes_needed = 0;

        if (QueryServiceConfigW(service_handle,
                                nullptr,
                                0,
                                &bytes_needed)
            || GetLastError() != ERROR_INSUFFICIENT_BUFFER)
        {
            LOG(ERROR) << "QueryServiceConfigW() failed: " << GetLastSystemErrorString();
            return nullptr;
        }

        current_service_config_ = std::make_unique<uint8_t[]>(bytes_needed);

        if (!QueryServiceConfigW(service_handle,
                                 reinterpret_cast<LPQUERY_SERVICE_CONFIG>(
                                     current_service_config_.get()),
                                 bytes_needed,
                                 &bytes_needed))
        {
            LOG(ERROR) << "QueryServiceConfigW() failed: " << GetLastSystemErrorString();
            return nullptr;
        }
    }

    return reinterpret_cast<LPQUERY_SERVICE_CONFIG>(current_service_config_.get());
}

std::string ServiceEnumerator::GetName() const
{
    ENUM_SERVICE_STATUS_PROCESS* service = GetCurrentService();

    if (!service)
        return std::string();

    return UTF8fromUNICODE(service->lpServiceName);
}

std::string ServiceEnumerator::GetDisplayName() const
{
    ENUM_SERVICE_STATUS_PROCESS* service = GetCurrentService();

    if (!service)
        return std::string();

    return UTF8fromUNICODE(service->lpDisplayName);
}

std::string ServiceEnumerator::GetDescription() const
{
    SC_HANDLE service_handle = GetCurrentServiceHandle();

    DWORD bytes_needed = 0;

    if (QueryServiceConfig2W(service_handle,
                             SERVICE_CONFIG_DESCRIPTION,
                             nullptr,
                             0,
                             &bytes_needed)
        || GetLastError() != ERROR_INSUFFICIENT_BUFFER)
    {
        LOG(WARNING) << "QueryServiceConfig2W() failed: " << GetLastSystemErrorString();
        return std::string();
    }

    std::unique_ptr<uint8_t[]> result = std::make_unique<uint8_t[]>(bytes_needed);

    if (!QueryServiceConfig2W(service_handle,
                              SERVICE_CONFIG_DESCRIPTION,
                              result.get(),
                              bytes_needed,
                              &bytes_needed))
    {
        LOG(WARNING) << "QueryServiceConfig2W() failed: " << GetLastSystemErrorString();
        return std::string();
    }

    SERVICE_DESCRIPTION* description = reinterpret_cast<SERVICE_DESCRIPTION*>(result.get());

    return UTF8fromUNICODE(description->lpDescription);
}

ServiceEnumerator::Status ServiceEnumerator::GetStatus() const
{
    ENUM_SERVICE_STATUS_PROCESS* service = GetCurrentService();

    if (!service)
        return Status::UNKNOWN;

    switch (service->ServiceStatusProcess.dwCurrentState)
    {
        case SERVICE_CONTINUE_PENDING:
            return Status::CONTINUE_PENDING;

        case SERVICE_PAUSE_PENDING:
            return Status::PAUSE_PENDING;

        case SERVICE_PAUSED:
            return Status::PAUSED;

        case SERVICE_RUNNING:
            return Status::RUNNING;

        case SERVICE_START_PENDING:
            return Status::START_PENDING;

        case SERVICE_STOP_PENDING:
            return Status::STOP_PENDING;

        case SERVICE_STOPPED:
            return Status::STOPPED;

        default:
            return Status::UNKNOWN;
    }
}

ServiceEnumerator::StartupType ServiceEnumerator::GetStartupType() const
{
    LPQUERY_SERVICE_CONFIG config = GetCurrentServiceConfig();

    if (!config)
        return StartupType::UNKNOWN;

    switch (config->dwStartType)
    {
        case SERVICE_AUTO_START:
            return StartupType::AUTO_START;

        case SERVICE_DEMAND_START:
            return StartupType::DEMAND_START;

        case SERVICE_DISABLED:
            return StartupType::DISABLED;

        case SERVICE_BOOT_START:
            return StartupType::BOOT_START;

        case SERVICE_SYSTEM_START:
            return StartupType::SYSTEM_START;

        default:
            return StartupType::UNKNOWN;
    }
}

std::string ServiceEnumerator::GetBinaryPath() const
{
    LPQUERY_SERVICE_CONFIG config = GetCurrentServiceConfig();

    if (!config)
        return std::string();

    return UTF8fromUNICODE(config->lpBinaryPathName);
}

std::string ServiceEnumerator::GetStartName() const
{
    LPQUERY_SERVICE_CONFIG config = GetCurrentServiceConfig();

    if (!config)
        return std::string();

    return UTF8fromUNICODE(config->lpServiceStartName);
}

} // namespace aspia

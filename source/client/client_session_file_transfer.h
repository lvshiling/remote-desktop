//
// PROJECT:         Aspia Remote Desktop
// FILE:            client/client_session_file_transfer.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_CLIENT__CLIENT_SESSION_FILE_TRANSFER_H
#define _ASPIA_CLIENT__CLIENT_SESSION_FILE_TRANSFER_H

#include "client/client_session.h"
#include "client/file_request_sender_local.h"
#include "client/file_request_sender_remote.h"
#include "ui/file_transfer/file_manager.h"

namespace aspia {

class ClientSessionFileTransfer :
    public ClientSession,
    private FileManagerWindow::Delegate
{
public:
    ClientSessionFileTransfer(const ClientConfig& config,
                              std::shared_ptr<NetworkChannelProxy> channel_proxy);
    ~ClientSessionFileTransfer();

private:
    // FileManagerWindow::Delegate implementation.
    void OnWindowClose() override;

    std::unique_ptr<FileManagerWindow> file_manager_;

    std::unique_ptr<FileRequestSenderLocal> local_sender_;
    std::unique_ptr<FileRequestSenderRemote> remote_sender_;

    DISALLOW_COPY_AND_ASSIGN(ClientSessionFileTransfer);
};

} // namespace aspia

#endif // _ASPIA_CLIENT__CLIENT_SESSION_FILE_TRANSFER_H

//
// PROJECT:         Aspia Remote Desktop
// FILE:            client/client.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_CLIENT__CLIENT_H
#define _ASPIA_CLIENT__CLIENT_H

#include "client/client_session.h"
#include "base/message_loop/message_loop_thread.h"
#include "network/network_channel.h"
#include "network/network_channel_proxy.h"
#include "proto/auth_session.pb.h"
#include "ui/status_dialog.h"

namespace aspia {

class Client :
    private MessageLoopThread::Delegate,
    private StatusDialog::Delegate
{
public:
    class Delegate
    {
    public:
        virtual ~Delegate() = default;
        virtual void OnSessionTerminate() = 0;
    };

    Client(std::shared_ptr<NetworkChannel> channel,
           const ClientConfig& config,
           Delegate* delegate);

    ~Client();

    bool IsTerminatedSession() const;

private:
    // MessageLoopThread::Delegate implementation.
    void OnBeforeThreadRunning() override;
    void OnAfterThreadRunning() override;

    void OnNetworkChannelStatusChange(NetworkChannel::Status status);

    // StatusDialog::Delegate implementation.
    void OnStatusDialogOpen() override;

    void OnAuthRequestSended();
    void DoAuthorize(const IOBuffer& buffer);
    void OpenStatusDialog();

    Delegate* delegate_;

    MessageLoopThread ui_thread_;
    std::shared_ptr<MessageLoopProxy> runner_;

    proto::Status status_;
    StatusDialog status_dialog_;

    std::shared_ptr<NetworkChannel> channel_;
    std::shared_ptr<NetworkChannelProxy> channel_proxy_;

    ClientConfig config_;
    std::unique_ptr<ClientSession> session_;

    DISALLOW_COPY_AND_ASSIGN(Client);
};

} // namespace aspia

#endif // _ASPIA_CLIENT__CLIENT_H

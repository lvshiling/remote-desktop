//
// PROJECT:         Aspia Remote Desktop
// FILE:            base/message_loop/message_loop_thread.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_BASE__MESSAGE_LOOP__MESSAGE_LOOP_THREAD_H
#define _ASPIA_BASE__MESSAGE_LOOP__MESSAGE_LOOP_THREAD_H

#include "base/message_loop/message_loop.h"
#include "base/message_loop/message_loop_proxy.h"
#include "base/synchronization/waitable_event.h"

#include <atomic>
#include <thread>

namespace aspia {

class MessageLoopThread
{
public:
    MessageLoopThread() = default;
    ~MessageLoopThread();

    class Delegate
    {
    public:
        virtual ~Delegate() = default;

        // Called just prior to starting the message loop.
        virtual void OnBeforeThreadRunning() { }

        virtual void OnThreadRunning(MessageLoop* message_loop);

        // Called just after the message loop ends.
        virtual void OnAfterThreadRunning() { }
    };

    // Starts the thread.
    void Start(MessageLoop::Type message_loop_type, Delegate* delegate = nullptr);

    // Signals the thread to exit in the near future.
    void StopSoon();

    // Signals the thread to exit and returns once the thread has exited.  After
    // this method returns, the Thread object is completely reset and may be used
    // as if it were newly constructed (i.e., Start may be called again).
    // Stop may be called multiple times and is simply ignored if the thread is
    // already stopped.
    void Stop();

    void Join();

    bool IsRunning() const { return running_; }

    MessageLoop* message_loop() const
    {
        return message_loop_;
    }

    std::shared_ptr<MessageLoopProxy> message_loop_proxy() const
    {
        return message_loop_ ? message_loop_->message_loop_proxy() : nullptr;
    }

    uint32_t thread_id() const
    {
        return thread_id_;
    }

    enum class Priority
    {
        ABOVE_NORMAL = THREAD_PRIORITY_ABOVE_NORMAL,
        BELOW_NORMAL = THREAD_PRIORITY_BELOW_NORMAL,
        HIGHEST      = THREAD_PRIORITY_HIGHEST,
        IDLE         = THREAD_PRIORITY_IDLE,
        LOWEST       = THREAD_PRIORITY_LOWEST,
        NORMAL       = THREAD_PRIORITY_NORMAL
    };

    bool SetPriority(Priority priority);

private:
    void ThreadMain(MessageLoop::Type message_loop_type);

    Delegate* delegate_ = nullptr;

    enum class State { STARTING, STARTED, STOPPING, STOPPED };

    std::atomic<State> state_ = State::STOPPED;

    std::thread thread_;
    std::mutex thread_lock_;
    uint32_t thread_id_ = 0;

    // True while inside of Run().
    std::atomic_bool running_ = false;

    WaitableEvent start_event_ { WaitableEvent::ResetPolicy::MANUAL,
                                 WaitableEvent::InitialState::NOT_SIGNALED };

    MessageLoop* message_loop_ = nullptr;

    DISALLOW_COPY_AND_ASSIGN(MessageLoopThread);
};

} // namespace aspia

#endif // _ASPIA_BASE__MESSAGE_LOOP__MESSAGE_LOOP_THREAD_H

//
// PROJECT:         Aspia Remote Desktop
// FILE:            base/message_loop/message_pump_default.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_BASE__MESSAGE_LOOP__MESSAGE_PUMP_DEFAULT_H
#define _ASPIA_BASE__MESSAGE_LOOP__MESSAGE_PUMP_DEFAULT_H

#include "base/message_loop/message_pump.h"
#include "base/synchronization/waitable_event.h"

namespace aspia {

class MessagePumpDefault : public MessagePump
{
public:
    MessagePumpDefault() = default;
    ~MessagePumpDefault() = default;

    // MessagePump methods:
    void Run(Delegate* delegate) override;
    void Quit() override;
    void ScheduleWork() override;
    void ScheduleDelayedWork(const TimePoint& delayed_work_time) override;

private:
    // This flag is set to false when Run should return.
    bool keep_running_ = true;

    // Used to sleep until there is more work to do.
    WaitableEvent event_ { WaitableEvent::ResetPolicy::AUTOMATIC,
                           WaitableEvent::InitialState::NOT_SIGNALED };

    // The time at which we should call DoDelayedWork.
    TimePoint delayed_work_time_;

    DISALLOW_COPY_AND_ASSIGN(MessagePumpDefault);
};

} // namespace aspia

#endif // _ASPIA_BASE__MESSAGE_LOOP__MESSAGE_PUMP_DEFAULT_H

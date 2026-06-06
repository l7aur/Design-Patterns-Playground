#pragma once

#include "Command.hpp"

template<typename Receiver>
class SimpleCommand : public Command
{
public:
    SimpleCommand(
        Receiver* const rcv,
        void (Receiver::*operation)()
    );
    ~SimpleCommand() override = default;

    void execute() override;
    virtual void undo() override;

protected:
    Receiver* const receiver;
    void (Receiver::*action)();
};

template <typename Receiver>
inline SimpleCommand<Receiver>::SimpleCommand(
    Receiver* const rcv,
    void (Receiver::*operation)()
)
    : receiver{ rcv }
    , action{ operation }
{
}

template <typename Receiver>
inline void SimpleCommand<Receiver>::execute()
{
    (receiver->*action)();
}

template <typename Receiver>
inline void SimpleCommand<Receiver>::undo()
{
    // do nothing
}
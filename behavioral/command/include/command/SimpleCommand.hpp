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
    ~SimpleCommand() = default;

    void execute() override;
    void undo() override;
    void redo() override;

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
}

template <typename Receiver>
inline void SimpleCommand<Receiver>::redo()
{
}
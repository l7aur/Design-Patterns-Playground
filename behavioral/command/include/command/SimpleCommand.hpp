#pragma once

#include "Command.hpp"

#include <memory>

template<typename Receiver>
class SimpleCommand : public Command
{
public:
    SimpleCommand(std::unique_ptr<Receiver> rcv, void (Receiver::*operation)());
    ~SimpleCommand() = default;

    void execute() override;
    void undo() override;
    void redo() override;

private:
    std::unique_ptr<Receiver> receiver;
    void (Receiver::*operation)() action;
};

template <typename Receiver>
inline SimpleCommand<Receiver>::SimpleCommand(std::unique_ptr<Receiver> rcv, void (Receiver::*operation)())
    : receiver{ std::move(recv) }
    , action{ operation }
{
}

template <typename Receiver>
inline void SimpleCommand<Receiver>::execute()
{
}

template <typename Receiver>
inline void SimpleCommand<Receiver>::undo()
{
}

template <typename Receiver>
inline void SimpleCommand<Receiver>::redo()
{
}
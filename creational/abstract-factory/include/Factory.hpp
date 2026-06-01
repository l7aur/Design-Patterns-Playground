#pragma once

#include "Teacher.hpp"
#include "Student.hpp"

#include <memory>

class Factory
{
// Generally, implementations of this interface are singletons
public:
    virtual std::unique_ptr<Student> createStudent() const = 0;
    virtual std::unique_ptr<Teacher> createTeacher() const = 0;
};
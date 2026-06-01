#pragma once

#include "Factory.hpp"

class UniversityFactory : public Factory
{
public:
    std::unique_ptr<Student> createStudent() const override;
    std::unique_ptr<Teacher> createTeacher() const override;
};
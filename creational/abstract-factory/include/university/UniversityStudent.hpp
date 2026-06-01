#pragma once

#include "Student.hpp"

class UniversityStudent : public Student
{
public:
    void learn() const override;
};
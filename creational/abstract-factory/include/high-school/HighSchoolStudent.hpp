#pragma once

#include "Student.hpp"

class HighSchoolStudent : public Student
{
public:
    void learn() const override;
};
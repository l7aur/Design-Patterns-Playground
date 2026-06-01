#pragma once

#include "Teacher.hpp"

class HighSchoolTeacher : public Teacher
{
public:
    void teach() const override;
};
#include "HighSchoolFactory.hpp"

#include "HighSchoolStudent.hpp"
#include "HighSchoolTeacher.hpp"

std::unique_ptr<Student> HighSchoolFactory::createStudent() const
{
    return std::make_unique<HighSchoolStudent>();
}

std::unique_ptr<Teacher> HighSchoolFactory::createTeacher() const
{
    return std::make_unique<HighSchoolTeacher>();
}
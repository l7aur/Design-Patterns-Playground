#include "UniversityFactory.hpp"

#include "UniversityStudent.hpp"
#include "UniversityTeacher.hpp"

std::unique_ptr<Student> UniversityFactory::createStudent() const
{
    return std::make_unique<UniversityStudent>();
}

std::unique_ptr<Teacher> UniversityFactory::createTeacher() const
{
    return std::make_unique<UniversityTeacher>();
}
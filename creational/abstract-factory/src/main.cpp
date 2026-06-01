#include "HighSchoolFactory.hpp"
#include "UniversityFactory.hpp"

int main(int argc, char* argv[])
{
    std::unique_ptr<Factory> f = std::make_unique<UniversityFactory>();
    // std::unique_ptr<Factory> f = std::make_unique<HighSchoolFactory>();

    auto student = f->createStudent();
    auto teacher = f->createTeacher();

    teacher->teach();
    student->learn();

    return 0;
}
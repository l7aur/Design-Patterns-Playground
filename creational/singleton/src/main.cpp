#include "QuestionCreator.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << QuestionCreator::instance().createQuestion(QuestionCreator::QuestionType::Q2);

    return 0;
}
#include "QuestionCreator.hpp"

QuestionCreator &QuestionCreator::instance()
{
    static QuestionCreator me;
    return me;
}

std::string QuestionCreator::createQuestion(const QuestionType type) const
{
    switch (type)
    {
    case QuestionType::Q1:
        return "This is Q1!";
    case QuestionType::Q2:
        return "This is Q2!";
    case QuestionType::Q3:
        return "This is Q3!";
    default:
        break;
    }
    return "This is a forbidden question!";
}

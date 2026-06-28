#pragma once

#include <memory>
#include <string>

class QuestionCreator
{
public:
    enum class QuestionType
    {
        Q1,
        Q2,
        Q3
    };
    static QuestionCreator &instance();

    QuestionCreator(const QuestionCreator &) = delete;
    void operator=(const QuestionCreator &) = delete;

    std::string createQuestion(QuestionType type) const;

protected:
    QuestionCreator() = default;
};
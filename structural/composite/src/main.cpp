#include "Portofolio.hpp"
#include "Investment.hpp"
#include "Loan.hpp"

int main(int argc, char* argv[])
{
    auto portofolio1 = std::make_unique<Portofolio>("John's Portofolio", 1);
    auto portofolio2 = std::make_unique<Portofolio>("Mary's Portofolio", 2);
    auto loan1 = std::make_unique<Loan>("Loan 1", -100);
    auto loan2 = std::make_unique<Loan>("Loan 2", -200);
    auto loan3 = std::make_unique<Loan>("Loan 3", -300);

    auto investment1 = std::make_unique<Investment>("Investment 1", 1000);
    auto investment2 = std::make_unique<Investment>("Investment 2", 5000);


    try {
        loan1->add(std::make_unique<Loan>("Malicious Loan", -10000));
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        investment1->add(std::make_unique<Loan>("Malicious Investment", 10000));
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    portofolio1->add(std::move(loan1));
    portofolio1->add(std::move(investment1));
    portofolio1->add(std::move(loan2));
    portofolio1->print(std::cout);
    std::cout << std::endl;

    portofolio2->add(std::move(loan3));
    portofolio2->add(std::move(investment2));
    portofolio2->print(std::cout);
    std::cout << std::endl;

    portofolio1->add(std::move(portofolio2));
    portofolio1->print(std::cout);
    std::cout << std::endl;

    portofolio1->remove("Loan 1");
    portofolio1->remove("Loan 2");
    portofolio1->print(std::cout);
    std::cout << std::endl;

    portofolio1->remove("Mary's Portofolio");
    portofolio1->print(std::cout);
    std::cout << std::endl;

    return 0;
}
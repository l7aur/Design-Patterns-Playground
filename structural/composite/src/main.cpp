#include "Investment.hpp"
#include "Account.hpp"
#include "Loan.hpp"

int main(int argc, char* argv[])
{
    auto account1 = std::make_unique<Account>("John", 1);
    auto account2 = std::make_unique<Account>("Mary", 2);
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

    account1->add(std::move(loan1));
    account1->add(std::move(investment1));
    account1->add(std::move(loan2));
    account1->print(std::cout);
    std::cout << std::endl;

    account2->add(std::move(loan3));
    account2->add(std::move(investment2));
    account2->print(std::cout);
    std::cout << std::endl;

    account1->add(std::move(account2));
    account1->print(std::cout);
    std::cout << std::endl;

    account1->remove("Loan 1");
    account1->remove("Loan 2");
    account1->print(std::cout);
    std::cout << std::endl;

    account1->remove("Mary");
    account1->print(std::cout);
    std::cout << std::endl;

    return 0;
}
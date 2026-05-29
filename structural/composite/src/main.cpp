#include "Portofolio.hpp"
#include "Investment.hpp"
#include "Loan.hpp"
#include "Asset.hpp"

int main(int argc, char* argv[])
{
    std::unique_ptr<Asset> portofolio1 = std::make_unique<Portofolio>("John's Portofolio", 1);
    std::unique_ptr<Asset> portofolio2 = std::make_unique<Portofolio>("Mary's Portofolio", 2);

    std::unique_ptr<Asset> loan1 = std::make_unique<Loan>("Loan 1", -100);
    std::unique_ptr<Asset> loan2 = std::make_unique<Loan>("Loan 2", -200);
    std::unique_ptr<Asset> loan3 = std::make_unique<Loan>("Loan 3", -300);

    std::unique_ptr<Asset> investment1 = std::make_unique<Investment>("Investment 1", 1000);
    std::unique_ptr<Asset> investment2 = std::make_unique<Investment>("Investment 2", 5000);

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
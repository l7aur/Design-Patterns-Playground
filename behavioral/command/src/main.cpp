#include "File.hpp"

#include "Command.hpp"
#include "SaveCommand.hpp"
#include "OpenCommand.hpp"
#include "CopyCommand.hpp"
#include "CloseCommand.hpp"
#include "PasteCommand.hpp"
#include "DisplayCommand.hpp"
#include "NavigateCommand.hpp"

#include <iostream>
#include <filesystem>

int main(int argc, char* argv[])
{
    File f;

    char key{ 0 };
    while (true)
    {
        std::cout << "n - navigate; c - copy; p - paste; o - open; x - close; s - save; d - display; q - quit\n";
        std::cin >> key;
        switch (key)
        {
        case 'n': {
            int x; std::cin >> x;
            std::unique_ptr<Command> cmd = std::make_unique<NavigateCommand>(&f, x);
            cmd->execute();
            break;
        }
        case 'c': {
            int x; std::cin >> x;
            std::unique_ptr<Command> cmd = std::make_unique<CopyCommand>(&f, x);
            cmd->execute();
            break;
        }
        case 'p': {
            std::unique_ptr<Command> cmd = std::make_unique<PasteCommand>(&f);
            cmd->execute();
            break;
        }
        case 'o': {
            std::filesystem::path p; std::cin >> p;
            std::unique_ptr<Command> cmd = std::make_unique<OpenCommand>(&f, p);
            try { cmd->execute(); }
            catch(const std::exception& e) {
                std::cout << e.what() << "\n";
            }
            break;
        }
        case 's': {
            std::unique_ptr<Command> cmd = std::make_unique<SaveCommand>(&f);
            cmd->execute();
            break;
        }
        case 'd': {
            std::unique_ptr<Command> cmd = std::make_unique<DisplayCommand>(&f);
            cmd->execute();
            break;
        }
        case 'x': {
            
            std::unique_ptr<Command> cmd = std::make_unique<CloseCommand>(&f);
            cmd->execute();
            break;
        }
        case 'q':
            return 0;
        default:
            break;
        }
    }

    return 0;
}
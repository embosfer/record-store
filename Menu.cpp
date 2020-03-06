#include <iostream>
#include "Menu.h"

static int GO_BACK = 9; // TODO: not very clean but will do for now...

Menu::Menu(string desc): description(desc) 
{
    addOption(GO_BACK, "Back", [](){});
}

void Menu::addOption(int option, string description, Menu& submenu)
{
    submenu.setParent(this);
    addOption(option, description, [&submenu]() { submenu.start(); });
}

void Menu::addOption(int option, string description, const std::function<void()>& callback)
{
    options.insert({option, Option(description, callback)});
}

void Menu::setParent(Menu* parentMenu)
{
    this->parentMenu = parentMenu;
}

void Menu::printOptions()
{
    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "\t\t\t\t" << description << std::endl;
    std::cout << "\t\t\t\t============" << std::endl;

    for(auto & [key, op] : options) {
        std::cout << "\t\t" << key << ". " << op.description << std::endl;
    }
}

int Menu::getUserInput()
{
    std::cout << "Enter an option: ";
    int op;
    std::cin >> op;
    std::cout << std::endl;
    return op;
}

void Menu::start()
{
    while(true) {
        printOptions();

        int op = getUserInput();
        if (op == GO_BACK) {
            break;
        }

        auto o = options.find(op);
        if (o == options.end()) {
            std::cout << "Option " << op << " does not exist. Try again.\n" << std::endl;
        } else {
            o->second.call();
        }
    }
}
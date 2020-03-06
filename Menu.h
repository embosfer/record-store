#pragma once
#include <functional>
#include <string>
#include <map>

using std::string;

class Option { // TODO: expose this as part of public API?
public:
    Option(string _description, const std::function<void(void)>& callback)
    {
        description = _description;
        call = callback;
    }
    string description;
    std::function<void(void)> call;
};

class Menu {

public:
    Menu(string desc);
    void addOption(int option, string description, const std::function<void()>& callback);
    void addOption(int option, string description, Menu& submenu);
    void start();

private:
    string description;
    std::map<int, Option> options;
    Menu* parentMenu;
    void setParent(Menu* parentMenu);
    void printOptions();
    int getUserInput();

};
#pragma once
#include <string>

using std::string;

class Record {

public:
    Record(string& name): _name(name) {}
    string name(); 

private:
    string _name;
};
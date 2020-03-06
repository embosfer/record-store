#pragma once
#include <vector>
#include "Record.h"

class Store {

public:
    std::vector<Record> getRecords() const;
    void addRecord(string record_name);
    void removeRecord(string record_name);

private:
    std::vector<Record> records;

};
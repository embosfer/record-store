#include <algorithm>
#include <iostream>
#include <vector>
#include "Record.h"
#include "Store.h"

std::vector<Record> Store::getRecords() const
{
    return records;
}

void Store::addRecord(string record_name)
{
    records.push_back(Record(record_name));
}

void Store::removeRecord(string record_name)
{
    auto remove_start = std::remove_if(records.begin(), records.end(), 
                    [&record_name](Record r) { return r.name() == record_name; });
    records.erase(remove_start, records.end());
}
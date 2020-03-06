#include <iostream>
#include <vector>

#include "Menu.h"
#include "Record.h"
#include "Store.h"

string getRecordNameFromUser()
{
    std::cout << "Type album name: ";
    std::string record_name;
    std::cin.ignore(); // ignore previous pending trailing \n in the stream
    std::getline(std::cin, record_name); 

    return record_name;
}

void showAvailableRecordsIn(const Store& store)
{
    std::vector<Record> records = store.getRecords();
    if (records.empty()) {
        std::cout << ">>> No records available.\n" << std::endl;
    } else {
        for (Record r : records) {
            std::cout << ">>> " << r.name() << std::endl;
        }
    }
}

int main()
{
    Store store;

    Menu main_menu("RECORD STORE");
    Menu record_editor_menu("Record editor");

    main_menu.addOption(1, "List records", [&store]() { showAvailableRecordsIn(store);});
    main_menu.addOption(2, "Add/Remove a record", record_editor_menu);

    record_editor_menu.addOption(1, "Add a record", [&store]() {
        string record_name = getRecordNameFromUser();
        store.addRecord(record_name);
        std::cout << "\n>>> Record '" << record_name << "' added.\n\n";
    });
    record_editor_menu.addOption(2, "Remove a record", [&store]() {
        string record_name = getRecordNameFromUser();
        store.removeRecord(record_name);
        std::cout << "\n>>> Record '" << record_name << "' removed.\n\n";
    });

    main_menu.start();
}


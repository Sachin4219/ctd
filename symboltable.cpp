#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> symbolTable;

void display() {
    cout << "Symbol Table:" << endl;
    for (auto const &entry : symbolTable) {
        cout << entry.first << " is present at " << entry.second << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\nSYMBOL TABLE IMPLEMENTATION\n";
        cout << "1. INSERT\t";
        cout << "2. DISPLAY\n";
        cout << "3. DELETE\t";
        cout << "4. SEARCH\n";
        cout << "5. MODIFY\t";
        cout << "6. END\n";
        cout << "Enter your option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string label, address;
                cout << "Enter the label and address: ";
                cin >> label >> address;

                if (symbolTable.find(label) != symbolTable.end()) {
                    cout << "Label already present!" << endl;
                } else {
                    symbolTable[label] = address;
                    cout << "Label added successfully!" << endl;
                }
                break;
            }
            case 2: {
                display();
                break;
            }
            case 3: {
                string label;
                cout << "Enter the label to delete: ";
                cin >> label;

                if (symbolTable.find(label) == symbolTable.end()) {
                    cout << "Label not present in symbol table!" << endl;
                } else {
                    symbolTable.erase(label);
                    cout << "Label deleted successfully!" << endl;
                }
                break;
            }
            case 4: {
                string label;
                cout << "Enter the label to search: ";
                cin >> label;

                if (symbolTable.find(label) != symbolTable.end()) {
                    cout << "The label is already in the symbol Table at address: " << symbolTable[label] << endl;
                } else {
                    cout << "The label is not found in the symbol table" << endl;
                }
                break;
            }
            case 5: {
                string label, newAddress;
                cout << "Enter the label: ";
                cin >> label;
                cout << "Enter the new address of the label: ";
                cin >> newAddress;

                if (symbolTable.find(label) == symbolTable.end()) {
                    cout << "Label not present" << endl;
                } else {
                    symbolTable[label] = newAddress;
                    cout << "Address updated successfully!" << endl;
                }
                break;
            }
            default: {
                break;
            }
        }
    } while (choice < 6);

    return 0;
}

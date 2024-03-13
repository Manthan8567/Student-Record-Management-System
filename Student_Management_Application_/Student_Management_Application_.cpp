#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int maxrow = 10;

struct Address {
    string street[maxrow] = {};
    string city[maxrow] = {};
    string postal_code[maxrow] = {};
    string state[maxrow] = {};
} a1;

struct Student {
    string StdName[maxrow] = {};
    string StdID[maxrow] = {};
    string StdLastName[maxrow] = {};
    string StdEmail[maxrow] = {};
    struct Address a1;
} s1;

// Function declarations
void AddRecord();
void ListRecord();
void SearchRecord(string search);
void UpdateRecord(string search);
void DeleteRecord(string search);

int main() {
    char choice, confirmation;
    bool exit_program = false;
    string StdID;

    do {
        cout << "\t\t\t----------------------------------";
        cout << "\n\t\t\tStudent Record Management System\n";
        cout << "\t\t\t----------------------------------\n";
        cout << "1. Add a student record.\n";
        cout << "2. Search for a student record.\n";
        cout << "3. Update a student record.\n";
        cout << "4. Delete a student record.\n";
        cout << "5. Display all student records.\n";
        cout << "6. Exit the program.\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            system("cls");
            AddRecord();
            break;
        case '2':
            system("cls");
            cin.ignore();
            cout << "Enter Student ID to search: ";
            getline(cin, StdID);
            SearchRecord(StdID);
            break;
        case '3':
            system("cls");
            cin.ignore();
            cout << "Enter Student ID to update: ";
            getline(cin, StdID);
            UpdateRecord(StdID);
            break;
        case '4':
            system("cls");
            cin.ignore();
            cout << "Enter Student ID to delete: ";
            getline(cin, StdID);
            DeleteRecord(StdID);
            break;
        case '5':
            ListRecord();
            break;
        case '6':
            cout << "Are you sure you want to exit? (y/n): ";
            cin >> confirmation;
            if (confirmation == 'y' || confirmation == 'Y') {
                exit_program = true;
            }
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    } while (!exit_program);

    return 0;
}

// Function definitions

void AddRecord() {
    char name[30];
    char stdnumber[5];
    char last_name[30];
    char email[30];
    char street[30];
    char city[20];
    char postalcode[7];
    char state[15];

    cin.ignore();

    cout << "Enter Student ID: ";
    cin.getline(stdnumber, 5);
    cout << "Enter Student name: ";
    cin.getline(name, 30);
    cout << "Enter Student last name: ";
    cin.getline(last_name, 30);
    cout << "Enter Student email: ";
    cin.getline(email, 30);
    cout << "Enter Student address (street): ";
    cin.getline(street, 30);
    cout << "Enter Student city: ";
    cin.getline(city, 20);
    cout << "Enter Student postal code: ";
    cin.getline(postalcode, 7);
    cout << "Enter Student state: ";
    cin.getline(state, 15);

    for (int i = 0; i < maxrow; i++) {
        if (s1.StdID[i] == "\0") {
            s1.StdID[i] = stdnumber;
            s1.StdName[i] = name;
            s1.StdLastName[i] = last_name;
            s1.StdEmail[i] = email;
            s1.a1.street[i] = street;
            s1.a1.city[i] = city;
            s1.a1.postal_code[i] = postalcode;
            s1.a1.state[i] = state;
            break;
        }
    }
    cout << "Student record added successfully.\n";
}

void ListRecord() {
    system("cls");
    cout << "\t\tCurrent Student Records\n";
    cout << "\t\t-----------------------\n";

    int counter = 0;

    cout << "----------------------------------------------\n";
    cout << "|  ID        |  Name                |  Email  |\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < maxrow; i++) {
        if (s1.StdID[i] != "\0") {
            counter++;
            cout << "|  " << s1.StdID[i] << "  |  " << s1.StdName[i] << " " << s1.StdLastName[i];
            // Adding spaces to align the columns
            cout << string(21 - s1.StdName[i].length() - s1.StdLastName[i].length(), ' ');
            cout << "  |  " << s1.StdEmail[i];
            // Adding spaces to align the column
            cout << string(23 - s1.StdEmail[i].length(), ' ') << "|\n";
        }
    }
    cout << "----------------------------------------------\n";

    if (counter == 0) {
        cout << "No records found!\n";
    }
    else {
        cout << "Student Address Details:\n";
        cout << "----------------------------------------------\n";
        cout << "|  Postal Code  |  City/State        |  Street  |\n";
        cout << "----------------------------------------------\n";

        for (int i = 0; i < maxrow; i++) {
            if (s1.StdID[i] != "\0") {
                cout << "|  " << s1.a1.postal_code[i] << "  |  " << s1.a1.city[i] << ", " << s1.a1.state[i] << "  |  " << s1.a1.street[i] << "\n";
            }
        }
        cout << "----------------------------------------------\n";
    }
}


void SearchRecord(string search) {
    system("cls");
    cout << "\t\tSearch Student Record\n";
    cout << "\t\t---------------------\n";

    int counter = 0;

    cout << "----------------------------------------------\n";
    cout << "|  ID        |  Name                |  Email  |\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < maxrow; i++) {
        if (s1.StdID[i] == search) {
            counter++;
            cout << "|  " << s1.StdID[i] << "  |  " << s1.StdName[i] << " " << s1.StdLastName[i];
            // Adding spaces to align the columns
            cout << string(21 - s1.StdName[i].length() - s1.StdLastName[i].length(), ' ');
            cout << "  |  " << s1.StdEmail[i];
            // Adding spaces to align the column
            cout << string(23 - s1.StdEmail[i].length(), ' ') << "|\n";
        }
    }
    cout << "----------------------------------------------\n";

    if (counter == 0) {
        cout << "No records found for Student ID: " << search << endl;
    }
    else {
        cout << "Student Address Details:\n";
        cout << "----------------------------------------------\n";
        cout << "|  Postal Code  |  City/State        |  Street  |\n";
        cout << "----------------------------------------------\n";

        for (int i = 0; i < maxrow; i++) {
            if (s1.StdID[i] == search) {
                cout << "|  " << s1.a1.postal_code[i] << "  |  " << s1.a1.city[i] << ", " << s1.a1.state[i] << "  |  " << s1.a1.street[i] << "\n";
            }
        }
        cout << "----------------------------------------------\n";
    }
}



void UpdateRecord(string search) {
    char name[30];
    char stdnumber[5];
    char last_name[30];
    char email[30];
    char street[30];
    char city[20];
    char postalcode[7];
    char state[15];

    int counter = 0;
    for (int i = 0; i < maxrow; i++) {
        if (s1.StdID[i] == search) {
            counter++;

            cout << "Enter new Student ID: ";
            cin.getline(stdnumber, 5);
            cout << "Enter new Student name: ";
            cin.getline(name, 30);
            cout << "Enter new Student last name: ";
            cin.getline(last_name, 30);
            cout << "Enter new Student email: ";
            cin.getline(email, 30);
            cout << "Enter new Student address (street): ";
            cin.getline(street, 30);
            cout << "Enter new Student city: ";
            cin.getline(city, 20);
            cout << "Enter new Student postal code: ";
            cin.getline(postalcode, 7);
            cout << "Enter new Student state: ";
            cin.getline(state, 15);

            s1.StdID[i] = stdnumber;
            s1.StdName[i] = name;
            s1.StdLastName[i] = last_name;
            s1.StdEmail[i] = email;
            s1.a1.street[i] = street;
            s1.a1.city[i] = city;
            s1.a1.postal_code[i] = postalcode;
            s1.a1.state[i] = state;

            cout << "Record updated successfully.\n";
            break;
        }
    }
    if (counter == 0) {
        cout << "No record found for ID: " << search << endl;
    }
}

void DeleteRecord(string search) {
    int counter = 0;
    for (int i = 0; i < maxrow; i++) {
        if (s1.StdID[i] == search) {
            counter++;

            s1.StdName[i] = "";
            s1.StdLastName[i] = "";
            s1.StdEmail[i] = "";
            s1.a1.street[i] = "";
            s1.a1.city[i] = "";
            s1.a1.postal_code[i] = "";
            s1.a1.state[i] = "";
            s1.StdID[i] = "";

            cout << "Record deleted successfully.\n";
            break;
        }
    }
    if (counter == 0) {
        cout << "No record found for ID: " << search << endl;
    }
}

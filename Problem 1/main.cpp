// => ** FCAI-CU - Data Structure – 2025 - Assignment ( 1 ) - Problem ( 1 ) ** <=
// => Last Modification Date: 02/04/2025
// => Under supervision of  : Dr.Basheer Abdel Fatah
// => TA                    : Eng.Abdalrahman Roshdi & Eng.Ashraf Mohy
// => File Name             : Problem1.cpp
// => Purpose               : Hosting Iftar gatherings for friends and family. Since invite different guests
//                            on different days, need a system to track invitations, including the guest’s name, contact
//                            details, and the date they’re invited.
// => Authors               : Malak Mohamed Saad Fahmy Al-Aabiad     => ID: ( 20230417 )  => SECTION: S3,4
// => Emails                : malakkalaabiadd@gmail.com
//----------------------------------------------------------------------------------------------------------------------

#include "bits/stdc++.h"

using namespace std;

// Guest class to store individual guest details
class Guest {
private:
    char* name;
    char* contact;
    char* iftar_date;
public:
    // Constructor to initialize guest details
    Guest(const char* n, const char* c, const char* d) {
        name = new char[strlen(n) + 1];
        contact = new char[strlen(c) + 1];
        iftar_date = new char[strlen(d) + 1];
        strcpy(name, n);
        strcpy(contact, c);
        strcpy(iftar_date, d);
    }

    // Destructor to free allocated memory
    ~Guest() {
        delete[] name;
        delete[] contact;
        delete[] iftar_date;
    }

    // Display guest information
    void display_guest() {
        cout << "\nGuest: " << name << ", Contact: " << get_contact() << ", Iftar Date: " << iftar_date << endl;
    }

    // Update invitation date
    void update_invitation(const char* new_date) {
        delete[] iftar_date;
        iftar_date = new char[strlen(new_date) + 1];
        strcpy(iftar_date, new_date);
    }

    // Getter functions to access private attributes
    const char* get_name() { return name; }
    const char* get_date() { return iftar_date; }
    const char* get_contact() { return contact; }
};

// IftarManager class to manage multiple guest invitations
class IftarManager {
private:
    Guest** guest_list;
    int count;
    int capacity;
public:
    // Constructor to initialize manager with default capacity
    IftarManager(int cap = 10) : count(0), capacity(cap) {
        guest_list = new Guest*[capacity];
    }

    // Destructor to free memory allocated for guest list
    ~IftarManager() {
        for (int i = 0; i < count; ++i) {
            delete guest_list[i];
        }
        delete[] guest_list;
    }

    // Add a guest to the list
    void add_guest(Guest* guest) {
        if (count == capacity) return;
        guest_list[count++] = guest;
    }

    // Load guests from a file
    void load_guests_from_file(const char* filename) {
        ifstream file(filename);
        if (!file) {
            cout << "\nError opening file!\n";
            return;
        }
        char name[50], contact[50], date[15];
        while (file >> name >> contact >> date) {
            add_guest(new Guest(name, contact, date));
        }
        file.close();
    }

    // Display all guests
    void display_all_guests() {
        for (int i = 0; i < count; ++i) {
            guest_list[i]->display_guest();
        }
    }

    // Update invitation date for a specific guest
    void update_guest_invitation(const char* name, const char* new_date) {
        for (int i = 0; i < count; ++i) {
            if (strcmp(guest_list[i]->get_name(), name) == 0) {
                guest_list[i]->update_invitation(new_date);
                return;
            }
        }
    }

    // Send reminders to guests with a specific iftar date
    void send_real_email(const string& recipient, const string& date) {
        cout << "Preparing to send email to: " << recipient << " for Iftar on " << date << endl;
        string python_path = R"(D:\DSA_Assignments\Assignment_1\venu\Scripts\python.exe)";

        string script_path = R"(D:\DSA_Assignments\Assignment_1\send_email.py)";
        string command = python_path + " " + script_path + " " + recipient + " " + date;
        int result = system(command.c_str());

        if (result != 0) {
            cout << "Error: Failed to execute Python script!" << endl;
        } else {
            cout << "Email sent successfully to " << recipient << "!\n";
        }
    }

    void send_reminders(const char* date) {
        cout << "Sending real email reminders...\n";
        for (int i = 0; i < count; ++i) {
            if (strcmp(guest_list[i]->get_date(), date) == 0) {
                cout << "Sending email to: " << guest_list[i]->get_contact() << endl;
                send_real_email(guest_list[i]->get_contact(), date);
            }
        }
        cout << "Emails sent successfully!\n";
    }
};

int main() {
    IftarManager manager;
    manager.load_guests_from_file("guests.txt");

    int choice;
    char name[50], contact[50], date[15];
    do {
        cout << "\nIftar Invitation Manager";
        cout << "\n1. Display All Guests";
        cout << "\n2. Add Guest";
        cout << "\n3. Update Invitation Date";
        cout << "\n4. Send Reminders";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.display_all_guests();
                break;
            case 2:
                cout << "\nEnter name, contact, and iftar date: ";
                cin >> name >> contact >> date;
                manager.add_guest(new Guest(name, contact, date));
                break;
            case 3:
                cout << "\nEnter guest name and new date: ";
                cin >> name >> date;
                manager.update_guest_invitation(name, date);
                break;
            case 4:
                cout << "\nEnter date to send reminders: ";
                cin >> date;
                manager.send_reminders(date);
                break;
            case 5:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "\nInvalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
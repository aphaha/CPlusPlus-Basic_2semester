#include <iostream>
#include <string>

using namespace std;

const int MAX_MEMBERS = 10;

class GymMember {
public:
    GymMember(int id, const string& name);
    void extendMembership(int months);
    void cancelMembership();
    void printStatus() const;
    int getId() const;

private:
    int id;
    string name;
    int membershipMonths;
};

GymMember::GymMember(int id, const string& name)
    : id(id), name(name), membershipMonths(0) {}

void GymMember::extendMembership(int months) {
    if (months > 0) {
        membershipMonths += months;
    } else {
        cout << "Invalid number of months. Membership extension failed." << endl;
    }
}

void GymMember::cancelMembership() {
    membershipMonths = 0;
}

void GymMember::printStatus() const {
    cout << "Member ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Membership Months: " << membershipMonths << endl;
}

int GymMember::getId() const {
    return id;
}

int main() {
    GymMember* members[MAX_MEMBERS] = { nullptr };
    int numMembers = 0;

    string command;
    while (command != "quit") {
        cout << "Enter a command (create [id] [name], delete [id], extend [id] [n], cancel [id], quit): ";
        cin >> command;

        if (command == "create") {
            int id;
            string name;
            cin >> id >> name;

            bool exists = false;
            for (int i = 0; i < numMembers; ++i) {
                if (members[i] && members[i]->getId() == id) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                cout << "Member with ID " << id << " already exists." << endl;
            } else {
                if (numMembers >= MAX_MEMBERS) {
                    cout << "Maximum number of members reached. Cannot create new member." << endl;
                } else {
                    members[numMembers] = new GymMember(id, name);
                    cout << "Member with ID " << id << " created." << endl;
                    numMembers++;
                }
            }
        } else if (command == "delete") {
            int id;
            cin >> id;

            bool found = false;
            for (int i = 0; i < numMembers; ++i) {
                if (members[i] && members[i]->getId() == id) {
                    delete members[i];
                    members[i] = nullptr;
                    found = true;
                    cout << "Member with ID " << id << " deleted." << endl;
                    break;
                }
            }

            if (!found) {
                cout << "Member with ID " << id << " not found." << endl;
            }
        } else if (command == "extend") {
            int id, months;
            cin >> id >> months;

            bool found = false;
            for (int i = 0; i < numMembers; ++i) {
                if (members[i] && members[i]->getId() == id) {
                    members[i]->extendMembership(months);
                    members[i]->printStatus();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Member with ID " << id << " not found." << endl;
            }
        } else if (command == "cancel") {
            int id;
            cin >> id;

            bool found = false;
            for (int i = 0; i < numMembers; ++i) {
                if (members[i] && members[i]->getId() == id) {
                    members[i]->cancelMembership();
                    members[i]->printStatus();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Member with ID " << id << " not found." << endl;
            }
        }
    }


    return 0;
}

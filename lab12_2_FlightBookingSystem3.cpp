#include <iostream>
#include <string>

using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    void set(int id, int capacity, int reserved);
    bool addReservations(int n);
    bool cancelReservations(int n);
    int getId() const;

private:
    int id;
    int capacity;
    int reserved;
};

void FlightBooking::printStatus() {
    cout << "Flight " << this->id << ": " << this->reserved << "/" << this->capacity << " (" << double(this->reserved) / this->capacity * 100 << "%) seats reserved" << endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    set(id, capacity, reserved);
}

void FlightBooking::set(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;
    this->reserved = reserved > 0 ? reserved : 0;
    if (this->reserved > this->capacity)
        this->reserved = this->capacity;
}

bool FlightBooking::addReservations(int n) {
    int newReserved = this->reserved + n;
    if (newReserved <= this->capacity * 1.05) {
        this->reserved = newReserved;
        return true;
    }
    return false;
}

bool FlightBooking::cancelReservations(int n) {
    int newReserved = this->reserved - n;
    if (newReserved >= 0) {
        this->reserved = newReserved;
        return true;
    }
    return false;
}

int FlightBooking::getId() const {
    return id;
}

int main() {
    FlightBooking* flights[10];
    int numFlights = 0;

    string command;
    while (command != "quit") {
        cout << "Enter a command (create [id] [cap], delete [id], add [id] [n], cancel [id] [n], quit): ";
        cin >> command;

        if (command == "create") {
            int id, capacity;
            cin >> id >> capacity;
            bool exists = false;
            for (int i = 0; i < numFlights; ++i) {
                if (flights[i]->getId() == id) {
                    exists = true;
                    break;
                }
            }
            if (exists) {
                cout << "Flight with ID " << id << " already exists." << endl;
            } else {
                flights[numFlights] = new FlightBooking(id, capacity, 0);
                cout << "Flight with ID " << id << " created." << endl;
                numFlights++;
            }
        } else if (command == "delete") {
            int id;
            cin >> id;
            bool found = false;
            for (int i = 0; i < numFlights; ++i) {
                if (flights[i]->getId() == id) {
                    delete flights[i];
                    for (int j = i; j < numFlights - 1; ++j) {
                        flights[j] = flights[j + 1];
                    }
                    numFlights--;
                    found = true;
                    break;
                }
            }
            if (found) {
                cout << "Flight with ID " << id << " deleted." << endl;
            } else {
                cout << "Flight with ID " << id << " not found." << endl;
            }
        } else if (command == "add") {
            int id, n;
            cin >> id >> n;
            bool found = false;
            for (int i = 0; i < numFlights; ++i) {
                if (flights[i]->getId() == id) {
                    if (flights[i]->addReservations(n)) {
                        flights[i]->printStatus();
                    } else {
                        cout << "Cannot add " << n << " reservations to Flight " << id << ". Exceeds capacity." << endl;
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Flight with ID " << id << " not found." << endl;
            }
        } else if (command == "cancel") {
            int id, n;
            cin >> id >> n;
            bool found = false;
            for (int i = 0; i < numFlights; ++i) {
                if (flights[i]->getId() == id) {
                    if (flights[i]->cancelReservations(n)) {
                        flights[i]->printStatus();
                    } else {
                        cout << "Cannot cancel " << n << " reservations from Flight " << id << ". Not enough reservations." << endl;
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Flight with ID " << id << " not found." << endl;
            }
        }
    }

    for (int i = 0; i < numFlights; ++i) {
        delete flights[i];
    }

    return 0;
}

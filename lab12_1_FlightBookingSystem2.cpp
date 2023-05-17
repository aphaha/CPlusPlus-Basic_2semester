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

int main() {
    int reserved = 0,
        capacity = 0;

    cout << "Provide flight capacity: ";
    cin >> capacity;

    cout << "Provide number of reserved seats: ";
    cin >> reserved;

    FlightBooking booking(1, capacity, reserved);

    booking.printStatus();

    string command;
    while (command != "quit") {
        cout << "Enter a command (add [n], cancel [n], quit): ";
        cin >> command;

        if (command == "add") {
            int n;
            cin >> n;
            if (booking.addReservations(n))
                booking.printStatus();
            else
                cout << "Cannot perform this operation" << endl;
        } else if (command == "cancel") {
            int n;
            cin >> n;
            if (booking.cancelReservations(n))
                booking.printStatus();
            else
                cout << "Cannot perform this operation" << endl;
        }
    }

    return 0;
}

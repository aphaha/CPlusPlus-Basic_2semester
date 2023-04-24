#include <iostream>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    void set(int id, int capacity, int reserved);

private:
    int id;
    int capacity;
    int reserved;
};

void FlightBooking::printStatus(){
    cout << "Flight" << this -> id << ":" << this -> reserved << "/" << this -> capacity << "(" << double(this -> reserved)/this -> capacity * 100 << "%) seats reserved";
    }
 
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    set(id, capacity, reserved);
}

void FlightBooking::set(int id, int capacity, int reserved){
    this -> id = id;
    this -> capacity = capacity;
    this -> reserved = reserved;

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
    
    return 0;
}
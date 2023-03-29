#include <iostream>
#include <string>

using namespace std;


int main(){
    
    string customer;
    string date;
    string room;
    
    cout << "customer = ";
    getline(cin, customer);
    
    cout << "date = ";
    getline(cin, date);
    
    cout << "room = ";
    getline(cin, room);

    
    cout << "Dear " + customer + ", your exam will take place on " + date + " in room " + room;
    
// date=02/02/02 3:00PM,room=504
// Dear [customer], your exam will take place on [date] in room [room]

}

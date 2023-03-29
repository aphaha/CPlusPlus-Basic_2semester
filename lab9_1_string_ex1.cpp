#include <iostream>
#include <string>

using namespace std;


int main(){
    
    string person;
    string action;
    string place;
    
    cout << "person = ";
    getline(cin, person);
    //person=Paul
    
    cout << "action = ";
    getline(cin, action);
    //action=strolls around
    
    cout << "place = ";
    getline(cin, place);
    //place=the park
    
    cout << endl;
    
    cout << person + " " + action + " " + place + ".";
    
}

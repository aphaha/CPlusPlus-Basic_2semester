#include <iostream>
#include <string>

using namespace std;


int main(){
    
    string customer;
    string pet;
    
    cout << "customer = ";
    getline(cin, customer);
    
    cout << "pet = ";
    getline(cin, pet);

    
    cout << "Dear " + customer + ", we were happy to take care of your " + pet + " while you were away. Please call our pet hotel again if you need help with your " + pet + "!";
    
// customer=John,pet=dog
// Dear [customer], we were happy to take care of your [pet] while you were away. Please call our pet hotel again if you need help with your [pet]!

}

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    int age; 
    
    string city;                       // My code
    string country;                    //
};
    
void print(Person* person)
{
cout << person->name << " is " << person->age << " years old." << endl;
}

int main()
{
        
    Person person;
    person.name = "Harry";
    person.age = 23;
        
    cout << "Meet " << person.name << ". " << endl;
        
    print(&person);
        
    Person place;                                                                              // My code
    place.city = "London";                                                                     //
    place.country = "Great Britain";                                                           //    
    
    cout << person.name << " was born in " << place.city << ", " << place.country << ".";      //
    
    return 0;
        
}

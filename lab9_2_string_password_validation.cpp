#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string password;

    cout << "password = ";
    getline(cin, password);

    if (password.length() != 8) cout << "The password must be 8 characters long" << endl;
    
    if (password.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos ) cout << "The password must have at least one upper case letter" << endl;
    // != std::string::npos  використовується для перевірки того, чи була знайдена підстрічка в рядку.
    
    if (password.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos ) cout << "The password must have at least one lower-case letter" << endl;
    
    if (password.find_first_not_of("1234567890") != std::string::npos ) cout << "The password must have at least one digit" << endl;
    
    if (password.find_first_not_of("~!@#$%^&*()_+-={}|[]:;'<>,.?/") != std::string::npos ) cout << "The password must have at least one specialcharacter"<< endl;
    
    else cout << "The password is valid" << endl;

    return 0;
}


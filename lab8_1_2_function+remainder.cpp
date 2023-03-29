#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int);

int main(void) {
    
    for(int i = 0; i <= 21; i++)
        if(isPrime(i))
            cout << i << " ";
    cout << endl;
    
    return 0;
}

bool isPrime(int x) {
    bool result = true;
    for (int i = 2; i < x; i++){
        if (x % i == 0) result = false;
    }
    return result;
    
}
//Перевіряє, чи є введене число простим, чи ні.
//– якщо вона дорівнює 0, ваше число не може бути простим.

// Приклад виведення:
// 2 3 5 7 11 13 17 19


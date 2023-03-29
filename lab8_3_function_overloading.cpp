#include <iostream>
using namespace std;

// Прототипи функцій
int increment(int);
int increment(int, int);

int main(void) {
    int var = 0;
    for(int i = 0; i < 10; i++)
        if(i % 2)
            var = increment(var); // Виклик функції increment з одним аргументом
        else
            var = increment(var, i); // Виклик функції increment з двома аргументами
    cout << var << endl;
    return 0;
}

// Функції
int increment(int x){
    return ++x; // Збільште значення x перед поверненням
}

int increment(int x, int y){
    return x + y; // Повертає суму x і y
}


// Приклад виведення:
// 25

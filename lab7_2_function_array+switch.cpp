#include <iostream>

using namespace std;


bool isLeap(int year) {
    bool result = false;
    if ( year % 4 == 0 ) result = true;
    return result;
}

int monthLength(int year, int month) {

    int countOfDays[12];
    
    if(isLeap(year)){
        countOfDays[0] = 31;
        countOfDays[1] = 29;
        countOfDays[2] = 31;
        countOfDays[3] = 30;
        countOfDays[4] = 31;
        countOfDays[5] = 30;
        countOfDays[6] = 31;
        countOfDays[7] = 31;
        countOfDays[8] = 30;
        countOfDays[9] = 31;
        countOfDays[10] = 30;
        countOfDays[11] = 31;
    }
    else{
        countOfDays[0] = 31;
        countOfDays[1] = 28;
        countOfDays[2] = 31;
        countOfDays[3] = 30;
        countOfDays[4] = 31;
        countOfDays[5] = 30;
        countOfDays[6] = 31;
        countOfDays[7] = 31;
        countOfDays[8] = 30;
        countOfDays[9] = 31;
        countOfDays[10] = 30;
        countOfDays[11] = 31;
    }
    
    return countOfDays[month - 1];
    
}

// int monthLength(int year, int month) {
//     int countOfDays;
//     switch (month) {
//         case 1: countOfDays = 31; break;
//         case 2: if(isLeap(year)) countOfDays = 29; else countOfDays = 28; break;
//         case 3: countOfDays = 31; break;
//         case 4: countOfDays = 30; break;
//         case 5: countOfDays = 31; break;
//         case 6: countOfDays = 30; break;
//         case 7: countOfDays = 31; break;
//         case 8: countOfDays = 31; break;
//         case 9: countOfDays = 30; break;
//         case 10: countOfDays = 31; break;
//         case 11: countOfDays = 30; break;
//         case 12: countOfDays = 31; break;
//     }
//     return countOfDays;
// }

int main(void) {
    
    for(int year = 2000; year < 2002; year++) {
        for(int month = 1; month <= 12; month++){
            cout << monthLength(year,month) << " ";
        }
        cout << endl;
    }
    
    return 0;
}

// Приклад виведення:
// 31 29 31 30 31 30 31 31 30 31 30 31
// 31 28 31 30 31 30 31 31 30 31 30 31

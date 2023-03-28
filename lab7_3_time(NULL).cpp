#include <iostream>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};


Date today(void);
bool isLeap(int year);
int monthLength(int year, int month);
int datelenght(Date);


int main(void) {
    Date t = today();
    Date bd;
    
    cout << "Current date: ";
    cout << t.year << "-" << t.month << "-" << t.day << endl;
    cout << "Enter your BD date" << endl;
    
    cout << "year: ";
    cin >> bd.year;
    
    cout << "month: ";
    cin >> bd.month;
    
    cout << "day: ";
    cin >> bd.day;
    
    cout << datelenght(t) - datelenght(bd);
    
    return 0;
}


bool isLeap(int year) {
    bool result = false;
    if ( year % 4 == 0 ) result = true;
    return result;
}


int monthLength(int year, int month) {
    // int countOfDays;
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
    
    // switch (month) {
    //     case 1: countOfDays = 31; break;
    //     case 2: if(isLeap(year)) countOfDays = 29; else countOfDays = 28; break;
    //     case 3: countOfDays = 31; break;
    //     case 4: countOfDays = 30; break;
    //     case 5: countOfDays = 31; break;
    //     case 6: countOfDays = 30; break;
    //     case 7: countOfDays = 31; break;
    //     case 8: countOfDays = 31; break;
    //     case 9: countOfDays = 30; break;
    //     case 10: countOfDays = 31; break;
    //     case 11: countOfDays = 30; break;
    //     case 12: countOfDays = 31; break;
    // }
    return countOfDays[month - 1];
    
}


Date today(void) {
    Date todayDate;
    time_t t = time(NULL); 
    //Отримати поточний час за допомогою функції time(NULL), яка повертає кількість секунд, що минули з 1 січня 1970 року до поточного моменту.
    tm tl = *localtime(&t);
    //Містить локальний час.
    todayDate.year = tl.tm_year + 1900;
    todayDate.month = tl.tm_mon + 1;
    todayDate.day = tl.tm_mday;
    return todayDate;
}


int datelenght(Date date) {
    int sum = 0;
    
    for(int i = 1; i < date.year; i++){
        if (isLeap(i)) sum +=366;
        else sum += 365;
    }
    
    for(int i = 1; i < date.month; i++){
        sum += monthLength(date.year, i);
    }
    
    sum += date.day;
    
    return sum;
}



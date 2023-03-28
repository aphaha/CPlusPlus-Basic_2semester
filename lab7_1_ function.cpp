#include <iostream>

using namespace std;

bool isLeap(int year) {
    bool result = false;
    if (year % 4 == 0) result = true;
    return result;
}

int main(void) {
    
 for(int year = 1995; year < 2017; year++)
  cout << year << " -> " << isLeap(year) << endl;
  
 return 0;
} 


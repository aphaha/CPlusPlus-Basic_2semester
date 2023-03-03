#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    
    int **mas = new int* [3];
    for (int count = 0;  count < 3; count++){
        mas[count] = new int [3];
    }
    
    for (int i = 0;  i < 3; i++){
        for (int j = 0;  j < 3; j++){
            mas[i][j] = (rand() % 10 + 1) / int((rand() % 10 + 1));
        }
    }
    
    for (int i = 0;  i < 3; i++){
        for (int j = 0;  j < 3; j++){
            cout << '\t' << mas[i][j] << '\t';
        }
        cout << endl;
    }
    
    cout << endl;
    cout << "   The main diagonal: ";
    
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (i == j) cout << *(*(mas + i) + j) << " ";
        }
    } 
    
    cout << endl;
    cout << "   The side diagonal: "; 
    
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if (i + j == 2) cout << *(*(mas + i) + j) << " ";
        }
    }
    
    int n = 0;
    
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (*(*(mas + i) + j) % 2 == 0){ 
            n++;
            }
        }
    }
    
    cout << endl;
    cout << "   Total of even numbers: " << n; 
    
    int o = 0;
    
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (*(*(mas + i) + j) % 2 != 0){ 
                o++;
            }
        }
    }
    
    cout << endl;
    cout << "   Total of odd numbers: " << o; 
    
    for (int count = 0;  count < 3; count++){
        delete [] mas[count];
    }

    return 0;
}

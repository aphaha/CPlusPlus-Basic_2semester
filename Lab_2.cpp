#include <iostream>

using namespace std;

int main(void) {
    int matrix[10][10] = { };
    
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            *(*(matrix + i) + j) = rand() % 10;
            
        }
    }
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout.width(4);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    
    cout << endl;
    cout << "   The main diagonal: ";
    
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if (i == j) cout << *(*(matrix + i) + j) << " ";
            
        }
    } 
     
    cout << endl;
    cout << "   The side diagonal: "; 
    
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if (i + j == 9) cout << *(*(matrix + i) + j) << " ";
            
        }
    }
    
    int n = 0;
    
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if (*(*(matrix + i) + j) % 2 == 0){ //&& *(*(matrix + i) + j) != 0
                n++;
            }
        }
    }
    
    cout << endl;
    cout << "   Total of even numbers: " << n; 
    
    int o = 0;
    
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if (*(*(matrix + i) + j) % 2 != 0){ 
                o++;
            }
        }
    }
    
    cout << endl;
    cout << "   Total of odd numbers: " << o; 
    
    return 0;
}
 
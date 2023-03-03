#include <iostream>
#include <string>

using namespace std;

int main()
{
    int p = 0;
    int n = 0;
    
    float *mas = new float [50];
    
    cout << "Array: ";
    
    for (int i = 0;  i < 50; i++){
        mas[i] = rand() % 5 - 2;
        cout << mas[i] << ' ';
    }
    
    for (int i = 0;  i < 50; i++){
        if (mas[i] > 0) p++;
        else n++;
    }
    
    cout << endl;
    cout << "Quantity of positive = " << p;
    cout << endl;
    cout << "Quantity of negative = " << n;
    
    delete [] mas;

    return 0;
}

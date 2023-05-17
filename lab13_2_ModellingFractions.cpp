#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    string toString() {
        ostringstream oss;
        int wholePart = numerator / denominator;
        int remainder = numerator % denominator;

        if (remainder < 0) {
            remainder = -remainder;
        }

        if (wholePart != 0) {
            oss << wholePart << " ";
        }

        oss << remainder << "/" << denominator;
        return oss.str();
    }

    double toDouble() {
        return static_cast<double>(numerator) / denominator;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    int num, den;
    string input;
    getline(cin, input);

    istringstream iss(input); //считує
    iss >> num;
    iss.ignore(2); //щоб пропустити символи " / "
    iss >> den;

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class IPAddress {
public:
    IPAddress(const string& address) : ipAddress(address) {}

    IPAddress(const IPAddress& other) : ipAddress(other.ipAddress) {}

    virtual void print() const { // метод виводить значення IP-адреси на екран
        cout << ipAddress << endl;
    }

protected:
    string ipAddress;
};

class IPAddressChecked : public IPAddress {
public:
    IPAddressChecked(const string& address, bool isCorrect)
        : IPAddress(address), isCorrect(isCorrect) {}

    IPAddressChecked(const IPAddressChecked& other)
        : IPAddress(other), isCorrect(other.isCorrect) {}

    void print() const override {
        IPAddress::print();
        cout << (isCorrect ? " - Correct" : " - Not Correct") << endl;
    }

private:
    bool isCorrect;
};

int main() {
    string ip1, ip2, ip3;

    cout << "Введіть першу IP-адресу: ";
    getline(cin, ip1);

    cout << "Введіть другу IP-адресу: ";
    getline(cin, ip2);

    cout << "Введіть третю IP-адресу: ";
    getline(cin, ip3);

    IPAddress ip(ip1);
    IPAddressChecked ipChecked1(ip2, false);
    IPAddressChecked ipChecked2(ip3, true);

    ip.print();
    ipChecked1.print();
    ipChecked2.print();

    return 0;
}


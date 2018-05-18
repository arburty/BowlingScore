#include <iostream>
using namespace std;

int main()
{
    int total = 5;
    cout << "total = " << total << "\n";
    int three = 3;
    total += three;
    cout << "total should be 8: " << total << "\n";
    int two = 2;
    total += two * three;
    cout << "total should be 14: " << total << "\n";
    int zero = 0;
    total += two * zero;
    cout << "total should be 14: " << total << "\n";
}


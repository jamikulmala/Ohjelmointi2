#include <iostream>

using namespace std;

int main()
{
    int temp;
    cout << "Enter a temperature: ";

    cin >> temp;

    cout << temp << " degrees Celsius is " << 1.8 * temp + 32 << " degrees Fahrenheit \n";
    cout << temp << " degrees Fahrenheit is " << (temp-32)/1.8 << " degrees Celsius";
    return 0;
}

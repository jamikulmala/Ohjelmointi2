#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Enter a positive number: ";
    int number;
    cin >> number;
    if (number > 0){
    int testnum = sqrt(number);
    while (number % testnum != 0){
        testnum -= 1;
    }
    cout << number << " = " << testnum << " * " << number/testnum;
    }
    else{
        cout << "Only positive numbers accepted";
    }

    return 0;
}

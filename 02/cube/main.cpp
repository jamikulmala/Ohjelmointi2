#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int luku;
    cout << "Enter a number: ";
    cin >> luku;
    int vastaus = luku * luku * luku;
    int toinen = cbrt(vastaus);
    if (luku == toinen){
        cout<< "The cube of " <<luku<< " is " << vastaus<< ".";
    }
    else{
        cout<< "Error! The cube of " <<luku<< " is not " <<vastaus<< ".";
    }
    return 0;
}

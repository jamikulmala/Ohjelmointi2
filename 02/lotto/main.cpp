#include <iostream>

using namespace std;

long unsigned int probability(int n){

    long unsigned int factorial = 1;
    long unsigned int vastaus = 1;
    for (int i = 1; i <= n; ++i){
        vastaus = factorial *= i;
    }
    return vastaus;
}

int main()
{
    int total;
    int pallot;
    cout << "Enter the total number of lottery balls: ";
    cin >> total;
    cout << "Enter the number of drawn balls: ";
    cin >> pallot;
    if (total > 0 and pallot > 0){
        if (total >= pallot){
            cout << "The probability of guessing all " <<pallot<< " balls correctly is "<<
            "1/"<< probability(total)/(probability(total-pallot)*probability(pallot));
        }
        else {
                cout << "The maximum number of drawn balls is the total amount of balls.";
            }
    }
    else {
            cout << "The number of balls must be a positive number.";
        }
    return 0;
}

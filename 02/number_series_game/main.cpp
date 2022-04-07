#include <iostream>


int main()
{
    std::cout << "How many numbers would you like to have? ";
    int howmany = 0;
    int i = 1;
    std::cin >> howmany ;
    while(i <= howmany){

        if (i % 3 == 0 && i % 7 == 0){
            std::cout << "zip boing\n";
        }

        else if (i % 3 == 0){
            std::cout << "zip\n";
        }
        else if (i % 7 == 0){
            std::cout << "boing\n";
        }
        else {
            std::cout << i <<"\n";
        }
        i++;
    }

    return 0;
}

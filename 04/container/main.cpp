#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>


void read_integers(std::vector< int >& ints, int count)
{
    int new_integer = 0;

    for(int i = 0; i < count; ++i)
    {
        std::cin >> new_integer;
        ints.push_back(new_integer);
    }
}

bool same_values(std::vector <int>& ints){
    if (std::equal(ints.begin() +1,ints.end(),ints.begin())){
        return true;
    }
    else{
        return false;
    }
}

bool is_ordered_non_strict_ascending(std::vector <int>& ints){
    int size = ints.size();
        int k;
        for (int i = 0; i < size-1; ++i) {
            k = i + 1;
            if (ints.at(i) > ints.at(k))
                return false;
        }
        return true;
    }

bool is_arithmetic_series(std::vector <int>& ints){

    int minus;
        int first = ints.at(0);
        int second = ints.at(1);
        minus = second - first;
        int size = ints.size();
        for (int i = 1; i < size-1; ++i) {
            if (ints.at(i+1) - ints.at(i) != minus)
                return false;
            }
        return true;
    }

bool is_geometric_series(std::vector <int>& ints){
    int x = 0;
    if (std::find(ints.begin(), ints.end(), x) != ints.end()){
        return false;
    }
    else{
    int d = ints[1] / ints[0];
    int size  = ints.size();

    for (int i = 2;i < size;i++){
        if(ints[i] / ints[i-1] == d){
            return true;
        }
        else{
            return false;
}
    }
    }

    return true;
}

int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers))
        std::cout << "All the integers are the same" << std::endl;
    else
        std::cout << "All the integers are not the same" << std::endl;

    if(is_ordered_non_strict_ascending(integers))
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    else
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;

    if(is_arithmetic_series(integers))
        std::cout << "The integers form an arithmetic series" << std::endl;
    else
        std::cout << "The integers do not form an arithmetic series" << std::endl;

    if(is_geometric_series(integers))
        std::cout << "The integers form a geometric series" << std::endl;
    else
        std::cout << "The integers do not form a geometric series" << std::endl;

    return EXIT_SUCCESS;
}

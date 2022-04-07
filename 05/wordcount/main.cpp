#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>

std::vector<std::string> split(std::string& str)
{
    std::string part = "";
    std::vector<std::string> result;
    int size = str.size();
    for (int i=0; i < size; ++i)  {
        if (str.at(i) == ' '){
            result.push_back(part);
            part.clear();
        }
        else {
            part += (str.at(i));
            if (i==size-1)
                result.push_back(part);
            }
    }
    return result;
}


int main()
{
    std::cout << "Input file: ";
    std::string input;
    std::cin >> input;
    std::ifstream tiedosto(input);

    if (not tiedosto){
        std::cout << "Error! The file " << input << " cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }
    std::map<std::string, std::vector<int>> data;
    std::vector<std::string> words;
    std::string row;
    int rivi = 0;
    while (getline(tiedosto, row)){
        ++rivi;
        words = split(row);
        for (std::string word : words){
            if (data.find(word) != data.end()){
                if (find(data.at(word).begin(), data.at(word).end(), rivi) == data.at(word).end()){
                    data.at(word).push_back(rivi);
                }
            }else{
                data.insert({word, {rivi}});
            }
        }
    }
    for (auto& pari : data){
        std::cout << pari.first << " " << pari.second.size() << ": ";
        std::cout << pari.second.at(0);
        pari.second.erase(pari.second.begin());
        for (int row_num : pari.second){
            std::cout << ", " << row_num;
        }
        std::cout << std::endl;
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>


int main()
{
    std::string input = "";
    std::cout << "Input file: ";
    std::cin >> input;
    std::map <std::string, int> pisteet;
    std::string substr;


    std::ifstream tiedosto(input);
    if (not tiedosto){
        std::cout << "Error! The file " << input << " cannot be opened.";
        return EXIT_FAILURE;
    }
    else{
        while (std::getline(tiedosto,substr)){
            int sep = substr.find(':');
            int len = substr.length();
            std::string pelaaja = substr.substr(0, sep);
            std::string points = substr.substr(sep+1, len-sep);
            int pst = stoi(points);
            if (pisteet.find(pelaaja) != pisteet.end()){
                pisteet.at(pelaaja) += pst;
            }
            else{
                pisteet.insert({pelaaja, pst});
            }

    }
    tiedosto.close();
    struct tietopari {
        int first;
        std::string second;
    };

    std::cout << "Final scores:"<< std::endl;
    for ( auto& tietopari : pisteet ) {
                      std::cout << tietopari.first << ": "
                 << tietopari.second << std::endl;

}
}
    return 0;
}

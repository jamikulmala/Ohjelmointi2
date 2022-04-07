#include <iostream>
#include <fstream>
#include <string>

int main()
{
std::string input = "";
std::string output = "";
std::cout << "Input file: ";
std::cin >> input;
std::cout << "Output file: ";
std::cin >> output;

std::ifstream tiedosto(input);
if (not tiedosto){
    std::cout << "Error! The file " << input << " cannot be opened.";
    return EXIT_FAILURE;
}
else{
    std::ofstream ttiedosto;
    ttiedosto.open(output);
    std::string rivi;
    int luku = 0;
    while(std::getline(tiedosto,rivi)){
    luku += 1;
    ttiedosto << luku << " " << rivi << std::endl;
}
    tiedosto.close();
    ttiedosto.close();
}
return 0;
}

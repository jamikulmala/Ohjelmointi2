#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector <std::string> split(std::string text,char separator,bool ignore = false){

    std::vector <std::string> result;
    std::stringstream data(text);
    std::string str;

    while (std::getline(data,str,separator)){
        result.push_back(str);
    }

    if(ignore == false){
        if (text.back() == separator){
            result.push_back("");
            return result;
        }
        return result;
    }
    if (ignore==true)    {
            std::string::size_type size = result.size();
            std::string::size_type& ref = size;
            for (std::string::size_type i=0; i < size -1; ++i)  {
                if (result.at(i)==""){
                    auto it = result.begin()+i;
                    result.erase(it);
                    ref -= 1;
                    i = 0;
                }
            }
            if (text.at(0) == separator){
                result.erase(result.begin());
                return result;
            }
            return result;
    }
    return result;
}

int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto& part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto& part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

const std::string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";


std::vector<std::string> split(const std::string& s,
                               const char delimiter,
                               bool ignore_empty = false)
{
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

void print(std::map <std::string, std::vector <std::string>> verkosto, std::string id,std::string pisteet){

    for(auto& nimi : verkosto.at(id)){
        std::cout << pisteet << nimi << std::endl;
        if(verkosto.at(nimi).size() > 0){
        pisteet += "..";
        print(verkosto,nimi,pisteet);
        pisteet = pisteet.substr(0,pisteet.length()-2);
        }
        else if(verkosto.at(id).size() <= 1){
            pisteet = "..";
        }
    }
}

void count(std::map <std::string, std::vector <std::string>> verkosto, std::string id,int& lasku){

    for (auto& nimi : verkosto.at(id)){
        lasku ++;

        if(verkosto.at(nimi).size() > 0){
            count(verkosto,nimi,lasku);

        }

    }
}

void depth(std::map <std::string, std::vector <std::string>> verkosto, std::string id,int& syvyys,int sub = 1){
    for (auto& nimi : verkosto.at(id)){
        ++ sub;

        if(verkosto.at(nimi).size() > 0){           
            depth(verkosto,nimi,syvyys,sub);
            -- sub;
        }
        else{
            if(sub > syvyys){
                syvyys = sub;
                sub = 1;
            }
            else{
                sub = 1;
            }

        }
    }
}

int main()
{
    std:: map < std::string , std::vector < std::string > > verkosto;


    while(true)
    {
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        // Allowing empty inputs
        if(parts.size() == 0)
        {
            continue;
        }

        std::string command = parts.at(0);

        if(command == "S" or command == "s")
        {
            if(parts.size() != 3)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            if (verkosto.find(id1) != verkosto.end()){
                verkosto.at(id1).push_back(id2);
                verkosto.insert({id2,{}});
            }
            else{
                verkosto.insert({id1,{id2}});
                verkosto.insert({id2,{}});
            }

        }
        else if(command == "P" or command == "p")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);
            std::string pisteet = "..";

            std::cout << id << std::endl;
            print(verkosto,id,"..");

        }
        else if(command == "C" or command == "c")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            int lasku = 0;
            std::string id = parts.at(1);
            count(verkosto,id,lasku);
            std::cout << lasku << std::endl;



        }
        else if(command == "D" or command == "d")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);
            int syvyys = 1;
            depth(verkosto,id,syvyys);
            std::cout << syvyys << std::endl;

        }
        else if(command == "Q" or command == "q")
        {
           return EXIT_SUCCESS;
        }
        else
        {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}

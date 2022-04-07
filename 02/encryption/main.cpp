#include <iostream>
#include <string>

using namespace std;

bool testall( string n){
    string::size_type pituus = n.length();

    if (pituus != 26){
        cout << "Error! The encryption key must contain 26 characters.";
        return false;
    }
    for (int i = 0; i < 26; ++i) {
            if (islower(n[i]) == false){
                cout << "Error! The encryption key must contain only lower case characters.";
                return false;
}
    int count = 0;
    for (int i = 0; i<26; i++){
    if(n[i] != n[i+1])
       count ++;
            }
    if (count != 26){
        cout << "Error! The encryption key must contain all alphabets a-z.";
        return false;
                   }


    }
    return true;
}

bool testtext(string text){
    int text_length;
    text_length = text.length();

    for (int i = 0; i < text_length; ++i) {
            if (islower(text[i]) == false){
                cout << "Error! The text to be encrypted must contain only lower case characters.";
                return false;
}
    }
    return true;
}

string ABC = "abcdefghijklmnopqrstuvwxyz";

string encrypt(string input_text, string key)
{
    int input_length;
    input_length = input_text.length();
    int index;
    string encrypted_text = input_text;
    for (int i = 0; i <= input_length-1; ++i) {
        index = ABC.find(input_text.at(i));
        encrypted_text.at(i) = key.at(index);
    }
    return encrypted_text;
}

int main()
{
    string key;
    string input_text;
    cout << "Enter the encryption key: ";
    cin >> key;
    if (testall(key) == false){
        return EXIT_FAILURE;
}
    else{
        cout << "Enter the text to be encrypted: ";
        cin >> input_text;

        if (testtext(input_text) == false){
             return EXIT_FAILURE;
        }
        else{
            cout << "Encrypted text: " << encrypt(input_text, key) << endl;
                }
        }
   }



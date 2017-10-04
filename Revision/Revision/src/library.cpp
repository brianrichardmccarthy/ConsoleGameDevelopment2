#include "library.h"
#include <iostream>
#include <algorithm>
#include <sstream>

/*
    A function that takes in a string with intergers seperated by multiple spaces
    and return a string where all integers are increased by one.
    Processing the string char by char.
*/
std::string incIntByChar(const std::string& s) {
    if (s.length() == 0) return std::string();

    int x = 0;
    std::string output("");

    while (x < s.length()) {
        if (s[x] == ' ') {
            output += ' ';
            x++;
            continue;
        }

        std::string substr = "";
        while (s[x] != ' ' && x < s.length()) {
            substr += s[x];
            x++;
        }
        output += std::to_string(std::stoi(substr) + 1);
    }

    return output;
}

/*
    A function that takes in a string with intergers seperated by multiple spaces 
    and return a string where all integers are increased by one.
    Using Tokens to sperate the string.
*/
std::string incIntByToken(const std::string& s) {

    std::stringstream stream(s);
    std::string loopNumbers = "";
    int index = 0;
    std::string output(s);

    while (stream >> loopNumbers) {
        index = output.find(loopNumbers, index);
        output.replace(index, loopNumbers.length(), std::to_string(std::stoi(loopNumbers) + 1));
        index++;
    }
    return output;
}
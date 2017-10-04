#include "library.h"
#include <iostream>

int main(int argc, char** argv) {

    // if the strings match then the output should be 1
    // else the output should be 0 if they don't match

    std::cout << "Testing first function" << std::endl;

    // Tests for function "incIntByChar"
    // simple tests
    std::cout << (incIntByChar("1") == "2") << std::endl;
    std::cout << (incIntByChar("2 2 3 ") == "3 3 4 ") << std::endl;
    std::cout << (incIntByChar(" 2  3 ") == " 3  4 ") << std::endl;
    
    // test for numbers bigger than 9
    std::cout << (incIntByChar("2 22 3 ") == "3 23 4 ") << std::endl;
    std::cout << (incIntByChar("11  22  300 ") == "12  23  301 ") << std::endl;
    std::cout << (incIntByChar("665 111 314 ") == "666 112 315 ") << std::endl;
    
    // test for negative numbers
    std::cout << (incIntByChar("-2 2 -3 ") == "-1 3 -2 ") << std::endl;
    std::cout << (incIntByChar(" -2  -2  -3 ") == " -1  -1  -2 ") << std::endl;
    std::cout << (incIntByChar("-2 2 3 ") == "-1 3 4 ") << std::endl;
    
    // test all of above
    std::cout << (incIntByChar(" -2 22 3 100") == " -1 23 4 101") << std::endl;
    std::cout << (incIntByChar(" -2 22 3 -100") == " -1 23 4 -99") << std::endl;
    std::cout << (incIntByChar(" -2 -22 3 100") == " -1 -21 4 101") << std::endl;

    std::cout << "Testing second function" << std::endl;

    // Tests for function "incIntByToken"
    // simple tests
    std::cout << (incIntByToken("1") == "2") << std::endl;
    std::cout << (incIntByToken("2 2 3 ") == "3 3 4 ") << std::endl;
    std::cout << (incIntByToken(" 2  3 ") == " 3  4 ") << std::endl;

    // test for numbers bigger than 9
    std::cout << (incIntByToken("2 22 3 ") == "3 23 4 ") << std::endl;
    std::cout << (incIntByToken("11  22  300 ") == "12  23  301 ") << std::endl;
    std::cout << (incIntByToken("665 111 314 ") == "666 112 315 ") << std::endl;

    // test for negative numbers
    std::cout << (incIntByToken("-2 2 -3 ") == "-1 3 -2 ") << std::endl;
    std::cout << (incIntByToken(" -2  -2  -3 ") == " -1  -1  -2 ") << std::endl;
    std::cout << (incIntByToken("-2 2 3 ") == "-1 3 4 ") << std::endl;

    // test all of above
    std::cout << (incIntByToken(" -2 22 3 100") == " -1 23 4 101") << std::endl; // fails for some fucking reason
    std::cout << (incIntByToken(" -2 22 3 -100") == " -1 23 4 -99") << std::endl; // fails for some fucking reason
    std::cout << (incIntByToken(" -2 -22 3 100") == " -1 -21 4 101") << std::endl; // passes for some fucking reason
    
    system("PAUSE");
    return 0;
}
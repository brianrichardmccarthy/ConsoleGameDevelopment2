#include "library.hpp"
#include <iostream>

void test();

int main(int argc, char** argv) {
    test();
    return 0;
}

void test() {
    /*
    std::cout << "tail(19) expected \"19\" got <" << tail(19) << ">" << std::endl;
        testing tail
        std::cout << "tail(1) expected \"1\" got <" << tail(1) << ">" << std::endl;
        std::cout << "tail(2) expected \"\" got <" << tail(2) << ">" << std::endl;
        std::cout << "tail(512) expected \"15\" got <" << tail(512) << ">" << std::endl;
        std::cout << "tail(7101) expected \"117\" got <" << tail(7101) << ">" << std::endl;
        std::cout << "tail(1102672) expected \"117\" got <" << tail(1102672) << ">" << std::endl;
    */
    std::cout << "numberOfDistincTails(1, 10) <" << numberOfDistinctTails(1, 10) << ">" << std::endl;
    std::cout << "numberOfDistincTails(18, 23) <" << numberOfDistinctTails(18, 23) << ">" << std::endl;
    std::cout << "numberOfDistincTails(1, 50) <" << numberOfDistinctTails(1, 50) << ">" << std::endl;
    std::cout << "numberOfDistincTails(1, 1000) <" << numberOfDistinctTails(1, 1000) << ">" << std::endl;
}
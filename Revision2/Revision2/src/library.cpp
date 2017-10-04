#include "library.hpp"
#include <algorithm>
#include <set>

/*
    Write a function to return the number of distinct tails from start to end (inclusive)
*/
unsigned long numberOfDistinctTails(unsigned long start, unsigned long end) {
   std::set<std::string> list;

    while (start <= end) list.insert(tail(start++));

    return list.size();
}

/*
    A tail of an integer n is the sorted (in non-descending order) the digits of x after extracting the even digits 
    e.g. input "321" returns "13"
*/
std::string tail(unsigned long x) {
    std::string output{""};
    
    for (auto c : std::to_string(x)) if (std::stoul(std::string{c}) % 2) output += c;
    
    std::sort(output.begin(), output.end());
    
    return output;
}
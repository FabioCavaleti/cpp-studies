#include <vector>
#include <deque>
#include <list>
#include <set>           // set and multiset
#include <map>           //map and multimap
#include <unordered_set> // Unordered set/multiset
#include <unordered_map> // unordered map/multimap
#include <iterator>
#include <algorithm>
#include <numeric> // numeric algorithms
#include <functional>
#include <random>

#include <iostream>

// String part 4: no membem functions


int main()
{
    std::string s = "Hogwarts is awesome !";
    std::string s1;

    std::cout << "s: " << s << std::endl;

    std::cin >> s1;

    getline(std::cin, s1); // Read a line including spaces
    getline(std::cin, s1, '!'); // Read a line until '!' character

    // Convert number to string
    s1 = std::to_string(10);

    // Convert string to number
    s1 = "190";
    int i = std::stoi(s1); // Convert string to int
    double d = std::stod(s1); // Convert string to double
    float f = std::stof(s1); // Convert string to float

    
    s1 = "10 is a number";
    size_t pos;
    i = std::stoi(s1, &pos); // Convert string to int, pos will be set to the position after the number

    // to_string and stox can only do simple conversions, for more complex conversions use stringstream
    


    
    return 0;
}
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

// Strings parte 2

int main()
{
    // Single element access
    std::string s("Hogwarts");

    s[2];
    s.at(2); // Throws std::out_of_range if the index is out of range

    s.front(); // First character
    s.back();  // Last character
    s.push_back('s'); // Adds a character to the end of the string
    s.pop_back(); // Removes the last character from the string

    s.begin();
    s.end();
    
    
    std::string s2(s.begin(), s.end()); // Constructs a string from a range of iterators
    
    // Ranged access
    s.assign(s2); // s = s2
    s.assign(s2, 2, 3); // s = s2.substr(2, 3); Assigns a substring of s2 to s; The substring starts at index 2 and has a length of 3
    
    s.reserve(100);
    s.assign("Hogwarts");
    s.append(" is");
    s.insert(s.size(), " Awesome", 8);
    
    std::cout << s << std::endl;
    
    s.replace(0, 8, "HOGWARTS");
    s.substr(0, 8); // Returns a substring of the string starting at index 0 and with a length of 8
    
    s.c_str(); // Returns a pointer to a null-terminated character array
    s.data(); // Returns a pointer to the underlying character array
    //s.data == s.c_str(); // In C++11 and later, data() is equivalent to c_str() for std::string


    s.erase(0, 8); // Removes the first 8 characters from the string
    s.clear(); // Clears the string, but does not change the capacity
    s.resize(10, 'a'); // Resizes the string to 10 characters, filling with 'a' if the new size is larger than the current size


    
    return 0;
}
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

// Member functions algorithms: copy, find, compare

int main()
{
    std::string s1 = "abcdef";
    char buf[20];

    size_t len = s1.copy(buf, 3);
    len = s1.copy(buf, 3, 2); // copy from index 2


    s1 = "Hogwarts is awesome !";

    size_t found = s1.find("is");
    found = s1.find("is", 5); // find "is" starting from index 5

    found = s1.find("is", 5, 2); // find "is" starting from index 5, with length 2

    found = s1.find_first_of("w"); // find first occurence
    found = s1.find_last_of("w"); // find last occurence

    found = s1.find_first_not_of("Hogwarts"); // find first character not in "Hogwarts"
    found = s1.find_last_not_of("Hogwarts"); // find last character not in "Hogwarts"

    s1.compare(buf); // returns 0 if equal, <0 if less, >0 if greater

    if (s1 > buf) // s1 > buf == s1.compare(buf) > 0
    {
        // Example
    }

    std::string s2 = s1 + "Love it !";
    // OBS: apesar da facilidade essas operações não são baratas, quanto maior o tamanho da string mais caro computacionalmente é fazer essas operações.


    
    return 0;
}
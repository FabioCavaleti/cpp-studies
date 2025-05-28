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


// String part 5: String and algorithms

int main()
{
    std::string s = "Hogwarts is awesome !!";
    
    int cnt = count(s.begin(), s.end(), 'a'); // Count occurrences of 'a'

    int cnt = count_if(s.begin(), s.end(), [](char c) {return c == 'a' || c == 'w'; });

    std::string::iterator it = search_n(s.begin(), s.end(), 2, '!'); // Find two consecutive '!' characters

    s.erase(it, it + 2); // Erase the two '!' characters
    s.insert(it, ' ');
    s.replace(it, it + 1, " lalala");

    std::string s1 = "abcd";
    std::string s2 = "cdab";

    is_permutation(s1.begin(), s1.end(), s2.begin()) ? 
        std::cout << "s1 is a permutation of s2" : 
        std::cout << "s1 is not a permutation of s2";

    
    
    



    
    return 0;
}
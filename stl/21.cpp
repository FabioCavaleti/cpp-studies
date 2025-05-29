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
#include <fstream>
#include <sstream>

#include <iostream>

//stream part 6: string stream

int main()
{
    std::stringstream ss; // Stream without IO operations, just for string manipulation

    ss << 89 << " " << 34.5 << " " << "Hogwarts"; // Insert data into the string stream
    std::cout << ss.str() << std::endl; // Output the contents of the string stream
    // ss.str(""); // Clear the string stream
    int a;
    float b;
    std::string s;
    ss >> a >> b >> s;
    std::cout << a << " " << b << " " + s << std::endl; // Read data from the string stream

}
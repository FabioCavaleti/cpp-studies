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

#include <iostream>

// stream part 5: Stream buffer

// IO operation:
// 1. Formatting the data -> stream
// 2. Communicating with the external device -> stream buffer

int main()
{
    std::cout << "Value" << std::endl;
    std::streambuf* pbuf = std::cout.rdbuf(); // Get the stream buffer of cout

    std::ostream mycout(pbuf); // Create a new ostream object using the same stream buffer as cout

    std::ofstream of("file.txt");
    std::streambuf* originalBuffer = std::cout.rdbuf(); // Save the original cout buffer
    std::cout.rdbuf(of.rdbuf()); // Redirect cout to the file stream buffer

    std::cout << "Hello, World!" << std::endl; // This will write to file.txt instead of the console, this lost the original cout buffer
    

    // Stream Buffer iterator
    std::istreambuf_iterator<char> i(std::cin);
    std::ostreambuf_iterator<char> o(std::cout);

    while( *i != '!')
    {
        *o = *i; // Copy characters from input stream to output stream
        ++i; // Move to the next character in the input stream
        ++o; // Move to the next position in the output stream
    }

    


    return 0;
}
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

int main()
{
    std::ofstream of("file.txt", std::ofstream::app); // Open file in append mode


    {
        of << "Goodbye" << std::endl;
    }

    {
        std::ofstream of2("file.txt", std::ofstream::in | std::ofstream::out);
        of.seekp(10, std::ios::beg); // Move the write pointer to the 10th byte from the beginning
        of.seekp(-5, std::ios::end); // Move the write pointer 5 bytes back from the end
        of.seekp(2, std::ios::cur); // Move the write pointer 2 bytes forward from the current position

    }

    std::ifstream ifs("file.txt"); // Open file for reading

    int i;
    ifs >> i; // Read an integer from the file
    // Error status: goodbit, badbit, failbit, eofbit
    ifs.good(); // All good
    ifs.bad(); // Non-recoverable error
    ifs.fail(); // Recoverable error (e.g., trying to read a string into an integer)
    ifs.eof(); // End of file reached

    ifs.clear(); // Clear the error flags
    ifs.clear(std::ios::goodbit); // Clear all error flags and set the goodbit flag
    ifs.rdstate(); // Get the current state of the stream

    ifs.clear(ifs.rdstate() & ~std::ios::failbit); // Clear only the failbit flag

    if (ifs) // == if (!ifs.fail())
    {
        std::cout << "Read successfully." << std::endl;
    }

    // Handle errors with exceptions

    ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit); // Set exceptions for failbit and badbit
    // when badbit or failbit is set, an exception of std::ios::failure will be thrown



    
    return 0;
}
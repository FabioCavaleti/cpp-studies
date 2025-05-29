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

// stream part 3: Formatting

int main()
{
    std::cout << 34 << std::endl;
    std::cout.setf(std::ios::oct, std::ios::basefield); // Set output format to octal
    std::cout << 34 << std::endl; // Output will be in octal format (42)
    std::cout.setf(std::ios::showbase);
    std::cout << 34 << std::endl; // Output will be in octal format with base (0o42)
    
    
    std::cout.setf(std::ios::hex, std::ios::basefield); // Set output format to hexadecimal
    std::cout << 34 << std::endl; // Output will be in hexadecimal format without base (22)
    
    std::cout.unsetf(std::ios::showbase);
    std::cout << 34 << std::endl; // Output will be in hexadecimal format (22)

    std::cout.setf(std::ios::dec, std::ios::basefield); // Set output format to decimal

    std::cout.width(10); // Set width for the next output

    // Member functions for unformatted IO

    std::ifstream ifs("file.txt");
    char buf[80];
    ifs.get(buf, 80); // Read up to 79 characters into buf (null-terminated)
    ifs.getline(buf, 80); // Read a line into buf (null-terminated)
    ifs.read(buf, 80); // Read exactly 80 characters into buf (no null-termination)
    ifs.ignore(80); // Ignore the next 80 characters in the input stream
    ifs.peek(); // Peek at the next character without extracting it
    ifs.unget(); // Unget the last character read, putting it back into the input stream
    ifs.putback('a'); // Put back a character into the input stream
    ifs.get(); // Read the next character from the input stream
    ifs.gcount(); // Get the number of characters read so far

    std::ofstream of("file.txt");
    of.put('a'); // Write a single character to the output stream
    of.write(buf, 80); // Write exactly 80 characters from buf to the output stream
    


    return 0;
}
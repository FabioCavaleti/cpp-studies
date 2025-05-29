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

// stream part 7: stream in classes


struct Dog{
    int age_;
    std::string name_;
    Dog(int age, const std::string& name) : age_(age), name_(name) {}
};

std::ostream& operator<<(std::ostream& sm, const Dog& d)
{
    sm << "Dog: " << d.name_ << ", Age: " << d.age_;
    return sm;
}

std::istream& operator>>(std::istream& sm, Dog& d)
{
    sm >> d.age_ >> d.name_;
    return sm;
}

int main()
{
    Dog d(0, "Bartolomeu");

    std::cin >> d;
    std::cout << d << std::endl;

}
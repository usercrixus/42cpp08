#include <iostream>
#include <vector>
#include <list>
#include "Easyfind.hpp"

int main() {
    // C++98 does NOT support initializer lists. Use push_back instead.
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    std::cout << "Index of 30 in vector: " << easyfind(vec, 30) << "\n";
    std::cout << "Index of 100 in vector: " << easyfind(vec, 100) << "\n"; // Not found

    // List example
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    lst.push_back(45);

    std::cout << "Index of 25 in list: " << easyfind(lst, 25) << "\n";
    std::cout << "Index of 200 in list: " << easyfind(lst, 200) << "\n"; // Not found

    return 0;
}

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // std::find
#include <iterator>  // std::distance

template<typename T>
int easyfind(T& a, int b) // Pass by reference for efficiency
{
    typename T::iterator it = std::find(a.begin(), a.end(), b);
    return (it != a.end()) ? std::distance(a.begin(), it) : -1;
}

#endif // EASYFIND_HPP
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

template<typename T>
void fillVector(std::vector<T>& vec, unsigned int num_el)
{
    auto value = std::rand();
    for (unsigned short i = 0U; i < num_el; ++i)
    {
        vec.push_back(std::rand());
    }
}


int main()
{
    std::vector<int> iVector;
    iVector.push_back(42);

    fillVector(iVector, 10U);

    std::cout << "Is empty? " << iVector.empty() << std::endl;
    std::cout << "Vector size: " << iVector.size() << std::endl;
    std::cout << "First element: " << iVector[0] << std::endl;
    std::cout << "Vector fron: " << iVector.front() << std::endl;
    std::cout << "Vector back: " << iVector.back() << std::endl;

    for (size_t i = 0U; i < iVector.size(); ++i)
    {
        std::cout << iVector.at(i) << "\t";
    }
    std::cout << std::endl; 

    // it is an iterator of type vector: std::vector<int>::iterator
    for (auto it = iVector.begin(); it != iVector.end(); ++it)
    {
        std::cout << *it << "\t"; 
    }
    std::cout << std::endl;

    for (auto el : iVector)
    {
        std::cout << el << "\t";
    }
    std::cout << std::endl;

    auto itMax = std::max_element(iVector.begin(), iVector.end());
    auto itMin = std::min_element(iVector.begin(), iVector.end());
    std::cout << "Max: " << *itMax << std::endl;
    std::cout << "Min: " << *itMin << std::endl;

    auto itFind42 = std::find(iVector.begin(), iVector.end(), 42);
    if (itFind42 != iVector.end())
    {
        std::cout << "42 found!" << std::endl;
    }

    std::sort(iVector.begin(), iVector.end());
    for (auto el : iVector)
    {
        std::cout << el << "\t";
    }
    std::cout << std::endl;


    
    // end of the program
    return 0;
}
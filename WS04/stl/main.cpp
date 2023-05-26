#include <iostream>
#include <random>
#include <vector>
#include <map>
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

    std::cout << "#####################" << std::endl;
    std::cout << "#### Vector case ####" << std::endl;
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
    // iVector.end() is an iterator that point to a position beyond 
    // the end of the vector
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

    // Algorithm methods
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

    //map
    std::cout << "##################" << std::endl;
    std::cout << "#### Map case ####" << std::endl;
    std::map<int, std::string> mapCardinal{ {1, "Primo"}, {2, "Secondo"} };

    // Add elements
    mapCardinal[3] = "Terzo";
    mapCardinal.insert(std::pair<int, std::string>(4, "Quarto"));

    auto it5 = mapCardinal.find(5);
    if (it5 != mapCardinal.end()) {
        std::cout << mapCardinal.at(5) << " found!" << std::endl;
    }
    else {
        std::cout << "Quinto not foud" << std::endl;
    }
    
    auto it4 = mapCardinal.find(4);
    if (it4 != mapCardinal.end())
    {
        std::cout << mapCardinal.at(4) << " found!" << std::endl;
    }
    else {
        std::cout << "Quarto not foud" << std::endl;
    }
    
    std::cout << "Map loop" << std::endl;
    for (auto pair : mapCardinal)
    {
        std::cout << pair.first << "\t" << pair.second << std::endl;
    }

    std::cout << "Map iterator loop" << std::endl;
    for (auto it = mapCardinal.begin(); it != mapCardinal.end(); ++it)
    {
        std::cout << it->first << "\t" << it->second << std::endl;
    }

    
    // end of the program
    return 0;
}
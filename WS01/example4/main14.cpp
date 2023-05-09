#include <iostream>
#include <experimental/filesystem>

int main()
{
    auto path = std::experimental::filesystem::current_path();
    std::cout << path << std::endl;
    return 0;
}
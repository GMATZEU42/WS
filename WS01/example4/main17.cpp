#include <iostream>
#include <filesystem>

int main()
{
    auto path = std::filesystem::current_path();
    std::cout << path << std::endl;
    return 0;
}
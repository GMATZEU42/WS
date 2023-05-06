#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <vector>

void saveResults(unsigned int dim, double timeCreation, double timeComputation)
{
    std::string fileName = (std::filesystem::current_path() / std::filesystem::path("benchmark_results.csv")).string();
    std::fstream stream(fileName, std::ostream::app);
    if (stream.is_open())
    {
        stream << "Cpp," << dim << "," << timeCreation << "," << timeComputation << "," << timeCreation + timeComputation << std::endl;
        stream.close();
    }
}

void printMatrix(std::vector<std::vector<int>> matrix)
{
    for(auto i = 0U; i < matrix.size(); ++i)
    {
        auto row = matrix[i];
        for(auto j = 0U; j < row.size(); ++j)
        {
            std::cout << row[j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[])
{
    if(argc > 1)
    {
        unsigned int dim = std::atoi(argv[1]);  
        if(dim > 0)
        {
            // creation matrix
            auto start = std::chrono::steady_clock::now();
            std::vector<std::vector<int>> matrix;
            for(int i = 0U; i < dim; ++i)
            {
                std::vector<int> vector{};
                for(int j = 0U; j < dim; ++j)
                {
                    vector.push_back(j);
                }
                matrix.push_back(vector);
            }
            auto end = std::chrono::steady_clock::now();
            auto tCreation = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() / 1000000.0;
            std::cout << "Time to create a matrix " << dim << "X" << dim << ": " << tCreation << std::endl;
            // calculate the square
            start = std::chrono::steady_clock::now();
            std::vector<std::vector<int>> matrix_sq;
            for(int k = 0U; k < dim; ++k)
            {
                std::vector<int> vector{};
                for(int i = 0U; i < dim; ++i)
                {
                    int sum = 0U;
                    for(int j = 0U; j < dim; ++j)
                    {
                        sum += matrix[i][j]*matrix[j][i];
                    }
                    vector.push_back(sum);
                }
                matrix_sq.push_back(vector);
            }
            end = std::chrono::steady_clock::now();
            auto tComputation = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() / 1000000.0;
            std::cout << "Time to compute the square of a matrix " << dim << "X" << dim << ": " << tComputation << std::endl;
            // debug print
            if (argc > 2)
            {
                auto tmp = argv[2];
                if (std::string(argv[2]) == "-d")
                {
                    printMatrix(matrix_sq);
                }
            }
            // save results
            saveResults(dim, tCreation, tComputation);
        }
        else
        {
            std::cout << "The dimension should be greater than zero" << std::endl;
        }
    }
    else
    {
        std::cout << "You should insert a dimension" << std::endl;
    }
    return 0;
}
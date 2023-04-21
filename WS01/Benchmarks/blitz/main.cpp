#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>

#include "blitz/array.h"

void saveResults(unsigned int dim, double timeCreation, double timeComputation)
{
    std::string fileName = (std::filesystem::current_path() / std::filesystem::path("benchmark_results.csv")).string();
    std::fstream stream(fileName, std::ostream::app);
    if (stream.is_open())
    {
        stream << "Blitz," << dim << "," << timeCreation << "," << timeComputation << "," << timeCreation + timeComputation << std::endl;
        stream.close();
    }
}

void printMatrix(blitz::Array<int, 2> matrix)
{
    std::cout << matrix << std::endl;
}

int main(int argc, char* argv[])
{
    if(argc > 1)
    {
        const unsigned int dim = std::atoi(argv[1]);  
        if(dim > 0)
        {
            // creation matrix
            auto start = std::chrono::steady_clock::now();
            
            blitz::Array<int, 2> matrix(dim, dim);
            
            for(int i = 0U; i < dim; ++i)
            {
                for(int j = 0U; j < dim; ++j)
                {
                    matrix(i, j) = j;
                }
            }
            auto end = std::chrono::steady_clock::now();
            auto tCreation = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() / 1000000.0;
            std::cout << "Time to create a matrix " << dim << "X" << dim << ": " << tCreation << std::endl;
            //printMatrix(matrix);
            // calculate the square
            start = std::chrono::steady_clock::now();
            blitz::Array<int, 2> matrix_sq(dim, dim);
            matrix_sq = matrix * matrix;
            end = std::chrono::steady_clock::now();
            auto tComputation = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() / 1000000.0;
            std::cout << "Time to compute the square of a matrix " << dim << "X" << dim << ": " << tComputation << std::endl;
            //printMatrix(matrix_sq);
            // save results
            saveResults(dim, tCreation, tComputation);
            /**/
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
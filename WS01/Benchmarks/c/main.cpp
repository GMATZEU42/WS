#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>

void saveResults(unsigned int dim, double timeCreation, double timeComputation)
{
    std::string fileName = (std::filesystem::current_path() / std::filesystem::path("benchmark_results.csv")).string();
    std::fstream stream(fileName, std::ostream::app);
    if (stream.is_open())
    {
        stream << "C," << dim << "," << timeCreation << "," << timeComputation << "," << timeCreation + timeComputation << std::endl;
        stream.close();
    }
}


void printSquareMatrix(int **matrix, int dim)
{
    for(int i = 0U; i < dim; ++i)
    {
        for(int j = 0U; j < dim; ++j)
        {
            std::cout << matrix[i][j] << "\t";
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
            int **matrix; 
            matrix = new int*[dim];
            for(int i = 0U; i < dim; ++i)
            {
                int* vector = new int[dim];
                for(int j = 0U; j < dim; ++j)
                {
                    vector[j] = j;
                }
                matrix[i] = vector;
            }
            auto end = std::chrono::steady_clock::now();
            auto tCreation = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() / 1000000.0;
            // calculate the square
            start = std::chrono::steady_clock::now();
            int** matrix_sq;
            matrix_sq = new int*[dim];  
            for(int k = 0U; k < dim; ++k)
            {   
                int* vector = new int[dim];
                for(int i = 0U; i < dim; ++i)
                {
                    int sum = 0U;
                    for(int j = 0U; j < dim; ++j)
                    {
                        sum += matrix[i][j] * matrix[j][i];
                    }
                    vector[i] = sum;
                }
                matrix_sq[k] = vector;
            }
            end = std::chrono::steady_clock::now();
            auto tComputation = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() / 1000000.0;
            //
            if (argc > 2)
            {
                auto tmp = argv[2];
                if (std::string(argv[2]) == "-d")
                {
                    printSquareMatrix(matrix_sq, dim);
                }
            }
            // free memory
            for (size_t i = 0U; i < dim; ++i)
            {
                delete matrix[i];
                delete matrix_sq[i];
            }
            delete[] matrix;
            delete[] matrix_sq;
            // save result
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
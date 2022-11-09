#include "matrix.h"
#include <iostream>
#include <memory>
#include <fmt/core.h>
#include <cassert>

#define UNUSED(variable) (void)variable

int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    try
    {
        Matrix<int, 2, -1> matrix;
        assert(matrix.size() == 0); // все ячейки свободны
        int a = matrix[0][0];
        fmt::print("a: {}\n", a);
        assert(a == -1);
        assert(matrix.size() == 0);
        matrix[100][100] = 314;
        matrix[100][110] = 315;
        fmt::print("matrix[100][100]: {}\n", (int)matrix[100][100]);
        fmt::print("matrix[100][110]: {}\n", (int)matrix[100][110]);
        fmt::print("matrix_size: {}\n", (int)matrix[100].size());
        assert(matrix.size() == 1);

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <format>

using Matrix = std::vector<std::vector<int>>;

void naive_matmul(
    const Matrix& matrix_a,
    const Matrix& matrix_b,
    Matrix& result_c
) {
    if (matrix_a.empty() || matrix_b.empty()) {
        throw std::invalid_argument("Input matrices cannot be empty");
    }

    const std::size_t a_rows = matrix_a.size();
    const std::size_t a_cols = matrix_a[0].size();

    const std::size_t b_rows = matrix_b.size();
    const std::size_t b_cols = matrix_b[0].size();


    
    if (a_cols != b_rows) {
        throw std::invalid_argument(
            std::format(
                "Matrix size mismatch: A is {}x{}, B is {}x{}",
                a_rows,
                a_cols,
                b_rows,
                b_cols
            )
        );
    }

    // Resize result to A.rows x B.cols
    result_c.assign(a_rows, std::vector<int>(b_cols, 0));

    for (std::size_t i = 0; i < a_rows; ++i) {
        for (std::size_t j = 0; j < b_cols; ++j) {
            for (std::size_t k = 0; k < a_cols; ++k) {
                result_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
}

int main() {
    Matrix matrix_a = {
        {1, 2, 3},
        {4, 5, 6}
    };

    Matrix matrix_b = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    Matrix result;

    naive_matmul(matrix_a, matrix_b, result);

    for (const auto& row : result) {
        for (int value : row) {
            std::cout << value << ' ';
        }
        std::cout << '\n';
    }
}

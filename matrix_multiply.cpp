#include <thread>
#include <iostream>
#include <vector>

/* sequential implementation of matrix multiplication */
void sequential_matrix_multiplication(long **A, size_t num_rows_a, size_t num_cols_a,
                                      long **B, size_t num_rows_b, size_t num_cols_b,
                                      long **C)
{
    for (size_t i = 0; i < num_rows_a; ++i)
    {
        for (size_t j = 0; j < num_cols_b; ++j)
        {
            C[i][j] = 0; // initialize result cell to zero
            for (size_t k = 0; k < num_cols_a; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/* parallel implementation of matrix multiplication */
void parallel_matrix_multiplication(long **A, size_t num_rows_a, size_t num_cols_a,
                                    long **B, size_t num_rows_b, size_t num_cols_b,
                                    long **C)
{
    auto row_multiply_col = [&](size_t i, size_t j) {
        C[i][j] = 0; // initialize result cell to zero
        for (size_t k = 0; k < num_cols_a; ++k)
        {
            C[i][j] += A[i][k] * B[k][j];
        }
    };
    std::vector<std::thread> threads;
    for (size_t i = 0; i < num_rows_a; ++i)
    {
        for (size_t j = 0; j < num_cols_b; ++j)
        {
            threads.push_back(std::thread(row_multiply_col, i, j));
        }
    }
    for (auto &th : threads)
    {
        th.join();
    }
}

int main()
{
    size_t m, n, p;
    m = n = p = 2;

    long **A, **B, **C;
    A = new long *[m];
    B = new long *[n];
    C = new long *[m];
    for (size_t i = 0; i < m; ++i)
        A[i] = new long[n];
    for (size_t i = 0; i < n; ++i)
        B[i] = new long[p];
    for (size_t i = 0; i < m; ++i)
        C[i] = new long[p];

    for (size_t i = 0; i < m; ++i)
        for (size_t j = 0; j < n; ++j)
            A[i][j] = i + j;

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < p; ++j)
            B[i][j] = i + j;

    // sequential_matrix_multiplication(A, 2, 2, B, 2, 2, C);
    parallel_matrix_multiplication(A, 2, 2, B, 2, 2, C);
    for (size_t i = 0; i < 2; ++i)
    {
        for (size_t j = 0; j < 2; ++j)
        {
            std::cout << C[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}

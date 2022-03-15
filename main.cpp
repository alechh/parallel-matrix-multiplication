#include <iostream>
#include "omp.h"

int main()
{
    const int M = 3;
    const int N = 3;
    const int K = 5;

    const int SIZE_A = M * K + K;
    const int SIZE_B = N * K + N;
    const int SIZE_C = M * N + N;

    double *A = new double [SIZE_A];
    double *B = new double [SIZE_B];
    double *C = new double [SIZE_C];

    double sum;

#pragma omp parallel for private(k,j,sum)
    for (int i = 0; i < M; ++i)
    {
        int indexIK = i * K;
        for (int j = 0; j < N; ++j)
        {
            int indexIN = i * N;

            sum = 0;
            for (int k = 0; k < K; ++k)
                sum += A[indexIK + k] * B[k * N + j];
            C[indexIN + j] = sum;
        }
    }
}


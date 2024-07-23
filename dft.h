#ifndef DFT_H
#define DFT_H

#include "header.h"
#include "complex.h"
#include "mathlib.h"

/*
    @brief DFT
    @param 関数の値
    @param 関数の要素数
    @return DFTの結果
*/
COMPLEX *DFT(double *, int);


/*
    @brief 逆DFT
    @param COMPLEX型の関数
    @param 関数の要素数
    @return 逆DFTの結果
*/
double *iDFT(COMPLEX *, int);


COMPLEX *DFT(double *function, int N)
{
    COMPLEX *FUNCTION = (COMPLEX *)malloc(sizeof(COMPLEX) * N);
    for(int k = 0; k < N; k++){
        FUNCTION[k].real = 0.0;
        FUNCTION[k].imaginary = 0.0;
        for(int n = 0; n < N; n++){
            COMPLEX euler = EULER(((-1) * 2 * M_PI * k * n) / N);
            FUNCTION[k].real += function[n] * euler.real;
            FUNCTION[k].imaginary += function[n] * euler.imaginary;
        }
    }
    return FUNCTION;
}


double *iDFT(COMPLEX *FUNCTION, int N)
{
    double *function = (double *)malloc(sizeof(double) * N);
    init_double(function, N);
    for(int n = 0; n < N; n++){
        for(int k = 0; k < N; k++){
            COMPLEX euler = EULER((2 * M_PI * k * n) / N);
            function[n] += (FUNCTION[k].real * euler.real - FUNCTION[k].imaginary * euler.imaginary) + (FUNCTION[k].real * euler.imaginary + FUNCTION[k].imaginary * euler.real);
        }
        function[n] /= N;
    }
    return function;
}



#endif

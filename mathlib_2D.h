#ifndef MATHLIB_2D_H
#define MATHLIB_2D_H

#include "header.h"
#include "complex.h"

/*
    @brief double型の2次元配列を小数第n位で四捨五入
    @param 関数
    @param x
    @param y
    @param n: 小数第n位で四捨五入
    @return DCTの結果
*/
double **rounder_n_2D(double **, int, int, int);


/*
    @brief COMPLEX型の2次元配列を小数第n位で四捨五入
    @param 関数
    @param x
    @param y
    @param n: 小数第n位で四捨五入
    @return DCTの結果
*/
COMPLEX **rounder_n_2D_complex(COMPLEX **, int, int, int);

/*
    @brief double型の2次元配列をCOMPLEX型に変換
    @param double型の2次元配列
    @param x
    @param y
    @return COMPLEX型の2次元配列
*/
COMPLEX **double_to_complex_2D(double **, int, int);


/*
    @brief COMPLEX型の2次元配列をdouble型に変換
    @param COMPLEX型の2次元配列
    @param x
    @param y
    @return double型の2次元配列
*/
double **complex_to_double_2D(COMPLEX **, int, int);

/*
    @brief COMPLEX型の2次元配列をコピー
    @param コピー元のCOMPLEX型の2次元配列
    @param x
    @param y
    @return コピー先のCOMPLEX型の2次元配列
*/
COMPLEX **copy_COMPLEX_2D(COMPLEX **, int, int);


double **rounder_n_2D(double **function, int X, int Y, int n)
{
    for(int y = 0; y < Y; y++){
        for(int x = 0; x < X; x++){
            function[x][y] = function[x][y] * pow(10, (n - 1));
            function[x][y] = round(function[x][y]);
            function[x][y] = function[x][y] / pow(10, (n - 1));
        }
    }
    return function;
}

COMPLEX **rounder_n_2D_complex(COMPLEX **function, int X, int Y, int n)
{
    for(int y = 0; y < Y; y++){
        for(int x = 0; x < X; x++){
            function[x][y].real = function[x][y].real * pow(10, (n - 1));
            function[x][y].real = round(function[x][y].real);
            function[x][y].real = function[x][y].real / pow(10, (n - 1));

            function[x][y].imaginary = function[x][y].imaginary * pow(10, (n - 1));
            function[x][y].imaginary = round(function[x][y].imaginary);
            function[x][y].imaginary = function[x][y].imaginary / pow(10, (n - 1));
        }
    }
    return function;
}


COMPLEX **double_to_complex_2D(double **function, int X, int Y)
{
    COMPLEX **output = (COMPLEX **)malloc(sizeof(COMPLEX *) * X);
    for(int i = 0; i < X; i++){
        output[i] = (COMPLEX *)malloc(sizeof(COMPLEX) * Y);
    }

    for(int y = 0; y < Y; y++){
        for(int x = 0; x < X; x++){
            output[x][y].real = function[x][y];
            output[x][y].imaginary = 0.0;
        }
    }

    return output;
}


double **complex_to_double_2D(COMPLEX **function, int X, int Y)
{
    double **output = (double **)malloc(sizeof(double *) * X);
    for(int i = 0; i < X; i++){
        output[i] = (double *)malloc(sizeof(double) * Y);
    }

    for(int y = 0; y < Y; y++){
        for(int x = 0; x < X; x++){
            output[x][y] = function[x][y].real;
        }
    }

    return output;
}



COMPLEX **copy_COMPLEX_2D(COMPLEX **source, int X, int Y)
{
    COMPLEX **output = (COMPLEX **)malloc(sizeof(COMPLEX *) * X);
    for(int i = 0; i < X; i++){
        output[i] = (COMPLEX *)malloc(sizeof(COMPLEX) * Y);
    }

    for(int y = 0; y < Y; y++){
        for(int x = 0; x < X; x++){
            output[x][y] = source[x][y];
        }
    }

    return output;
}

#endif

#ifndef DFT_2D_H
#define DFT_2D_H

#include "header.h"
#include "complex.h"
#include "mathlib.h"


/*
    @brief 2次元DFT
    @param 関数の値
    @param x方向の要素数
    @param y方向の要素数
    @return 2次元DFTの結果
*/
COMPLEX **DFT_x(COMPLEX **, int, int);


/*
    @brief 2次元DFT
    @param 関数の値
    @param x方向の要素数
    @param y方向の要素数
    @return 2次元DFTの結果
*/
COMPLEX **DFT_y(COMPLEX **, int, int);




COMPLEX **DFT_x(COMPLEX **function, int x, int y)
{
    // F[x][y]
    COMPLEX **FUNCTION = (COMPLEX **)malloc(sizeof(COMPLEX *) * x);
    for(int i = 0; i < x; i++){
        FUNCTION[i] = (COMPLEX *)malloc(sizeof(COMPLEX) * y);
    }

    for(int column = 0; column < x; column++){
        for(int k = 0; k < y; k++){
            FUNCTION[column][k].real = 0.0;
            FUNCTION[column][k].imaginary = 0.0;
            for(int n = 0; n < y; n++){
                COMPLEX euler = EULER(((-1) * 2 * M_PI * k * n) / y);
                COMPLEX temp = MUL(function[column][n], euler);
                FUNCTION[column][k].real += temp.real;
                FUNCTION[column][k].imaginary += temp.imaginary;

            }
        }
    }
    return FUNCTION;
}


COMPLEX **DFT_y(COMPLEX **function, int x, int y)
{
    // F[x][y]
    COMPLEX **FUNCTION = (COMPLEX **)malloc(sizeof(COMPLEX *) * x);
    for(int i = 0; i < x; i++){
        FUNCTION[i] = (COMPLEX *)malloc(sizeof(COMPLEX) * y);
    }

    for(int row = 0; row < y; row++){
        for(int k = 0; k < x; k++){
            FUNCTION[k][row].real = 0.0;
            FUNCTION[k][row].imaginary = 0.0;
            for(int n = 0; n < x; n++){
                COMPLEX euler = EULER(((-1) * 2 * M_PI * k * n) / x);
                COMPLEX temp = MUL(function[n][row], euler);
                FUNCTION[k][row].real += temp.real;
                FUNCTION[k][row].imaginary += temp.imaginary;
            }
        }
    }
    return FUNCTION;
}


#endif

#ifndef DCT_2D_H
#define DCT_2D_H

#include "header.h"


/*
    @brief 2次元DCT
    @param 関数
    @param x
    @param y
    @return DCTの結果
*/
double **DCT_x(double **, int, int);

/*
    @brief 2次元DCT
    @param 関数
    @param x
    @param y
    @return DCTの結果
*/
double **DCT_y(double **, int, int);



double **DCT_x(double **function, int X, int Y)
{
    double **cosine = (double **)malloc(sizeof(double) * X);
    for(int i = 0; i < X; i++){
        cosine[i] = (double *)malloc(sizeof(double) * Y);
    }

    for(int x = 0; x < X; x++){
        for(int k = 0; k < Y; k++){
            cosine[x][k] = 0;
            for(int n = 0; n < Y; n++){
                cosine[x][k] += function[x][n] * cos((2 * n + 1) * k * M_PI / (2 * Y));
            }
        }
    }

    return cosine;
}


double **DCT_y(double **function, int X, int Y){
    double **cosine = (double **)malloc(sizeof(double) * X);
    for(int i = 0; i < X; i++){
        cosine[i] = (double *)malloc(sizeof(double) * Y);
    }

    for(int y = 0; y < Y; y++){
        for(int k = 0; k < X; k++){
            cosine[k][y] = 0;
            for(int n = 0; n < X; n++){
                cosine[k][y] += function[n][y] * cos((2 * n + 1) * k * M_PI / (2 * X));
            }
        }
    }

    return cosine;
}


#endif

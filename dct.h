#ifndef DCT_H
#define DCT_H

#include "header.h"
#include "complex.h"
#include "mathlib.h"

/*
    @brief DCT
    @param 関数の値
    @param 関数の要素数
    @return DCTの結果

*/
double *DCT(double *, int);

/*
    @brief 逆DCT
    @param 関数
    @param 関数の要素数
    @return 逆DCTの結果

*/
double *iDCT(double *, int);


/*
    @brief DCTフィルタ．index = k以上の要素を0にする
    @param 関数
    @param 関数の要素数
    @param フィルタの次数
    @return フィルタの結果
*/
double *DCT_Filter(double *, int, int);

/*
    @brief DCT量子化
    @param 関数
    @param 関数の要素数
    @return 量子化の結果
*/
double *DCT_QUANTIZE( double *, int);




double *DCT(double *function, int N)
{
    double *dct = (double *)malloc(sizeof(double) * N);
    for(int k = 0; k < N; k++){
        dct[k] = 0;
        for(int n = 0; n < N; n++){
            dct[k] += function[n] * cos((2 * n + 1) * k * M_PI / (2 * N));
        }
        // dct[k] = rounder(dct[k]);
    }
    return dct;
}


double *iDCT(double *dct, int N)
{
    double *function = (double *)malloc(sizeof(double) * N);
    double value = 2 / (double)N;
    for(int n = 0; n < N; n++){
        function[n] = 0;
        for(int k = 1; k < N; k++){
            function[n] += dct[k] * cos(((2 * n + 1) * k * M_PI) / (2 * N));
        }
        function[n] += 0.5 * dct[0];
        function[n] *= value;
        // function[n] = rounder(function[n]);
    }
    return function;
}


double *DCT_Filter(double *cosine, int N, int k)
{
    double *output = (double *)malloc(sizeof(double) * N);
    for(int i = 0; i < N; i++){
        if(i < k){
            output[i] = cosine[i];
        }else if(i >= k){
            output[i] = 0;
        }
    }
    return output;
}

double *DCT_QUANTIZE( double *cosine, int N)
{
    double *cosine_quantize = (double *)malloc(sizeof(double) * N);
    for(int k = 0; k < N; k++){
        cosine_quantize[k] = 0;
        cosine_quantize[k] = floor((cosine[k] / 20) + 0.5) * 20;
    }
    return cosine_quantize;
}

#endif

#ifndef FFT_2D_H
#define FFT_2D_H

#include "header.h"
#include "complex.h"
#include "mathlib.h"

/*
    @brief 2次元FFT
    @param 関数の値
    @param x方向の要素数
    @param y方向の要素数
*/
void FFT_x(COMPLEX **, int, int);

/*
    @brief 2次元FFT
    @param 関数の値
    @param x方向の要素数
    @param y方向の要素数
*/
void FFT_y(COMPLEX **, int, int);


/*
    @brief バタフライ演算
    @param 関数の値
    @param 関数の要素数
*/
void FFT(COMPLEX *, int);


/*
    @brief 2次元逆FFT
    @param 関数の値
    @param x方向の要素数
    @param y方向の要素数
*/
void iFFT_x(COMPLEX **, int, int);

/*
    @brief 2次元逆FFT
    @param 関数の値
    @param x方向の要素数
    @param y方向の要素数
*/
void iFFT_y(COMPLEX **, int, int);


/*
    @brief 逆FFT
    @param 関数の値
    @param 関数の要素数
*/
void iFFT(COMPLEX *, int);





void FFT_x(COMPLEX **data, int x, int y) {
    for(int i = 0; i < x; i++){
        FFT(data[i], y);
    }
}


void FFT_y(COMPLEX **data, int x, int y) {
    COMPLEX *column = (COMPLEX *)malloc(sizeof(COMPLEX) * x);
    for(int j = 0; j < y; j++){
        for(int i = 0; i < x; i++){
            column[i] = data[i][j];
        }
        FFT(column, x);
        for(int i = 0; i < x; i++){
            data[i][j] = column[i];
        }
    }
    free(column);
}



void FFT(COMPLEX *data, int N){
    if (N <= 1) return;

    // データを偶数と奇数の部分に分割
    COMPLEX *data_even = (COMPLEX *)malloc(sizeof(COMPLEX) * (N / 2));
    COMPLEX *data_odd = (COMPLEX *)malloc(sizeof(COMPLEX) * (N / 2));

    for (int i = 0; i < N / 2; i++) {
        data_even[i] = data[2 * i];
        data_odd[i] = data[2 * i + 1];
    }

    // 再帰的にバタフライ演算を実行
    FFT(data_even, N / 2);
    FFT(data_odd, N / 2);

    // バタフライ演算
    for (int k = 0; k < N / 2; k++) {
        double theta = -2 * M_PI * k / N;
        COMPLEX t = {data_odd[k].real * cos(theta) - data_odd[k].imaginary * sin(theta),
                      data_odd[k].real * sin(theta) + data_odd[k].imaginary * cos(theta)};
        data[k].real = data_even[k].real + t.real;
        data[k].imaginary = data_even[k].imaginary + t.imaginary;
        data[k + N / 2].real = data_even[k].real - t.real;
        data[k + N / 2].imaginary = data_even[k].imaginary - t.imaginary;
    }

    free(data_even);
    free(data_odd);
}




void iFFT(COMPLEX *data, int N){
    if (N <= 1) return;

    // データを偶数と奇数の部分に分割
    COMPLEX *data_even = (COMPLEX *)malloc(sizeof(COMPLEX) * (N / 2));
    COMPLEX *data_odd = (COMPLEX *)malloc(sizeof(COMPLEX) * (N / 2));

    for (int i = 0; i < N / 2; i++) {
        data_even[i] = data[2 * i];
        data_odd[i] = data[2 * i + 1];
    }

    // 再帰的にバタフライ演算を実行
    iFFT(data_even, N / 2);
    iFFT(data_odd, N / 2);

    // バタフライ演算
    for (int k = 0; k < N / 2; k++) {
        double theta = 2 * M_PI * k / N;  // FFTとの違いはここです
        COMPLEX t = {data_odd[k].real * cos(theta) - data_odd[k].imaginary * sin(theta),
                      data_odd[k].real * sin(theta) + data_odd[k].imaginary * cos(theta)};
        data[k].real = (data_even[k].real + t.real) / 2;  // FFTとの違いはここです
        data[k].imaginary = (data_even[k].imaginary + t.imaginary) / 2;  // FFTとの違いはここです
        data[k + N / 2].real = (data_even[k].real - t.real) / 2;  // FFTとの違いはここです
        data[k + N / 2].imaginary = (data_even[k].imaginary - t.imaginary) / 2;  // FFTとの違いはここです
    }

    free(data_even);
    free(data_odd);
}

void iFFT_x(COMPLEX **data, int x, int y) {
    for(int i = 0; i < x; i++){
        iFFT(data[i], y);
    }
}

void iFFT_y(COMPLEX **data, int x, int y) {
    COMPLEX *column = (COMPLEX *)malloc(sizeof(COMPLEX) * x);
    for(int j = 0; j < y; j++){
        for(int i = 0; i < x; i++){
            column[i] = data[i][j];
        }
        iFFT(column, x);
        for(int i = 0; i < x; i++){
            data[i][j] = column[i];
        }
    }
    free(column);
}



#endif

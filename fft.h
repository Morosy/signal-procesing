#ifndef FFT_H
#define FFT_H

#include "header.h"
#include "complex.h"
#include "mathlib.h"


/*
    @brief FFT
    @param 関数の値
    @param 関数の要素数
*/
void FFT(COMPLEX *, int );
// COMPLEX *FFT(double* input, int N);

/*
    @brief 逆FFT
    @param COMPLEX型の関数
    @param 関数の要素数
*/
// void iFFT(COMPLEX *data, int N);

/*
    @brief 逆FFT
    @param COMPLEX型の関数
    @param 関数の要素数
*/
void iFFT(COMPLEX *, int );
// double *iFFT(COMPLEX* data, int N);

void swap(COMPLEX *, COMPLEX *);
void bitReverse(COMPLEX *, int);

/*
    @brief 逆FFTの実行結果をソート
    @param 関数
    @param 関数の要素数
    @return ソートの結果
*/
double *sort_iFFT(double *, int);





// void FFT(COMPLEX *data, int N){
//     if (N <= 1) return;

//     // データを偶数と奇数の部分に分割
//     COMPLEX *data_even = (COMPLEX *)malloc(sizeof(COMPLEX) * (N / 2));
//     COMPLEX *data_odd = (COMPLEX *)malloc(sizeof(COMPLEX) * (N / 2));

//     for (int i = 0; i < N / 2; i++) {
//         data_even[i] = data[2 * i];
//         data_odd[i] = data[2 * i + 1];
//     }

//     // 再帰的にバタフライ演算を実行
//     FFT(data_even, N / 2);
//     FFT(data_odd, N / 2);

//     // バタフライ演算
//     for (int k = 0; k < N / 2; k++) {
//         double theta = -2 * M_PI * k / N;
//         COMPLEX t = {data_odd[k].real * cos(theta) - data_odd[k].imaginary * sin(theta),
//                       data_odd[k].real * sin(theta) + data_odd[k].imaginary * cos(theta)};
//         data[k].real = data_even[k].real + t.real;
//         data[k].imaginary = data_even[k].imaginary + t.imaginary;
//         data[k + N / 2].real = data_even[k].real - t.real;
//         data[k + N / 2].imaginary = data_even[k].imaginary - t.imaginary;
//     }

//     free(data_even);
//     free(data_odd);
// }


// ビットリバースの関数
// int reverse_bit(int num, int m) {
//     int res = 0;
//     for (int i = 0; i < m; i++) {
//         res = (res << 1) | (num & 1);
//         num >>= 1;
//     }
//     return res;
// }

// FFTの実装
// COMPLEX *FFT(double* input, int N){
//     COMPLEX *output = (COMPLEX *)malloc(sizeof(COMPLEX) * N);
//     // int N = N;
//     int m = (int)log2(N);

//     // メモ化
//     COMPLEX* memo = (COMPLEX*)malloc(sizeof(COMPLEX) * (N / 2));
//     for (int i = 0; i < N / 2; i++) {
//         double vector = -2.0 * M_PI * i / N;
//         memo[i].real = cos(vector);
//         memo[i].imaginary = sin(vector);
//     }

//     // 実数を複素数に変換
//     for (int i = 0; i < N; i++) {
//         output[i].real = input[i];
//         output[i].imaginary = 0.0;
//     }

//     // ならびかえ
//     for (int i = 0; i < N; i++) {
//         int j = reverse_bit(i, m);
//         if (i < j) {
//             COMPLEX temp = output[i];
//             output[i] = output[j];
//             output[j] = temp;
//         }
//     }

//     // FFTのメインループ
//     for (int s = 1; s <= m; ++s) {
//         int m = 1 << s;
//         int m2 = m >> 1;
//         for (int j = 0; j < m2; ++j) {
//             COMPLEX w = memo[N / m * j];
//             for (int k = j; k < N; k += m) {
//                 COMPLEX t = MUL(w, output[k + m2]);
//                 output[k + m2] = SUB(output[k], t);
//                 output[k] = ADD(output[k], t);
//             }
//         }
//     }
//     free(memo);

//     return output;
// }




void swap(COMPLEX *a, COMPLEX *b){
    COMPLEX temp = *a;
    *a = *b;
    *b = temp;
}

// void bitReverse(COMPLEX *data, int N) {
//     int i, j = 0;
//     for(i = 0; i < N; i++) {
//         if (j > i) {
//             swap(&data[j], &data[i]);
//         }
//         int k = N;
//         while (j & (k >>= 1)) {
//             j &= ~k;
//         }
//         j |= k;
//     }
// }

// void iFFT(COMPLEX *data, int N) {
//     bitReverse(data, N);
//     double pi = acos(-1);
//     for(int s = 1; (1 << s) <= N; s++) {
//         int m = 1 << s;
//         int m2 = m >> 1;
//         COMPLEX w;
//         w.real = cos(pi / m2);
//         w.imaginary = -sin(pi / m2);
//         for(int k = 0; k < N; k += m) {
//             COMPLEX e = {1, 0};
//             for(int j = 0; j < m2; j++) {
//                 COMPLEX t, u;
//                 t.real = data[k + j].real + e.real * data[k + j + m2].real - e.imaginary * data[k + j + m2].imaginary;
//                 t.imaginary = data[k + j].imaginary + e.real * data[k + j + m2].imaginary + e.imaginary * data[k + j + m2].real;
//                 u.real = data[k + j].real - e.real * data[k + j + m2].real + e.imaginary * data[k + j + m2].imaginary;
//                 u.imaginary = data[k + j].imaginary - e.real * data[k + j + m2].imaginary - e.imaginary * data[k + j + m2].real;
//                 data[k + j] = t;
//                 data[k + j + m2] = u;
//                 COMPLEX next;
//                 next.real = e.real * w.real - e.imaginary * w.imaginary;
//                 next.imaginary = e.real * w.imaginary + e.imaginary * w.real;
//                 e = next;
//             }
//         }
//     }
//     for(int i = 0; i < N; i++) {
//         data[i].real /= N;
//         data[i].imaginary /= N;
//     }
// }

void bitReverse(COMPLEX *data, int N) {
    int i, j, k;
    for (i = 1, j = 0; i < N; i++) {
        for (k = N >> 1; k > (j ^= k); k >>= 1);
        if (i < j) {
            COMPLEX temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
}

void FFT(COMPLEX *data, int N){
    if (N <= 1) return;

    COMPLEX *data_even = (COMPLEX *)malloc(sizeof(COMPLEX) * (N / 2));
    COMPLEX *data_odd = (COMPLEX *)malloc(sizeof(COMPLEX) * (N / 2));

    for (int i = 0; i < N / 2; i++) {
        data_even[i] = data[2 * i];
        data_odd[i] = data[2 * i + 1];
    }

    FFT(data_even, N / 2);
    FFT(data_odd, N / 2);

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



void iFFT(COMPLEX *data, int N) {
    bitReverse(data, N);
    double pi = acos(-1);
    for(int s = 1; (1 << s) <= N; s++) {
        int m = 1 << s;
        int m2 = m >> 1;
        COMPLEX w, wm;
        wm.real = cos(pi / m2);
        wm.imaginary = -sin(pi / m2);
        for(int k = 0; k < N; k += m) {
            COMPLEX e = {1, 0};
            for(int j = 0; j < m2; j++) {
                COMPLEX t, u;
                t.real = e.real * data[k + j + m2].real - e.imaginary * data[k + j + m2].imaginary;
                t.imaginary = e.real * data[k + j + m2].imaginary + e.imaginary * data[k + j + m2].real;
                u.real = data[k + j].real - t.real;
                u.imaginary = data[k + j].imaginary - t.imaginary;
                data[k + j].real = data[k + j].real + t.real;
                data[k + j].imaginary = data[k + j].imaginary + t.imaginary;
                data[k + j + m2] = u;
                COMPLEX next;
                next.real = e.real * wm.real - e.imaginary * wm.imaginary;
                next.imaginary = e.real * wm.imaginary + e.imaginary * wm.real;
                e = next;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        data[i].real /= N;
        data[i].imaginary /= N;
    }
}




// double *iFFT(COMPLEX* data, int N)
// {
//     // int N = N;
//     double omega_conj = 2 * M_PI / N;
//     double vector;
//     double *output = (double *)malloc(sizeof(double) * N);

//     for(int n = 0; n < N; n++) {
//         output[n] = 0;
//         for(int k = 0; k < N; k++) {
//             vector = (double)n * (double)k * omega_conj;
//             COMPLEX multi;
//             multi.real = cos(vector);
//             multi.imaginary = sin(vector);
//             COMPLEX term = MUL(data[k], multi);
//             output[n] += term.real;
//         }
//         output[n] /= N;
//     }
//     return output;
// }


double *sort_iFFT(double *data, int N)
{
    double *output = (double *)malloc(sizeof(double) * N);
    output[0] = data[0];
    for(int i = 1; i < N; i++){
        output[i] = data[N - i];
    }
    return output;
}



#endif

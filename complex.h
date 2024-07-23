#ifndef COMPLEX_H
#define COMPLEX_H

#include "header.h"


typedef struct{
    double real;
    double imaginary;
}COMPLEX;

/*
    @brief double型の初期化
    @param double型の配列
    @param 配列の要素数
    @return double型の初期化結果

*/
double *init_double(double *, int);

/*
    @brief COMPLEX型の初期化
    @param COMPLEX型の配列
    @param 配列の要素数
    @return COMPLEXの初期化結果
*/
COMPLEX *init_complex(COMPLEX *, int);


/*
    @brief double型の配列をCOMPLEX型に変換
    @param double型の配列
    @param 配列の要素数
    @return COMPLEX型の配列
*/
COMPLEX *double_To_COMPLEX(double *, int);

/*
    @brief COMPLEX型の配列をdouble型に変換
    @param COMPLEX型の配列
    @param 配列の要素数
    @return double型の配列
*/
double *COMPLEX_To_double(COMPLEX *, int);


/*
    @brief double型のコピー
    @param コピー元のdouble型
    @param 配列の要素数
    @return コピー先のdouble型
*/
double *copy_double(double *, int);


/*
    @brief COMPLEX型のコピー
    @param コピー元のCOMPLEX型
    @param 配列の要素数
    @return コピー先のCOMPLEX型
*/
COMPLEX *copy_COMPLEX(COMPLEX *, int);






double *init_double(double *array, int size)
{
    for(int i = 0; i < size; i++){
        array[i] = 0.0;
    }
    return array;
}


COMPLEX *init_complex(COMPLEX *array, int size)
{
    for(int i = 0; i < size; i++){
        array[i].real = 0.0;
        array[i].imaginary = 0.0;
    }
    return array;
}


COMPLEX *double_To_COMPLEX(double *data, int N)
{
    COMPLEX *output = (COMPLEX *)malloc(sizeof(COMPLEX) * N);
    output = init_complex(output, N);

    for(int i = 0; i < N; i++){
        output[i].real = data[i];
    }

    return output;
}


double *COMPLEX_To_double(COMPLEX *data, int N)
{
    double *output = (double *)malloc(sizeof(double) * N);
    output = init_double(output, N);

    for(int i = 0; i < N; i++){
        output[i] = data[i].real;
    }

    return output;
}


double *copy_double(double *source, int N)
{
    double *output = (double *)malloc(sizeof(double) * N);
    output = init_double(output, N);

    for(int i = 0; i < N; i++){
        output[i] = source[i];
    }

    return output;
}


COMPLEX *copy_COMPLEX(COMPLEX *source, int N)
{
    COMPLEX *output = (COMPLEX *)malloc(sizeof(COMPLEX) * N);
    output = init_complex(output, N);

    for(int i = 0; i < N; i++){
        output[i].real = source[i].real;
        output[i].imaginary = source[i].imaginary;
    }

    return output;
}


#endif

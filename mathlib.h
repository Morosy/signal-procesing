#ifndef MATHLIB_H
#define MATHLIB_H

#include <math.h>

#include "header.h"
#include "COMPLEX.h"


/*
    @brief COMPLEX型の加算
    @param 二つのCOMPLEX型
    @return COMPLEXの加算結果
*/
COMPLEX ADD(COMPLEX, COMPLEX);

/*
    @brief COMPLEX型の減算
    @param 二つのCOMPLEX型
    @return COMPLEXの減算結果
*/
COMPLEX SUB(COMPLEX, COMPLEX);

/*
    @brief COMPLEX型の乗算
    @param 二つのCOMPLEX型
    @return COMPLEXの乗算結果
*/
COMPLEX MUL(COMPLEX, COMPLEX);

/*
    @brief COMPLEX型の除算
    @param 二つのCOMPLEX型
    @return COMPLEXの除算結果
*/
COMPLEX DIV(COMPLEX, COMPLEX);


/*
    @brief オイラーの公式
    @param theta 角度
    @return オイラーの公式の結果
*/
COMPLEX EULER(double);


/*
    @brief COMPLEX型の信号の大きさを求める
    @param COMPLEX型の信号
*/
double return_Power(COMPLEX);


/*
    @brief COMPLEX型の構造体の小数第1位を四捨五入する
    @param COMPLEX型の構造体
    @return 小数点第一位までの四捨五入後のCOMPLEX型の構造体
*/
COMPLEX rounder_1(COMPLEX);


/*
    @brief COMPLEX型の構造体の配列の小数第1位を四捨五入する
    @param COMPLEX型の構造体の配列
    @param 配列の要素数
    @return 小数点第一位までの四捨五入後のCOMPLEX型の構造体の配列
*/
COMPLEX *rounder_array_1(COMPLEX *, int);

/*
    @brief COMPLEX型の構造体の小数第2位を四捨五入する
    @param COMPLEX型の構造体
    @return 小数点第一位までの四捨五入後のCOMPLEX型の構造体
*/
COMPLEX rounder_2(COMPLEX);

/*
    @brief COMPLEX型の構造体の配列の小数第2位を四捨五入する
    @param COMPLEX型の構造体の配列
    @param 配列の要素数
    @return 小数点第一位までの四捨五入後のCOMPLEX型の構造体の配列
*/
COMPLEX *rounder_array_2(COMPLEX *, int);

/*
    @brief double型の構造体の小数第1位を四捨五入する
    @param double型の構造体
    @param 配列の要素数
    @return 小数点第一位までの四捨五入後のdouble型の構造体
*/
double *rounder_double_array_1(double *, int);


/*
    @brief double型の構造体の小数第2位を四捨五入する
    @param double型の構造体
    @param 配列の要素数
    @return 小数点第一位までの四捨五入後のdouble型の構造体
*/
double *rounder_double_array_2(double *, int);

/*
    @brief メイン周波数を計算する
    @param COMPLEX型の信号
    @param 配列の要素数
    @param サンプリング周波数
    @return メイン周波数
*/
double return_Main_Frequency(COMPLEX *, int, double);

/*
    @brief ハイパスフィルタ
    @param COMPLEX型の信号
    @param カットオフ周波数
    @param 配列の要素数
    @return フィルタ後の信号
*/
COMPLEX* highpass_Filter(COMPLEX *data, int cutoff, int N);



COMPLEX ADD(COMPLEX a, COMPLEX b){
    COMPLEX result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

COMPLEX SUB(COMPLEX a, COMPLEX b){
    COMPLEX result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

COMPLEX MUL(COMPLEX a, COMPLEX b){
    COMPLEX result;
    result.real = a.real * b.real - a.imaginary * b.imaginary;
    result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return result;
}

COMPLEX DIV(COMPLEX a, COMPLEX b){
    COMPLEX result;
    result.real = (a.real * b.real + a.imaginary * b.imaginary) / (b.real * b.real + b.imaginary * b.imaginary);
    result.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / (b.real * b.real + b.imaginary * b.imaginary);
    return result;
}

COMPLEX EULER(double theta){
    COMPLEX result;
    result.real = cos(theta);
    result.imaginary = sin(theta);
    return result;
}


double return_Power(COMPLEX input)
{
    double power = sqrt((input.real * input.real) + (input.imaginary * input.imaginary));
    return power;
}


COMPLEX rounder_1(COMPLEX input)
{
    COMPLEX output;
    output.real = round(input.real);
    output.imaginary = round(input.imaginary);
    return output;
}


COMPLEX *rounder_array_1(COMPLEX *input, int size)
{
    COMPLEX *output = (COMPLEX *)malloc(sizeof(COMPLEX) * size);
    output = init_complex(output, size);
    for(int i = 0; i < size; i++){
        output[i].real = round(input[i].real);
        output[i].imaginary = round(input[i].imaginary);
    }
    return output;
}


COMPLEX rounder_2(COMPLEX input)
{
    COMPLEX output;
    output.real = round(input.real * 10) / 10;
    output.imaginary = round(input.imaginary * 10) / 10;
    return output;
}


COMPLEX *rounder_array_2(COMPLEX *input, int size)
{
    COMPLEX *output = (COMPLEX *)malloc(sizeof(COMPLEX) * size);
    output = init_complex(output, size);
    for(int i = 0; i < size; i++){
        output[i].real = round(input[i].real * 10) / 10;
        output[i].imaginary = round(input[i].imaginary * 10) / 10;
    }
    return output;
}

double *rounder_double_array_1(double *input, int size)
{
    double *output = (double *)malloc(sizeof(double) * size);
    init_double(output, size);
    for(int i = 0; i < size; i++){
        output[i] = round(input[i]);
    }
    return output;
}


double *rounder_double_array_2(double *input, int size)
{
    double *output = (double *)malloc(sizeof(double) * size);
    init_double(output, size);
    for(int i = 0; i < size; i++){
        output[i] = round(input[i] * 10) / 10;
    }
    return output;
}


double return_Main_Frequency(COMPLEX *data, int N, double sampling_rate)
{
    // 最大振幅を持つ周波数成分を見つける
    int max_index = 0;
    double max_power = 0;
    for(int i = 1; i < N / 2; i++){
        // double power = sqrt(data[i].real * data[i].real + data[i].imaginary * data[i].imaginary);
        double power = return_Power(data[i]);
        if (power > max_power) {
            max_power = power;
            max_index = i;
        }
    }

    // 周波数を計算
    double frequency = (double)max_index * sampling_rate / N;
    return frequency;
}


COMPLEX* highpass_Filter(COMPLEX *data, int cutoff, int N)
{
    COMPLEX *output = (COMPLEX *)malloc(sizeof(COMPLEX) * N);
    init_complex(output, N);
    for(int k = 0; k < N; k++){
        if(k < cutoff || k > N - cutoff){
            output[k].real = 0.0;
            output[k].imaginary = 0.0;
        }else{
            output[k] = data[k];
        }
    }
    return output;
}

double return_Max_Power_In_Range(COMPLEX *data, int start_Hz, int end_Hz, int N)
{
    double max_power = 0;
    for(int i = start_Hz; i <= end_Hz; i++){
        double power = return_Power(data[i]);
        if(power > max_power){
            max_power = power;
        }
    }
    return max_power;
}


#endif

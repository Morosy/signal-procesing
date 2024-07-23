#ifndef FILEIO_H
#define FILEIO_H

#include "header.h"

#include "COMPLEX.h"


/*
    @brief ファイルの行数をカウントする
    @param ファイル名
    @return ファイルの行数
*/
int read_file_row(char *);

/*
    @brief ファイルを読み込む
    @param ファイル名
    @return ファイルの中身
*/
double *read_file_double(char *);

/*
    @brief ファイルを読み込む
    @param ファイル名
    @return ファイルの中身
*/
int *read_file_int(char *);

/*
    @brief double型のファイル内容の読み込み
    @param 読み込む配列
    @param ファイル名
*/
void read_file(double *, char *);

void output_int(int *, int, char *);

/*
    @brief COMPLEX型のファイル内容の出力
    @param 出力する配列
    @param 配列の要素数
    @param ファイル名
*/
void output_complex(COMPLEX *, int, char *);

/*
    @brief double型のファイル内容の出力
    @param 出力する配列1
    @param 出力する配列2
    @param 配列の要素数
    @param ファイル名
*/
void output_double_2array(double *, double *, int, char *);


/*
    @brief 改行のないcsvファイルの読み込み
    @param 配列の要素数
    @param ファイル名
    @return ファイルの中身
*/
double *read_csv(int, char *);



int read_file_row(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("file open error\n");
        exit(1);
    }
    double trash;
    int row = 0;
    while(fscanf(fp, "%lf", &trash) != EOF){
        row++;
    }
    fclose(fp);
    return row;
}

int *read_file_int(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("file open error\n");
        exit(1);
    }

    int row = read_file_row(filename);
    int *input = (int *)malloc(sizeof(int) * row);

    for(int i = 0; i < row; i++){
        fscanf(fp, "%d", &input[i]);
    }
    fclose(fp);
    return input;
}


double *read_file_double(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("file open error\n");
        exit(1);
    }

    int row = read_file_row(filename);
    double *input = (double *)malloc(sizeof(double) * row);

    for(int i = 0; i < row; i++){
        fscanf(fp, "%lf", &input[i]);
    }
    fclose(fp);
    return input;
}


void read_file(double *array, char *filename)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("file open error\n");
        exit(1);
    }

    int row = read_file_row(filename);
    for(int i = 0; i < row; i++){
        fscanf(fp, "%lf", &array[i]);
    }
    fclose(fp);
}


void output_int(int *output, int N, char *filename)
{
    FILE *fp = fopen(filename, "w");
    for(int i = 0; i < N; i++){
        fprintf(fp, "%d\n", output[i]);
    }
    fclose(fp);
}

void output_complex(COMPLEX *output, int size, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "w");
    fprintf(fp, "real, imaginary\n");
    for(int i = 0; i < size; i++){
        fprintf(fp, "%.1lf, %.1lf\n", output[i].real, output[i].imaginary);
    }
    fclose(fp);
}

void output_double(double *output, int row, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "w");
    for(int i = 0; i < row; i++){
        fprintf(fp, "%lf\n", output[i]);
    }
    fclose(fp);
}


void output_double_2array(double *output1, double *output2, int row, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "w");
    for(int i = 0; i < row; i++){
        fprintf(fp, "%.1lf, %.1lf\n", output1[i], output2[i]);
    }
    fclose(fp);
}


double *read_csv(int N, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("File open error\n");
        exit(1);
    }

    double *data = (double *)malloc(sizeof(double) * N);
    if(data == NULL){
        printf("Memory allocation error\n");
        exit(1);
    }

    for(int i = 0; i < N; i++){
        fscanf(fp, "%lf,", &data[i]);
    }

    fclose(fp);
    return data;
}


#endif

#ifndef FILEIO_2D_H
#define FILEIO_2D_H

#include "header.h"
#include "complex.h"

/*
    @brief 2次元配列のファイル内容の読み込み
    @param X
    @param Y
    @param ファイル名
    @return ファイルの中身

*/
double **read_file_2D(int, int, char *);


/*
    @brief 2次元配列のファイル内容の出力
    @param 出力する配列
    @param X
    @param Y
    @param ファイル名
*/
void output_double_2D(double **, int, int, char *);


/*
    @brief 2次元配列のファイル内容の読み込み
    @param X
    @param Y
    @param ファイル名
    @return ファイルの中身
*/
void output_complex_2D(COMPLEX **, int, int, char *);



double **read_file_2D(int X, int Y, char *filename)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("File open error\n");
        exit(1);
    }

    double **input = (double **)malloc(sizeof(double) * X);
    for(int i = 0; i < X; i++){
        input[i] = (double *)malloc(sizeof(double) * Y);
    }

    for(int y = 0; y < Y; y++){
        for(int x = 0; x < (X - 1); x++){
            if(fscanf(fp, "%lf,", &input[x][y]) != 1){
                printf("Failed to read data at (%d, %d)\n", x, y);
                exit(1);
            }
        }
        if(fscanf(fp, "%lf\n", &input[X - 1][y]) != 1){
            printf("Failed to read data at (%d, %d)\n", (X - 1), y);
            exit(1);
        }
    }

    return input;
}


void output_double_2D(double **output, int X, int Y, char *filename)
{
    FILE *fp = fopen(filename, "w");
    if(fp == NULL){
        printf("file open error in 'fprint_2D_double'\n");
        exit(1);
    }

    for(int y = 0; y < Y; y++){
        for(int x = 0; x < (X - 1); x++){
            fprintf(fp, "%.1lf,", output[x][y]);
        }
        fprintf(fp, "%.1lf\n", output[X - 1][y]);
    }

    fclose(fp);
}


void output_complex_2D(COMPLEX **output, int X, int Y, char *filename)
{
    FILE *fp = fopen(filename, "w");
    if(fp == NULL){
        printf("file open error in 'fprint_2D_COMPLEX'\n");
        exit(1);
    }

    for(int y = 0; y < Y; y++){
        for(int x = 0; x < (X - 1); x++){
            fprintf(fp, "%.1lf + j * %.1lf, ", output[x][y].real, output[x][y].imaginary);
        }
        fprintf(fp, "%.1lf + j * %.1lf\n", output[X - 1][y].real, output[X - 1][y].imaginary);
    }

    fclose(fp);
}

#endif

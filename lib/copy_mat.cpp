#include"header.h"

void copy_matrix(double **mat1, double **mat2, int row, int col)
{
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++) mat1[i][j]=mat2[i][j];
    }
}

#include "header.h"

void subtract_matrix(double **mat1, double **mat2, double **subtract_mat, int r, int c)
{
    for(int i=0;i<r; i++){
        for(int j=0;j<c;j++){
            subtract_mat[j][i]= mat1[i][j] - mat2[i][j];
        }
    }
}

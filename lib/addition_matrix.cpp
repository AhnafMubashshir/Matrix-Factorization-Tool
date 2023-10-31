#include "header.h"

void add_matrix(double **mat1, double **mat2, double **add_mat, int r, int c)
{
    for(int i=0;i<r; i++){
        for(int j=0;j<c;j++){
            add_mat[i][j]= mat1[i][j] + mat2[i][j];
        }
    }
}

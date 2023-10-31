#include "header.h"

void make_abs_mat(double **mat, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            mat[i][j]=fabs(mat[i][j]);
        }
    }
}

#include<bits/stdc++.h>
#include "header.h"
using namespace std;

void matrix_normalizer(double **mat, int row, int col)
{
    double SD=sd(mat, row, col);

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat[i][j]/=SD;
        }
    }
}

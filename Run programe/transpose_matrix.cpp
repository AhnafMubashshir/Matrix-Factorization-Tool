#include<bits/stdc++.h>
#include "header.h"
using namespace std;

//Transpose Matrix
void transpose_matrix(double **mat, double **transpose_mat, int r, int c)
{
    for(int i=0;i<r; i++){
        for(int j=0;j<c;j++){
            transpose_mat[j][i]=mat[i][j];
        }
    }
}

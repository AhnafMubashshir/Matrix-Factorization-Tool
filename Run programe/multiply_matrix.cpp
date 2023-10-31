#include<bits/stdc++.h>
#include "header.h"
using namespace std;

//Multiplying matrices
void multiply_matrix(double **mat1, double **mat2, double **res, int r1, int c, int c2)
{
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            res[i][j]=0;
        }
    }

    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            for(int k=0; k<c; k++){
                res[i][j]+=(mat1[i][k]*mat2[k][j]);
            }
        }
    }
}

#include<bits/stdc++.h>
#include "header.h"
using namespace std;

double error(double **mat, double **mat1, double **mat2, int r1, int c, int c2)
{
    double** result= new double*[r1];
    for(int i=0; i<c2; i++) result[i]= new double[c2];

    multiply_matrix(mat1, mat2, result, r1, c, c2);

    double er=0;

    for(int i=0;i<r1; i++){
        for(int j=0;j<c2;j++){
            er+= pow((mat[i][j] - result[i][j]),2);
        }
    }

    delete[] result;

    return sqrt(er);
}

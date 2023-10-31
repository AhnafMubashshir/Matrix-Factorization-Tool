#include<bits/stdc++.h>
#include "header.h"
using namespace std;

void sub_matrix_initializer(double **mat, double **sub_mat, int r, int c, int r1, int c1)
{
    int k=0, l=0;

    for(int i=0;i<r;i++){
        if(i==r1) continue;
        for(int j=0;j<c;j++){
            if(j!=c1){
                sub_mat[k][l]=mat[i][j];
                l++;
            }
        }
        k++, l=0;
    }
//    print_matrix(sub_mat, r-1, c-1);
}

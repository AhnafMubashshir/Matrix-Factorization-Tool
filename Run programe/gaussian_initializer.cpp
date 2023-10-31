#include<bits/stdc++.h>
#include "header.h"
using namespace std;

void gaussian_initializer(double **mat, int row, int col)
{
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat[i][j]=random_number();
        }
    }
}

#include<bits/stdc++.h>
#include "header.h"

void print_matrix(double **mat, int row, int col)
{
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

#include "header.h"

void hadamard(double **mat, int row, int col)
{

    int nRow=1, nCol=1, HrowCol;

    while(nRow<row){
        nRow*=2;
    }
    while(nCol<col){
        nCol*=2;
    }
    if(nRow>nCol) HrowCol= nRow;
    else HrowCol=nCol;


    double** H= new double*[HrowCol];
        for(int i=0; i<HrowCol; i++) H[i]= new double[HrowCol];


    H[0][0]=1;

    int i1=1;

    while(i1<HrowCol){
        for(int i2=0; i2<i1; i2++){
            for(int i3=0; i3<i1; i3++){
                H[i2+i1][i3]= H[i2][i3];
                H[i2][i3+i1]= H[i2][i3];
                H[i2+i1][i3+i1]= -H[i2][i3];
            }
        }
        i1+=i1;
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            mat[i][j]=H[i][j];
        }
    }

    delete[] H;
}

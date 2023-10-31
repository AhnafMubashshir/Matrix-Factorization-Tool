#include "header.h"

//Inverse matrix
double inverse_matrix(double **mat, double **inv_mat, int r, int c)
{
    int i,j, sign=1;
    double det;

    double** sub_mat= new double*[r];
    for(int i=0; i<r; i++) sub_mat[i]= new double[c];

    double** Adj_mat= new double*[r];
    for(int i=0; i<r; i++) Adj_mat[i]= new double[c];

    double** t_Adj_mat= new double*[c];
    for(int i=0; i<c; i++) t_Adj_mat[i]= new double[r];

    double** temp= new double*[c];
    for(int i=0; i<c; i++) temp[i]= new double[r];

    double** temp1= new double*[c];
    for(int i=0; i<c; i++) temp1[i]= new double[c];

    double** temp2= new double*[c];
    for(int i=0; i<c; i++) temp2[i]= new double[r];

    //using pseudo inverse
    transpose_matrix(mat, temp, r, c); //temp is the conjugated transpose matrix
    multiply_matrix(temp, mat, temp1, c, r, c);

    det=determenent(temp1, c, c);

    if(det==0) return det;

    //adjacence matrix
    if(c==2){
        t_Adj_mat[0][0]=temp1[1][1];
        t_Adj_mat[1][1]=temp1[0][0];
        t_Adj_mat[0][1]=-temp1[0][1];
        t_Adj_mat[1][0]=-temp1[1][0];
    }
    else{
        for(i=0;i<c;i++){
            for(j=0;j<c;j++){
                sub_matrix_initializer(temp1, sub_mat, c, c, i, j);
                Adj_mat[i][j]=(sign*determenent(sub_mat, c-1, c-1));
                sign=-sign;
            }
        }
        transpose_matrix(Adj_mat, t_Adj_mat, c, c);
    }

    for(i=0;i<c;i++){
        for(j=0;j<c;j++){
            t_Adj_mat[i][j]/=det;
        }
    }

    multiply_matrix(t_Adj_mat, temp, temp2, c, c, r);

    //inversed matrix
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            inv_mat[i][j]=temp2[i][j];
        }
    }

    delete[] sub_mat;
    delete[] Adj_mat;
    delete[] t_Adj_mat;
    delete[] temp;
    delete[] temp1;
    delete[] temp2;
return 1;
}

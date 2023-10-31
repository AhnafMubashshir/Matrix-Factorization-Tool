#include<bits/stdc++.h>
#include "header.h"

void multiplicative_update(double **mat, double **mat1, double **mat2, int row, int col, int k)
{
    double err=error(mat , mat1, mat2, row, k, col);
    int cnt;

    for(int i=2;;i++){
        if((err<=-0.05 || err>=0.05)){
            if(i%2==0){
                double** temp= new double*[k];
                for(int i=0; i<k; i++) temp[i]= new double[row];

                double** temp1= new double*[k];
                for(int i=0; i<k; i++) temp1[i]= new double[col];

                double** temp2= new double*[k];
                for(int i=0; i<k; i++) temp2[i]= new double[k];

                double** temp3= new double*[k];
                for(int i=0; i<k; i++) temp3[i]= new double[col];

                double** temp4= new double*[k];
                for(int i=0; i<k; i++) temp4[i]= new double[col];

                double** temp5= new double*[k];
                for(int i=0; i<k; i++) temp5[i]= new double[col];



                transpose_matrix(mat1, temp, row, k); //keeps the transpose matrix of matrix-1 in temp(k*row)
                multiply_matrix(temp, mat, temp1, k, row, col); //keeps the multiplied matrix of temp & matrix in temp1(k*col)


                multiply_matrix(temp, mat1, temp2, k, row, k); //keeps the multiplied matrix in temp2(k*k)
                multiply_matrix(temp2, mat2, temp3, k, k, col); //keeps the multiplied matrix in temp3(k*col)

                elementwise_devide_matrix(temp1, temp3, temp4, k, col);
                elementwise_multiply_matrix(mat2, temp4, temp5, k, col);

                err= error(mat , mat1, temp5, row, k, col);

                copy_matrix(mat2, temp5, k, col);

                delete[] temp;
                delete[] temp1;
                delete[] temp2;
                delete[] temp3;
                delete[] temp4;
                delete[] temp5;

                //cout<<"----------------Changing mat-2----------------"<<endl;
            }
            else{
                double** temp= new double*[col];
                for(int i=0; i<col; i++) temp[i]= new double[k];

                double** temp1= new double*[row];
                for(int i=0; i<row; i++) temp1[i]= new double[k];

                double** temp2= new double*[k];
                for(int i=0; i<k; i++) temp2[i]= new double[k];

                double** temp3= new double*[row];
                for(int i=0; i<row; i++) temp3[i]= new double[k];

                double** temp4= new double*[row];
                for(int i=0; i<row; i++) temp4[i]= new double[k];

                double** temp5= new double*[row];
                for(int i=0; i<row; i++) temp5[i]= new double[k];


                transpose_matrix(mat2, temp, k, col); //keeps the transpose matrix of matrix-1 in temp(col*k)
                multiply_matrix(mat, temp, temp1, row, col, k); //keeps the multiplied matrix of temp & matrix in temp1(row*k)

                multiply_matrix(mat2, temp, temp2, k, col, k); //keeps the multiplied matrix in temp2(k*k)
                multiply_matrix(mat1, temp2, temp3, row, k, k); //keeps the multiplied matrix in temp3(row*k)

                elementwise_devide_matrix(temp1, temp3, temp4, row, k);
                elementwise_multiply_matrix(mat1, temp4, temp5, row, k);


                err= error(mat , temp5, mat2, row, k, col);

                copy_matrix(mat1, temp5, row, k);
                delete[] temp;
                delete[] temp1;
                delete[] temp2;
                delete[] temp3;
                delete[] temp4;
                delete[] temp5;

                //cout<<"----------------Changing mat-1----------------"<<endl;
            }
            cnt++;
        }
        else break;
    }

    cout<<endl;

    cout<<"--------------------------------------------------------------------------------------------------"<<endl<<endl;

    cout<<"Factorized matrices: "<<endl<<endl;

    cout<<"Matrix-1:"<<endl;
    print_matrix(mat1, row, k);
    cout<<endl;

    cout<<"Matrix-2:"<<endl;
    print_matrix(mat2, k, col);
    cout<<endl;

//    cout<<"Total iterations: "<<cnt<<" "<<endl;
//    cout<<"Error: "<<(err*100)<<"%"<<endl;
}

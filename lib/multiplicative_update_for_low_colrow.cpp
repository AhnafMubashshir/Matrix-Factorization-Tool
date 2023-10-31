#include "header.h"

void multiplicative_update_for_low_colrow(double **mat, double **mat1, double **mat2, int row, int col, int k)
{
    double new_err=error(mat , mat1, mat2, row, k, col), old_err= INFINITE;

    for(int i=2;;i++){
        if((new_err<=epsilon_MU || new_err>=epsilon_MU)){
            if(i%2==0){
                double** temp= new double*[k];
                for(int i=0; i<k; i++) temp[i]= new double[row];
//                cout<<"created temp"<<endl;

                double** temp1= new double*[k];
                for(int i=0; i<k; i++) temp1[i]= new double[col];
//                cout<<"created temp 1"<<endl;

                double** temp2= new double*[k];
                for(int i=0; i<k; i++) temp2[i]= new double[k];
//                cout<<"created temp 2"<<endl;

                double** temp3= new double*[k];
                for(int i=0; i<k; i++) temp3[i]= new double[col];
//                cout<<"created temp 3"<<endl;

                double** temp4= new double*[k];
                for(int i=0; i<k; i++) temp4[i]= new double[col];
//                cout<<"created temp 4"<<endl;

                double** temp5= new double*[k];
                for(int i=0; i<k; i++) temp5[i]= new double[col];
//                cout<<"created temp 5"<<endl;



                transpose_matrix(mat1, temp, row, k); //keeps the transpose matrix of matrix-1 in temp(k*row)
//                cout<<"matrix is transposed."<<endl;
                multiply_matrix(temp, mat, temp1, k, row, col); //keeps the multiplied matrix of temp & matrix in temp1(k*col)
//                cout<<"matrices are multplied."<<endl;


                multiply_matrix(temp, mat1, temp2, k, row, k); //keeps the multiplied matrix in temp2(k*k)
//                cout<<"Matrices are multiplied for second time."<<endl;

                multiply_matrix(temp2, mat2, temp3, k, k, col); //keeps the multiplied matrix in temp3(k*col)
//                cout<<"Matrices are multiplied for 3rd time."<<endl;

                elementwise_devide_matrix(temp1, temp3, temp4, k, col);
//                cout<<"elementwise divide."<<endl;
                elementwise_multiply_matrix(mat2, temp4, temp5, k, col);
//                cout<<"element wise multiply."<<endl;

//                print_matrix(temp5, k, col);
//                print_matrix(mat1, row, k);

                new_err= error(mat , mat1, temp5, row, k, col);
//                cout<<"New error: "<<new_err<<endl;

                if(fabs(old_err-new_err)<epsilon_Err_Check) break;
                else if(old_err==new_err) break;

                copy_matrix(mat2, temp5, k, col);
//                cout<<"Matrix is copied"<<endl;

                old_err= new_err;

//                if(isnan(new_err)) break;

                delete[] temp;
                delete[] temp1;
                delete[] temp2;
                delete[] temp3;
                delete[] temp4;
                delete[] temp5;

//                cout<<"----------------Changed mat-2----------------error: "<<new_err<<endl;

//                cout<<"Matrix-1:"<<endl;
//                print_matrix(mat1, row, k);
//                cout<<endl;
//
//                cout<<"Matrix-2:"<<endl;
//                print_matrix(mat2, k, col);
//                cout<<endl;

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


                new_err= error(mat , temp5, mat2, row, k, col);

                if(fabs(old_err-new_err)<epsilon_Err_Check) break;
                else if(old_err==new_err) break;

                copy_matrix(mat1, temp5, row, k);

                old_err=new_err;

                delete[] temp;
                delete[] temp1;
                delete[] temp2;
                delete[] temp3;
                delete[] temp4;
                delete[] temp5;

//                cout<<"----------------Changed mat-1----------------error: "<<new_err<<endl;

//                cout<<"Factorized matrices: "<<endl<<endl;
//
//                cout<<"Matrix-1:"<<endl;
//                print_matrix(mat1, row, k);
//                cout<<endl;
//
//                cout<<"Matrix-2:"<<endl;
//                print_matrix(mat2, k, col);
//                cout<<endl;

            }
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
    cout<<"Error: "<<new_err<<endl;
}


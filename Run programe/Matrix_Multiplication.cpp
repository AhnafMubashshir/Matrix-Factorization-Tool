#include "header.h"

void Matrix_Multiplication()
{
    cout<<"#Matrix Multiplication"<<endl<<endl;

    int row1,col1,row2,col2;

    cout<<"Enter 1st matrix row & column: ";
    cin>>row1>>col1;
    cout<<endl;

    cout<<"Enter 2nd matrix row & column: ";
    cin>>row2>>col2;
    cout<<endl;

    if(col1!=row2){
        cout<<"::Wrong input (Column of 1st matrix and Row of 2nd matrix must have to be same)."<<endl<<endl;
        return;
    }

    //Taking 1st matrix input
    double** matrix1=new double*[row1];
    for(int i=0; i<row1; i++) matrix1[i]= new double[col1];

    cout<<"Enter 1st matrix: "<<endl;
    for(int i=0; i<row1; i++){
        for(int j=0; j<col1; j++){
            cin>>matrix1[i][j];
        }
    }
    cout<<endl;



    //Takin 2nd matrix input
    double** matrix2=new double*[row2];
    for(int i=0; i<row2; i++) matrix2[i]= new double[col2];

    cout<<"Enter 2nd matrix: "<<endl;
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            cin>>matrix2[i][j];
        }
    }
    cout<<endl;


    double** result=new double*[row1];
    for(int i=0; i<row1; i++) result[i]= new double[col2];


    multiply_matrix(matrix1, matrix2, result, row1, col1, col2);

    cout<<"The multiplied matrix: "<<endl;
    print_matrix(result, row1, col2);

    delete[] matrix1;
    delete[] matrix2;
    delete[] result;
}

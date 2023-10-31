#include "header.h"

void Matrix_Addition(){
    cout<<"#Matrix Addition"<<endl<<endl;

    int row, col;

    cout<<"Enter row & column of the matrices: ";
    cin>>row>>col;
    cout<<endl;


    //Taking 1st matrix input
    double** matrix1=new double*[row];
    for(int i=0; i<row; i++) matrix1[i]= new double[col];

    cout<<"Enter 1st matrix: "<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>matrix1[i][j];
        }
    }
    cout<<endl;



    //Takin 2nd matrix input
    double** matrix2=new double*[row];
    for(int i=0; i<row; i++) matrix2[i]= new double[col];

    cout<<"Enter 2nd matrix: "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix2[i][j];
        }
    }
    cout<<endl;


    double** result=new double*[row];
    for(int i=0; i<row; i++) result[i]= new double[col];

    add_matrix(matrix1, matrix2, result, row, col);

    cout<<"The added matrix is: "<<endl;
    print_matrix(result, row, col);

    delete[] matrix1;
    delete[] matrix2;
    delete[] result;
}

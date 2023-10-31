#include "header.h"

void Determinant()
{
    cout<<"#Determinant"<<endl<<endl;
    int row, col;

    cout<<"Enter row & column of the matrix: ";
    cin>>row>>col;
    cout<<endl;


    //Taking 1st matrix input
    double** matrix=new double*[row];
    for(int i=0; i<row; i++) matrix[i]= new double[col];

    cout<<"Enter The matrix: "<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>matrix[i][j];
        }
    }
    cout<<endl;
    double det;
    det= determenent(matrix, row, col);

    cout<<"The determinant is: "<<det<<endl;

    delete[] matrix;
}

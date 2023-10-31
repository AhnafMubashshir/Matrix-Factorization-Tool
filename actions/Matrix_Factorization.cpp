#include "header.h"

int Matrix_Factorization()
{
    cout<<"#Matrix Factorization"<<endl<<endl;

    int row,col,colrow;
    int range;
    string str;
//    double minn= INFINITE;

    //dimension input
    cout<<"Enter row & column of the matrix: ";
    cin>>str;
    if(str=="exit") return 0;
    else if(str=="back") return 1;
    cin>>str;
    if(str=="exit") return 0;
    else if(str=="back") return 1;
    row= stoi(str);
    col= stoi(str);
    cout<<endl;


    double** matrix=new double*[row];
    for(int i=0; i<row; i++) matrix[i]= new double[col];

    cout<<"Enter new matrix row/column: ";
    cin>>str;
    if(str=="exit") return 0;
    else if(str=="back") return 1;
    colrow= stoi(str);
    cout<<endl;

    cout<<"How you want your input?"<<endl;
    cout<<"Press '1' for user input."<<endl;
    cout<<"Press '2' for random input."<<endl<<endl;
    cout<<"Choose an option: ";

    while(1){
        cin>>str;

        if(str=="1"){

            cout<<endl<<"Enter the matrix: "<<endl;
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    cin>>str;
                    if(str=="exit") return 0;
                    else if(str=="back") return 1;
                    matrix[i][j]=stoi(str);
                }
            }
            cout<<endl;

            break;
        }
        else if(str=="2"){

            cout<<endl<<"Enter the last range of your input: ";
            cin>>str;
            if(str=="exit") return 0;
            else if(str=="back") return 1;
            range= stoi(str);
            cout<<endl;

            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    double input= randfrom(1, range);
                    matrix[i][j]= abs(input);
                }
            }

            break;
        }
        else if(str=="back") return 1;
        else if(str=="exit") return 0;
        else{
            cout<<"Wrong choice! Please try again: ";
            continue;
        }
    }

    double** matrix1=new double*[row];
    double** matrix2=new double*[colrow];

    for(int i=0; i<row; i++) matrix1[i]= new double[colrow];
    for(int i=0; i<colrow; i++) matrix2[i]= new double[col];


    //normalizing initial matrix
    matrix_normalizer(matrix, row, col);



    hadamard(matrix1, row, colrow);
    make_abs_mat(matrix1, row, colrow);

    hadamard(matrix2, colrow, col);
    make_abs_mat(matrix2, colrow, col);

    cout<<"Reduced Matrices are initialized."<<endl<<endl;

    multiplicative_update_for_low_colrow(matrix, matrix1, matrix2, row, col, colrow);



    delete[] matrix;
    delete[] matrix1;
    delete[] matrix2;

    return 2;
}

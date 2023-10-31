#include "header.h"

int Matrix_Subtraction()
{
    cout<<"#Matrix Subtraction"<<endl<<endl;

    int row, col, range;
    string str;

    //dimension input
    cout<<"Enter row & column of the matrix: ";
    cin>>str;
    if(str=="exit") return 0;
    else if(str=="back") return 1;
    row= stoi(str);
    cin>>str;
    if(str=="exit") return 0;
    else if(str=="back") return 1;
    col= stoi(str);
    cout<<endl;


    //Taking 1st matrix input
    double** matrix1=new double*[row];
    for(int i=0; i<row; i++) matrix1[i]= new double[col];

     cout<<"How you want your matrix-1 input?"<<endl;
    cout<<"Press '1' for user input."<<endl;
    cout<<"Press '2' for random input."<<endl<<endl;
    cout<<"Choose an option: ";

    while(1){
        cin>>str;

        if(str=="1"){

            cout<<endl<<"Enter matrix-1: "<<endl;
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    cin>>str;
                    if(str=="exit") return 0;
                    else if(str=="back") return 1;
                    matrix1[i][j]=stoi(str);
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
                    double input= rand()%range;
                    matrix1[i][j]= abs(input);
                }
            }
//            cout<<"The Matrix-1 is:"<<endl;
//            print_matrix(matrix1, row, col);

            break;
        }
        else if(str=="back") return 1;
        else if(str=="exit") return 0;
        else{
            cout<<"Wrong choice! Please try again: ";
            continue;
        }
        break;
    }


    cout<<"How you want your matrix-2 input?"<<endl;
    cout<<"Press '1' for user input."<<endl;
    cout<<"Press '2' for random input."<<endl<<endl;
    cout<<"Choose an option: ";

    //Takin 2nd matrix input
    double** matrix2=new double*[row];
    for(int i=0; i<row; i++) matrix2[i]= new double[col];

    while(1){
        cin>>str;

        if(str=="1"){

            cout<<endl<<"Enter matrix-2: "<<endl;
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    cin>>str;
                    if(str=="exit") return 0;
                    else if(str=="back") return 1;
                    matrix2[i][j]=stoi(str);
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
                    double input= rand()%range;
                    matrix2[i][j]= abs(input);
                }
            }
//            cout<<"The Matrix-2 is:"<<endl;
//            print_matrix(matrix2, row, col);

            break;
        }
        else if(str=="back") return 1;
        else if(str=="exit") return 0;
        else{
            cout<<"Wrong choice! Please try again: ";
            continue;
        }
    }


    double** result=new double*[row];
    for(int i=0; i<row; i++) result[i]= new double[col];

    subtract_matrix(matrix1, matrix2, result, row, col);

    cout<<"The subtracted matrix is: "<<endl;
    print_matrix(result, row, col);

    delete[] matrix1;
    delete[] matrix2;
    delete[] result;

    return 2;
}

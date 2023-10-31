#include "header.h"

int Determinant()
{
    cout<<"#Determinant"<<endl<<endl;
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


    //Taking matrix input
    double** matrix=new double*[row];
    for(int i=0; i<row; i++) matrix[i]= new double[col];

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
                    double input= rand()%range;
                    matrix[i][j]= abs(input);
                }
            }
//            cout<<"The Matrix is:"<<endl;
//            print_matrix(matrix, row, col);

            break;
        }
        else if(str=="back") return 1;
        else if(str=="exit") return 0;
        else{
            cout<<"Wrong choice! Please try again: ";
            continue;
        }
    }

    double det;
    det= determenent(matrix, row, col);

    cout<<"The determinant is: "<<det<<endl;

    delete[] matrix;

    return 2;
}

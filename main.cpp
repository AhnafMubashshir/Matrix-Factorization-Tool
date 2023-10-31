#include "header.h"

int main()
{
    string ch;
    int opt;

    while(1){
        cout<<"--------------------------------------------------Matrix Operations--------------------------------------------------"<<endl<<endl;
        cout<<"Options: (Type 'exit' anywhere in the programe to terminate & 'back' for previous window.)"<<endl;
        cout<<"Press '1' for Matrix Addition"<<endl;
        cout<<"Press '2' for Matrix Subtraction."<<endl;
        cout<<"Press '3' for Matrix Multiplication."<<endl;
        cout<<"Press '4' for Inverse Matrix."<<endl;
        cout<<"Press '5' for Transpose Matrix"<<endl;
        cout<<"Press '6' for Determinant of Matrix."<<endl;
        cout<<"Press '7' for Matrix Factorization."<<endl;
        cout<<"Press '8' for Linear Equation Solving."<<endl<<endl;
        cout<<"Choose an option or type 'exit' to terminate: ";

        while(1){
            cin>>ch;
            cout<<endl;

            if(ch=="exit"){
                cout<<endl<<"--------------------------------------------------Thank You!--------------------------------------------------"<<endl<<endl;
                return 0;
            }

            if(ch=="1"){
                opt= Matrix_Addition();
                break;
            }
            else if(ch=="2"){
                opt= Matrix_Subtraction();
                break;
            }
            else if(ch=="3"){
                opt=Matrix_Multiplication();
                break;
            }
            else if(ch=="4"){
                opt =Inverse_Matrix();
                break;
            }
            else if(ch=="5"){
                opt= Transpose_Matrix();
                break;
            }
            else if(ch=="6"){
                opt= Determinant();
                break;
            }
            else if(ch=="7"){
                opt= Matrix_Factorization();
                break;
            }
            else if(ch=="8"){
                opt= Solve_Linear_Equation();
                break;
            }
            else{
                cout<<"Wrong choice! Please try again: ";
                continue;
            }
        }
        cout<<endl;

        if(opt==0) break;
        if(opt==1) continue;

        cout<<"Do you wish to continue? press 'Y' for Yes | 'N' for No | 'exit' to terminate: ";
        while(1){
            cin>>ch;
            if(ch=="N" || ch=="Y" || ch=="n" || ch=="y" || ch=="exit") break;
            else cout<<"Wrong choice! Please try again: ";
        }
        cout<<endl<<endl;
        if(ch=="n" || ch=="N" || ch=="exit") break;
    }
    cout<<endl<<"--------------------------------------------------Thank You!--------------------------------------------------"<<endl<<endl;
}

#include "header.h"
using namespace std;

int main()
{
    int choice;
    char ch;

    cout<<"Options: "<<endl;
    cout<<"Press '1' for Matrix Addition"<<endl;
    cout<<"Press '2' for Matrix Subtraction."<<endl;
    cout<<"Press '3' for Matrix Multiplication."<<endl;
    cout<<"Press '4' for Inverse Matrix."<<endl;
    cout<<"Press '5' for Transpose Matrix"<<endl;
    cout<<"Press '6' for Determinant of Matrix."<<endl;
    cout<<"Press '7' for Matrix Factorization."<<endl;
    cout<<endl;

    while(1){
        cout<<"Choose an option: ";
        cin>>choice;
        cout<<endl;

        if(choice==1) Matrix_Addition();
        else if(choice==2) Matrix_Subtraction();
        else if(choice==3) Matrix_Multiplication();
        else if(choice==4) Inverse_Matrix();
        else if(choice==5) Transpose_Matrix();
        else if(choice==6) Determinant();
        else if(choice==7) Matrix_Factorization();

        cout<<endl;

        cout<<"Do you wish to continue? press 'Y' for Yes : 'N' for No: ";
        while(1){
            cin>>ch;
            if(ch=='N' || ch=='Y') break;
            else cout<<"Wrong choice! Please try again: ";
        }
        cout<<endl<<endl;
        if(ch=='N') break;
    }
    cout<<endl<<"--------------------------------------------------Thank You!--------------------------------------------------"<<endl<<endl;
}

#include "header.h"

int Matrix_Multiplication()
{
    cout<<"#Multiplication of Chain Matrix"<<endl<<endl;
    int Hrow, Hcol, row1, col1, row2, col2, tot, range;
    string str, choice;

    cout<<"Enter number of matrices you want to multiply: ";
    cin>>str;
    if(str=="exit") return 0;
    else if(str=="back") return 1;
    tot= stoi(str);
    cout<<endl;

    //dimension input
    cout<<"Enter the highest row and column in your chained matrix: ";
    cin>>str;
    if(str=="exit") return 0;
    else if(str=="back") return 1;
    Hrow= stoi(str);
    cin>>str;
    if(str=="exit") return 0;
    else if(str=="back") return 1;
    Hcol= stoi(str);
    cout<<endl;


    double** matrix1=new double*[Hrow];
    for(int i=0; i<Hrow; i++) matrix1[i]= new double[Hcol];

    double** matrix2=new double*[Hrow];
    for(int i=0; i<Hrow; i++) matrix2[i]= new double[Hcol];

    double** result=new double*[Hrow];
    for(int i=0; i<Hrow; i++) result[i]= new double[Hcol];


    //first mat dimension input
    while(1){
        cout<<"Enter 1st matrix row & column: ";
        cin>>str;
        if(str=="exit") return 0;
        else if(str=="back") return 1;
        row1= stoi(str);
        cin>>str;
        if(str=="exit") return 0;
        else if(str=="back") return 1;
        col1= stoi(str);
        cout<<endl;

        //second mat dimension input
        cout<<"Enter 2nd matrix row & column: ";
        cin>>str;
        if(str=="exit") return 0;
        else if(str=="back") return 1;
        row2= stoi(str);
        cin>>str;
        if(str=="exit") return 0;
        else if(str=="back") return 1;
        col2= stoi(str);
        cout<<endl;

        if(col1!=row2){
            cout<<"::Wrong input (Column of 1st matrix and Row of 2nd matrix must have to be same)."<<endl<<endl;
            continue;
        }

        break;
    }


    //Mat-1 input
    cout<<"How you want your matrix-1 input?"<<endl;
    cout<<"Press '1' for user input."<<endl;
    cout<<"Press '2' for random input."<<endl<<endl;
    cout<<"Choose an option: ";

    while(1){
        cin>>str;

        if(str=="1"){

            cout<<endl<<"Enter matrix-1: "<<endl;
            for(int i=0;i<row1;i++){
                for(int j=0;j<col1;j++){
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

            for(int i=0; i<row1; i++){
                for(int j=0; j<col1; j++){
                    double input= rand()%range;
                    matrix1[i][j]= abs(input);
                }
            }
//            cout<<"The Matrix-1 is:"<<endl;
//            print_matrix(matrix1, row1, col1);

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


    //Mat-2 input
    cout<<"How you want your matrix-2 input?"<<endl;
    cout<<"Press '1' for user input."<<endl;
    cout<<"Press '2' for random input."<<endl<<endl;
    cout<<"Choose an option: ";

    while(1){
        cin>>str;

        if(str=="1"){

            cout<<endl<<"Enter matrix-2: "<<endl;
            for(int i=0;i<row2;i++){
                for(int j=0;j<col2;j++){
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

            for(int i=0; i<row2; i++){
                for(int j=0; j<col2; j++){
                    double input= rand()%range;
                    matrix2[i][j]= abs(input);
                }
            }
//            cout<<"The Matrix-2 is:"<<endl;
//            print_matrix(matrix2, row2, col2);

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

    //Multiplying the matrices
    multiply_matrix(matrix1, matrix2, result, row1, col1, col2);

    tot-=2;


    while(tot--){
        cout<<"Enter another matrix:"<<endl<<endl;

        cout<<"Is it in the front side of the result matrix or back side? Press 'f' for front side else Press 'b': ";

        while(1){
            cin>>choice;

            if(choice=="F" || choice=="f" || choice=="b" || choice=="B") break;
            if(str=="exit") return 0;
            else if(str=="back"){
                delete[] matrix1;
                delete[] matrix2;
                delete[] result;
                return 1;
            }
            else{
                cout<<"::Wrong input. Please try again: ";
                continue;
            }
            break;
        }
        cout<<endl;

        cout<<"The dimension of result matrix is: "<<row1<<"x"<<col2<<endl<<endl;



        //Mat-1 input
        if(choice=="F" || choice=="f"){
            row2=row1;
            copy_matrix(matrix2, result, row2, col2);

            while(1){
                //first mat dimension input
                cout<<"Enter other matrix row & column: ";
                cin>>str;
                if(str=="exit") return 0;
                else if(str=="back") return 1;
                row1= stoi(str);
                cin>>str;
                if(str=="exit") return 0;
                else if(str=="back") return 1;
                col1= stoi(str);
                cout<<endl;

                if(col1!=row2){
                    cout<<"::Wrong input (Column of 1st matrix and Row of 2nd matrix must have to be same)."<<endl<<endl;
                    continue;
                }

                break;
            }

            //Mat-1 input
            cout<<"How you want your matrix-1 input?"<<endl;
            cout<<"Press '1' for user input."<<endl;
            cout<<"Press '2' for random input."<<endl<<endl;
            cout<<"Choose an option: ";

            while(1){
                cin>>str;

                if(str=="1"){

                    cout<<endl<<"Enter matrix-1: "<<endl;
                    for(int i=0;i<row1;i++){
                        for(int j=0;j<col1;j++){
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

                    for(int i=0; i<row1; i++){
                        for(int j=0; j<col1; j++){
                            double input= rand()%range;
                            matrix1[i][j]= abs(input);
                        }
                    }
                    cout<<"The Matrix is:"<<endl;
                    print_matrix(matrix1, row1, col1);

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

            //Multiplying matrices
            multiply_matrix(matrix1, matrix2, result, row1, col1, col2);
        }
        //Mat-2 input
        else{
            col1=col2;

            copy_matrix(matrix1, result, row1, col1);

            while(1){
                //first mat dimension input
                cout<<"Enter other matrix row & column: ";
                cin>>str;
                if(str=="exit") return 0;
                else if(str=="back") return 1;
                row2= stoi(str);
                cin>>str;
                if(str=="exit") return 0;
                else if(str=="back") return 1;
                col2= stoi(str);
                cout<<endl;

                if(col1!=row2){
                    cout<<"::Wrong input (Column of 1st matrix and Row of 2nd matrix must have to be same)."<<endl<<endl;
                    continue;
                }

                break;
            }


            //Mat-2 input
            cout<<"How you want your matrix-2 input?"<<endl;
            cout<<"Press '1' for user input."<<endl;
            cout<<"Press '2' for random input."<<endl<<endl;
            cout<<"Choose an option: ";

            while(1){
                cin>>str;

                if(str=="1"){

                    cout<<endl<<"Enter matrix-1: "<<endl;
                    for(int i=0;i<row2;i++){
                        for(int j=0;j<col2;j++){
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

                    for(int i=0; i<row2; i++){
                        for(int j=0; j<col2; j++){
                            double input= rand()%range;
                            matrix2[i][j]= abs(input);
                        }
                    }
//                    cout<<"The Matrix is:"<<endl;
//                    print_matrix(matrix2, row2, col2);

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

            //Multiplyingmatrices
            multiply_matrix(matrix1, matrix2, result, row1, col1, col2);
        }
    }

    cout<<"Result of the multiplied matrices: "<<endl;
    print_matrix(result, row1, col2);

    delete[] matrix1;
    delete[] matrix2;
    delete[] result;

    return 2;
}

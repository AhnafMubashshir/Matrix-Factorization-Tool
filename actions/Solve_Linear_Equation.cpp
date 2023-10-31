#include"header.h"

int Solve_Linear_Equation(){

    cout<<"#Linear equation solving"<<endl<<endl;

    int variables, range;
    string str;

    cout<<"Enter number of variables: ";
	cin>>str;
    if(str=="exit") return 0;
    else if(str=="back") return 1;
    variables= stoi(str);
	cout<<endl;

	double** co_efficient_mat=new double*[variables];
    for(int i=0; i<variables; i++) co_efficient_mat[i]= new double[variables];

    double* right_hand_side_mat=new double[variables];


    //Left side values
	cout<<"How you want your input?"<<endl;
    cout<<"Press '1' for user input."<<endl;
    cout<<"Press '2' for random input."<<endl<<endl;
    cout<<"Choose an option: ";

    while(1){
        cin>>str;

        if(str=="1"){

            cout<<endl<<"Enter the matrix: "<<endl;
            for(int i=0;i<variables;i++){
                for(int j=0;j<variables;j++){
                    cin>>str;
                    if(str=="exit") return 0;
                    else if(str=="back") return 1;
                    co_efficient_mat[i][j]=stoi(str);
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

            for(int i=0; i<variables; i++){
                for(int j=0; j<variables; j++){
                    double input= rand()%range;
                    co_efficient_mat[i][j]= abs(input);
                }
            }
            cout<<"The Matrix is:"<<endl;
            print_matrix(co_efficient_mat, variables, variables);

            break;
        }
        else if(str=="back") return 1;
        else if(str=="exit") return 0;
        else{
            cout<<"Wrong choice! Please try again: ";
            continue;
        }
    }


	//Right side values
	cout<<"How you want your input?"<<endl;
    cout<<"Press '1' for user input."<<endl;
    cout<<"Press '2' for random input."<<endl<<endl;
    cout<<"Choose an option: ";

    while(1){
        cin>>str;

        if(str=="1"){

            cout<<endl<<"Enter the matrix: "<<endl;
            for(int i=0;i<variables;i++){
                cin>>str;
                if(str=="exit") return 0;
                else if(str=="back") return 1;
                right_hand_side_mat[i]=stoi(str);
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

            for(int i=0; i<variables; i++){
                double input= rand()%range;
                right_hand_side_mat[i]= abs(input);
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


	gauss_seidel(co_efficient_mat, right_hand_side_mat, variables);

	delete[] co_efficient_mat;
	delete[] right_hand_side_mat;

	return 2;
}

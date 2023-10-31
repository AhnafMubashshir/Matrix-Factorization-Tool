#include "header.h"

void gauss_seidel(double **co_efficient_mat, double *right_hand_side_mat, int variables)
{

    //Checking diagonally dominent
    double sum;
    for(int i=0; i<variables; i++){
        sum=0;
        for(int j=0; j<variables; j++){
            if(i!=j) sum+=co_efficient_mat[i][j];
        }
        if(co_efficient_mat[i][i]<=sum){
            cout<<"Co-Efficient Matrix is not diagonally dominant. Can't find answer."<<endl<<endl;
            return;
        }
    }

    double* old_val=new double[variables];
    double* new_val=new double[variables];


    double old_err=100, new_err=0;

	int flag, cnt=0;


	do{
        for(int i=0;i<variables;i++)
		{
			sum=right_hand_side_mat[i];

			for(int j=0;j<variables;j++)
			{
				if(j<i) sum-=co_efficient_mat[i][j]*new_val[j];
				else if(j>i) sum-=co_efficient_mat[i][j]*old_val[j];
			}
			new_val[i]=sum/co_efficient_mat[i][i];
		}


		flag=0;
		for(int i=0;i<variables;i++){
			if(fabs(old_val[i]-new_val[i])>epsilon_Err_Check){
                flag=1;
                if( fabs(old_val[i]-new_val[i])>new_err ) new_err=fabs(old_val[i]-new_val[i]);
			}
		}

		if(fabs(old_err-new_err)<=epsilon_Err_Check) cnt++;
		else cnt=0;

		if(old_err==new_err) flag=0;
		else if(cnt>100) flag=0;

		if(flag==1){
			for(int i=0;i<variables;i++){
				old_val[i]=new_val[i];
			}
		}
        old_err=new_err;
	}while(flag==1);


	cout<<"The Solution is: ";
	for(int i=0;i<variables;i++) printf("%8.5lf ",new_val[i]);
	cout<<endl<<endl;

	delete[] new_val;
	delete[] old_val;
}

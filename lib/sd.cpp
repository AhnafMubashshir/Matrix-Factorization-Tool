#include "header.h"

//Calculating SD of main matrix
double sd(double **mat, int r, int c)
{
    double add=0, avg, sd=0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            add+=(mat[i][j]);
        }
    }

    avg=add/(r*c);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sd+=pow((mat[i][j]-avg), 2);
        }
    }

    sd=sd/(r*c);

    return sqrt(sd);
}

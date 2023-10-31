#include<bits/stdc++.h>
#include "constants.h"
#include "header.h"
using namespace std;

// Generating random number with gaussian rule
double randfrom(double minn, double maxx)
{
    double range = (maxx - minn);
    double div = RAND_MAX / range;
    return minn + (rand() / div);
}
double exponential(){
    double power, x;
    x=randfrom(-8.0,9.0);
    power= ((x-sigma)/miu);
    power=pow((-0.5*power), 2);
    return pow(e, power);
}
double random_number(){
    return initial*exponential();
}

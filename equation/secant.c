#include"equation.h"
#include<stdio.h>
double secant_k(double* f,int len,double a,double b){
    return (fx(f,a,len)-fx(f,b,len))/(a-b);
}

double secant(double* f,int len,double x0,double x1,double esp){
    double x2;
    x2 = x1;
    x1 = x0;
    do{
        x1 = x2;
        x0 = x1;
        x2 = fx(f,x1,len)/secant_k(f,len,x0,x1);
    }while(fabs(x2-x1)>esp);
    return x1;
}

int main(){
    double f[] = {0};
    int len = sizeof(f)/sizeof(double);
    double x0;
    double x1;
    double esp = 1e-3;
    double res = secant(f,len,x0,x1,esp);
    printf("%lf\n",res);
}
#include"equation.h"
#include<stdio.h>
double iteration(Fx f,double init,double eps){
    double x ;
    double xn = init;
    do{
        x = xn;
        xn = f(x);
    }while(fabs(x-xn)>eps);
    return x;
}
// 迭代公式
double f(double x){
    double tmp = 10.0-x*x;
    return sqrt(10.0-x*x*x) / 2;
}

int main(){
    double init =1.5;
    double eps = 1e-3;
    // fx必须是收敛的,至少是局部收敛的
    double res = iteration(f,init,eps);
    printf("%lf\n",res);   
}
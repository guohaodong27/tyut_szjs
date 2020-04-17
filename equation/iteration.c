#include"equation.h"
#include<stdio.h>
double iteration(Fx f,double init,double esp){
    double x ;
    double xn = init;
    do{
        x = xn;
        xn = f(x);
    }while(fabs(x-xn)>esp);
    return x;
}
// 迭代公式
double f(double x){
    return pow(x+1,0.33333);
}

int main(){
    double init =1.5;
    double esp = 1e-4;
    // fx必须是收敛的
    double res = iteration(f,init,esp);
    printf("%lf\n",res);   
}
#include"equation.h"
#include<stdio.h>
double secant_k(double* f,int len,double a,double b){
    return (fx(f,a,len)-fx(f,b,len))/(a-b);
}
/**
 * 割线法
 * @param f 系数向量
 * @param len f的长度
 * @param x0 初始左区间边界
 * @param x1 初始右区间边界
 * @param eps 精确度
 */
double secant(double* f,int len,double x0,double x1,double eps){
    double x2;
    do{
        x2 = x1 - fx(f,x1,len) / secant_k(f,len,x0,x1);
        x0 = x1;
        x1 = x2;
    }while(fabs(x0-x1)>eps);
    return x1;
}

int main(){
    double f[] = {1,4,0,-10};
    int len = sizeof(f)/sizeof(double);
    double x0 = 1;
    double x1 = 2;
    double eps = 1e-3;
    double res = secant(f,len,x0,x1,eps);
    printf("%lf\n",res);
}
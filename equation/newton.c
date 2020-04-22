#include"equation.h"
#include<stdio.h>
#include <stdlib.h>

static int noFreePoint = 0;
// 对多项式微分返回多项式，注意需要free
double* diff(double* x,int len){
    double* y = (double*)malloc((len-1)*sizeof(double));
    noFreePoint++;
    for (int i=0;i<len-1;i++){
        y[i] = (len-1-i)*x[i];
    } 
    return y;  
}

// f 多项式系数向量
// len 系数向量长度
// init 初始值
// esp 精确度
double newton (double* f,int len ,double init,double esp){
    double xn =init;
    double x=init;
    // 求导
    double* df = diff(f,len);

    do{
        // 下山因子
        double lambda = 1;
        x = xn;
        do{
            // x = xn;
            xn = x-lambda*(fx(f,x,len)/fx(df,x,len-1));
            lambda = lambda/2;
        }while(fabs(fx(f,xn,len))>fabs(fx(f,x,len)));
        // 结束条件: x-xn的差小于精确度
    }while(fabs(x-xn) > esp);

    // 释放df内存
    free(df);
    noFreePoint--;
    return x;
}

// test
int main(){
    double f[] = {1,4,0,-10};
    double res = newton(f,4,1.5,1e-3); 
    printf("%lf\n",res);
}
#include<stdio.h>
#include<math.h>
#include"equation.h"

// f为降幂排列的系数
// len 系数的个数
// a,b预测区间
// esp 精确度，eg： 1e-3
double dichotomy_my(double* f,int len,double a,double b,double esp){
    while(fabs(a-b)>esp){
        double mid = (a+b)/2;
        if(fx(f,a,len)*fx(f,mid,len)<0){
            b = mid;
        }else{
            a = mid;
        }
    }
    return (a+b)/2;
}

// test
int main(){
    // 系数向量
    double x[] = {1,0,-2,-5};
    // 二分法
    double res = dichotomy_my(x,4,2,3,1e-3);
    printf("%lf",res);
}
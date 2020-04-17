#include<math.h>
// 定义一个函数指针类型
typedef double (*Fx)(double x) ;

// 多项式函数
// f为多项式系数向量(一个n维向量)
// x为自变量取值
// p为系数矩阵的长度,即最高次-1 .如果最高次是3那么p=4,由于有0次项.
double fx(double f[],double x,int p){
    double sum =0;
    for(int i=0;i<p;i++){
        sum += f[i]*pow(x,p-i-1);
    }
    return sum;
}
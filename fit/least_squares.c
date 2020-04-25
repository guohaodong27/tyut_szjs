#include "matrix.h"
#include <math.h>
int main(){

    // 输入x,y向量
    double x[] = {2,2.5,3,4,5,5.5};
    double y[] = {4,4.5,6,8,8.5,9};
    // 拟合次数
    int fit_power = 1;

    // 两个列向量xv yv
    Matrix* xv = c_m_array(x,sizeof(x)/sizeof(double));
    Matrix* yv = c_m_array(y,sizeof(y)/sizeof(double));

    // 方程矩阵
    Matrix* equation = c_m(fit_power+1,fit_power+1);
    // 右侧的y矩阵
    Matrix* yk = c_m(fit_power+1,1);
    // x向量的各个幂的和
    Matrix* sum_xi = c_m(2*fit_power+1,1);
    // 计算x的各幂和
    for (int i =0;i < sum_xi->m;i++){
        Coords range = {0,-1};
        Coords coord = {0,i};
        set_m(sum_xi, coord,sum_i(matrix_pow(xv,i),0,range));
    }
    // 计算yk
    for (int i = 0;i < yk->m;i++){
        Coords range = {0,-1};
        Coords ykc = {0,i};
        set_m(yk,ykc,sum_i(dot_times_m(yv,matrix_pow(xv,i)),0,range));
    }
    
    // 方程矩阵
    for(int i = 0;i < fit_power+1;i++){
        for (int j = 0;j < fit_power+1 ;j++){
            Coords c ={i,j};
            Coords xc = {0,i+j};
            set_m(equation,c,get_m(sum_xi,xc));
        }
    }
    Coords s = {0,0};
    set_m(equation,s,xv->m);
    
    // 增广矩阵
    Matrix* all = horicat(equation,yk);
    disp_m(all);
    disp_m(equation);


    d_m(yk);
    d_m(sum_xi);
    d_m(equation);
    d_m(xv);
    d_m(yv);
    printf("\n%d\n",noFreePointCount);
}
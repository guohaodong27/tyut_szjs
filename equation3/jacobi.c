#include "../matrix.h"
/**
 * 雅克比方法,迭代
 * @param mat 增广矩阵
 * @param eps 精确度
 * @param xn 初始x,注意:计算后将被自动free
 */
Matrix* jacobi(Matrix* mat,Matrix* xn,double eps){
    // 求解迭代矩阵
    Matrix* B = m_create(mat->m,mat->n-1);
    Matrix* b = m_create(mat->m,1);

    // 设置矩阵中的值,后去迭代矩阵
    for(int i =0;i < B->m;i++){
        // 对角元素的值
        double d = m_get(mat,i,i); 
        for(int j =0;j < B->n;j++){
            if(i==j){
                m_set(B,i,j,0);
            }else{
                m_set(B,i,j,- m_get(mat,i,j) / d);
            }
        }
        m_set(b,i,0,m_get(mat,i,mat->n-1) / d);
    }

    // 开始迭代
    Matrix* x;
    Matrix* Bx;
    double x_xn;
    do{
        x = xn;
        Bx = times(B,x);
        xn = add(Bx,b);
        x_xn = fabs(norm(x)-norm(xn));
        m_distory(Bx);
        if(x_xn < eps){
            m_distory(xn);
            m_distory(B);
            m_distory(b);
            break;
        }else{
            m_distory(x);
        }
    }while(1);
    return x;
}

int main(){
    // double a[3][4] = {{2,-1,-1,-5},{1,5,-1,8},{1,1,10,11}};
    double a [3][4] = {{10,-1,-2,7.2},{-1,10,-2,8.3},{-1,-1,5,4.2}};
    double x0[] = {1,1,1};
    Matrix* mat = array2mat((double*)a,3,4);
    Matrix* init = array2mat((double*)x0,3,1);
    Matrix* res = jacobi(mat,init,1e-3);
    disp_m(res);

    m_distory(mat);
    m_distory(res);
}

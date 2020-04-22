#include<stdio.h>
#include<stdlib.h>
#include "../matrix.h"

/**
 * 高斯消元法
 * mat 增广矩阵
 */
void gaussian_eli(Matrix* mat){
    // j为列标,总体是按列遍历赋值
    for(int j = 0;j < mat-> n;j++){
        // i为行标,当前处理的行的行标,<j,j>为当前处理的列的对角线坐标
        for(int i = j+1;i < mat->m;i++){
            double k = - m_get(mat,i,j) / m_get(mat,j,j);
            // 两行相加
            for(int index = 0; index < mat->n;index++){
                double val = m_get(mat,i,index) + m_get(mat,j,index)*k;
                m_set(mat,i,index,val);
            }
        }
    }
}

int main(){
    double a[][4] = {{2,8,2,14},{1,6,-1,13},{2,-1,2,5}};
    Matrix* mat = array2mat((double*)a,3,4);
    gaussian_eli(mat);
    // int swap[] = {0,1,2};
    int swap[] = {0,1,2};
    Matrix* res = get_result(mat,swap);
    disp_m(mat);
    disp_m(res);
    m_distory(mat);
    m_distory(res);
}
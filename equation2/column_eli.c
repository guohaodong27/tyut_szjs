#include "matrix.h"
#include<math.h>
/**
 * 列主元消元法
 * @param mat: 矩阵
 */
void col_eli(Matrix* mat){
    for (int j = 0; j < mat->n; j++)
    {   
        // 选最大元,换行,主元坐标为<j,j>
        int maxind = j;
        double max = fabs(m_get(mat,j,j));
        for(int cur =j;cur < mat->m;cur++){
            double curval = fabs(m_get(mat,cur,j));
            if(curval > max){
                max = curval;
                maxind = cur; 
            }
        }
        change_i(mat,j,maxind);

        // 消去
        for(int i =j+1;i < mat->m;i++){
            double k = -m_get(mat,i,j) / m_get(mat,j,j);
            for(int index =0; index < mat->m;index++){
                double val = m_get(mat,i,index) + m_get(mat,j,index) * k;
                m_set(mat,i,index,val);
            }
        }
    }
}

/**
 * 回代
 * @param mat: 一个上三角矩阵
 * @return 方程的解,一个列向量,自上向下依次x0,x1...xn
 */
Matrix* get_result(Matrix* mat,int* swap_map){
    Matrix* res = m_create(mat->m,1);
    double sum =0;
    // 计算每一行
    for(int xind = mat->m-1;xind > -1;xind--){
        double sum =0;
        // 计算和的话,从<xind,xind+1>往后
        for(int ind = xind+1;ind < mat->m;ind++){
            sum += m_get(mat,xind,ind);
        }
        double xi  = (m_get(mat,xind,mat->m) - sum) / m_get(mat,xind,xind);
        m_set(res,swap_map[xind],0,xi);
    }
    return res;
}

int main(){
    double a[][4] = {{4,-1,1,5},{-18,3,-1,-15},{1,1,1,6}};
    Matrix* mat = array2mat((double*)a,3,4);
    col_eli(mat);
    disp_m(mat);
    Matrix* res = get_result(mat);
    m_distory(mat);
    m_distory(res);
}
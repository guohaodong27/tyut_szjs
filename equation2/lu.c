#include "matrix.h"

// LU分解 doolittle
void lu(Matrix* mat){
    // 根据对角线循环
    for(int d = 0; d < mat->n;d++){
        // u
        for(int j = d;j< mat->n;j++){
            // <d,j>
            double sum =0;
            for(int i = 0;i < d;i++){
                sum += m_get(mat,i,j) * m_get(mat,j,i);
            }
            double val = (m_get(mat,d,j)-sum) / m_get(mat,d,d);
            m_set(mat,d,j,val);
        }
        // l
        for(int i = d+1;i < mat->m;i++){
            // <i,d>
            double sum  = 0;
            // ind表示的是累加的j值
            for(int j = 0;j < d;j++){
                sum += m_get(mat,i,j) * m_get(mat,j,i);
            }
            double val = (m_get(mat,i,d) - sum) / m_get(mat,d,d);
            m_set(mat,i,d,val);
        }
    }
}
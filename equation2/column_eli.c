#include "../matrix.h"
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
            if(fabs(curval) > fabs(max)){
                max = curval;
                maxind = cur; 
            }
        }
        change_i(mat,j,maxind);

        // 消去
        for(int i =j+1;i < mat->m;i++){
            double k = -m_get(mat,i,j) / m_get(mat,j,j);
            for(int index =0; index < mat->n;index++){
                double val = m_get(mat,i,index) + m_get(mat,j,index) * k;
                m_set(mat,i,index,val);
            }
        }
    }
}



int main(){
    double a[][4] = {{2,8,2,14},{1,6,-1,13},{2,-1,2,5}};
    Matrix* mat = array2mat((double*)a,3,4);
    int swap[] = {0,1,2};
    col_eli(mat);
    disp_m(mat);
    Matrix* res = get_result(mat,swap);
    disp_m(res);
    m_distory(mat);
    m_distory(res);
}
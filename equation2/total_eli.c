#include"matrix.h"

void total_eli(Matrix* mat,int* record){
    for(int j = 0;j < mat->n;j++){
        // 选取主元
        int maxindx = j;
        int maxindy = j;
        double max = m_get(mat,maxindy,maxindx);
        for(int y = j;y < mat->m ;y++){
            for(int x = j;x < mat->m;x++){
                double cur = m_get(mat,x,y);
                if(max < cur){
                    max = cur;
                    maxindx = x;
                    maxindy = y;
                }
            }
        }

        //交换
        change_i(mat,j,maxindy);
        change_j(mat,j,maxindx);
        int tmp = (*record+j);
        *(record+j) = *(record+maxindx);
        *(record+maxindx) = tmp;



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


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
                if(fabs(max) < fabs(cur)){
                    max = cur;
                    maxindx = x;
                    maxindy = y;
                }
            }
        }

        //交换
        change_i(mat,j,maxindx);
        change_j(mat,j,maxindy);
        int tmp = record[j];
        record[j] = record[maxindy];
        record[maxindy] = tmp;


        disp_m(mat);
        printf("\n");
        for(int i = 0; i< 4;i++){
            printf("%d\t",*(record+i));
        }
        printf("\n");
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
    int swap[] = {0,1,2,3};
    total_eli(mat,swap);
    disp_m(mat);
    Matrix* res = get_result(mat,swap);
    disp_m(res);
    m_distory(res);
    m_distory(mat);
}


#include "../matrix.h"

Matrix* gauss_seidel(Matrix* mat,Matrix* xn,double eps){
    
    Matrix* D = m_create(mat->m,mat->n-1);
    Matrix* L = m_create(mat->m,mat->n-1);
    Matrix* U = m_create(mat->m,mat->n-1);
    Matrix* b = m_create(mat->m,1);

    for(int i =0 ;i < mat->m;i++){
        for(int j = 0 ;j < mat->n-1;j++){
            double val = m_get(mat,i,j);
            if(i == j){
                m_set(D,i,j,val);
            }else{
                if(i < j){
                    m_set(U,i,j,val);
                }else{
                    m_set(L,i,j,val);
                }
            }
        }
    }
    for(int k = 0;k < mat->m;k++){
        m_set(b,k,0,m_get(mat,k,mat->n-1));
    }
    Matrix* DL = add(D,L);
    Matrix* DL_inv = inv(DL);
    Matrix* neg_B = times(DL_inv,U);

    Matrix* B = scalar_times(neg_B,-1);
    Matrix* f = times(DL_inv,b);
    Matrix* de[] = {D,L,U,b,DL,DL_inv,neg_B};
    distory(de,7);
    Matrix *Bx,*x;
    // 开始迭代
    do{
        x = xn;
        Bx = times(B,x);
        xn = add(Bx,f);
        double x_xn = fabs(norm(x)-norm(xn));
        m_distory(Bx);
        if(x_xn < eps){
            m_distory(xn);
            m_distory(B);
            m_distory(f);
            break;
        }else{
            m_distory(x);
        }
    }while(1);
    return x;
}

int main(){
    double a [3][4] = {{10,-1,-2,7.2},{-1,10,-2,8.3},{-1,-1,5,4.2}};
    double b[] = {1,1,1};
    Matrix* mat = array2mat((double*)a,3,4);
    Matrix* xn = array2mat((double*)b,3,1);
    Matrix* x = gauss_seidel(mat,xn,1e-3);
    disp_m(x);
}
#include"../matrix.h"
/**
 * 拉格朗日插值
 * @param xi x向量
 * @param yi y向量
 * @param n阶数
 * @param x 求g(x)值
 */
double lagrange(Matrix* xi,Matrix* yi,int n,double x){
    double sum =0;
    for(int i =0;i < yi->m;i++){
        double mul=1;
        for(int j = 0;j < n+1;j++){
            if (i != j){
                mul *= (x - m_get(xi,j,0)) / (m_get(xi,i,0) - m_get(xi,j,0));
            }
        }
        double test = mul*m_get(yi,i,0); 
        printf("%lf\n",test);
        sum += mul*m_get(yi,i,0);
    }
    return sum;
}


int main(){
    double x[] = {0.4,0.55,0.65,0.80,0.90,1.05};
    double y[] = {0.41075,0.57816,0.69675,0.88811,1.02652,1.25386};
    // double x[] = {10,15,20};
    // double y[] = {1,1.1761,1.3010};
    Matrix* xi = array2mat(x,6,1);
    Matrix* yi = array2mat(y,6,1);
    double res = lagrange(xi,yi,5,0.596);
    // double res = lagrange(xi,yi,5,12);
    printf("%lf\n",res);
}

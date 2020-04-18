
double lagrange(Matrix* xi,Matrix* yi,int n,double x){
    double sum =0;
    for(int i =0;i < yi->m;i++){
        double mul=1;
        for(int j = 0;j < xi->m;j++){
            mul *= (x - m_get(xi,j,0)) / (m_get(xi,i,0) - m_get(xi,j,0));
        }
        sum += mul*m_get(yi,i,0);
    }
    return sum;
}


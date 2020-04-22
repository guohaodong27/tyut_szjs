# include <stdio.h>
# include<stdlib.h>

// 牛顿插值
int main(){
    // param
    double x[] = {0.4,0.55,0.65,0.80,0.90,1.05};
    double y[] = {0.41075,0.57816,0.69675,0.88811,1.02652,1.25386};
    // double x[] = {1,4,9,16,25,36};
    // double y[] = {1,2,3,4,5,6};
    int len = 6;
    double xn = 0.596;

    // allocate memory
    double* area = (double*)malloc(sizeof(double)*len*len);

    // init matrix
    for(int i=0;i < len;i++){
        area[i] = y[i];
    }

    // 第i行的对x的差分间距为i,对y的差分间距始终是1
    for(int i = 1;i < len;i++){
        for(int j = i;j < len;j++){
            // i,j为行数,列数
            double dy = area[(i-1)*len+j]-area[(i-1)*len+j-1];
            double dx = x[j] - x[j-i];
            area[i*len+j] = dy/dx;
        }
    }


    // output
    for (int i = 0;i < len; i++){
        for (int j =0;j < len;j++){
            if (j < i){
                printf("      \t");
            }else{
                double value = area[i*len+j];
                printf("%6.3lf \t",value);
            }
        }
        printf("\n");
    }


    printf("\n\n");
    double sum =0;
    for(int i = 0;i< len;i++){
        double mul = 1;
        for(int k = 0;k < i;k++){
            mul *= (xn - x[k]);
        }
        sum += area[i*(len+1)]* mul;
    }
    printf("%lf\n",sum);

    free(area);
}
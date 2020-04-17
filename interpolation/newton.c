# include <stdio.h>
# include<stdlib.h>

// 牛顿插值
int main(){
    // param
    double x[] = {1,2,3,4,5};
    double y[] = {1,4,7,8,6};
    int len = 5;


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
    for(int i = 0;i< len*len;i+=(len+1)){
        printf("%6lf\t",area[i]);
    }
    printf("\n");

    free(area);
}
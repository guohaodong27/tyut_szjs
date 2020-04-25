#include<stdio.h>
#include<math.h>
void Gauss();
double* get_result(double* mat,int* orderby,int m,int n);
int main(){
	double a[][4] = {{2,8,2,14},{0,2,-2,6},{0,0,-9,18}};
	int swap[] = {0,1,2};
	double* res = get_result(a,swap,3,4);
}
static int noFreePoint = 0 ;
// mxn的矩阵
// mat 输入上三角阵的二维数组首地址(数组名)
// orderby 解的顺序,如果是全住院消元法输入记录的交换数组,如果要让res = x0 res+1 = x1 则输入 int swap[] = {0,1,2}
// m 矩阵的行数 如果是一个 a[3][4] 那么m = 3,n = 4
// n矩阵的列数 
double* get_result(double* mat,int* orderby,int m,int n){
    double sum = 0;
    double* res = (double*)malloc(m*sizeof(double));
	res[m-1] = mat[n*(m-1)+(n-1)] / mat[n*(m-1)+m-1];
	noFreePoint++; 
    for(int xind = m-2;xind > -1;xind--){
        double sum =0;
        for(int ind = xind+1;ind < m;ind++){
			sum += mat[xind*n+ind] * res[orderby[ind]];
        }
        double xi  = (mat[n*xind+m] - sum) / mat[n*xind+xind];
        res[orderby[xind]] = xi;
    }
	return res;
}

void Gauss(){
//输入矩阵的值 
	int i = 3 ;

    double Gas[3][4] =  {{2,8,2,14},{1,6,-1,13},{2,-1,2,5}};
// 将矩阵变成上三角形形式
	double midx;
	for(int n=0;n<i+1;n++){
		for(int m=n+1;m<=i;m++){
			midx=Gas[m][n]/Gas[n][n];
			for(int z=0;z<i;z++) {
				Gas[m][z]=Gas[m][z]-Gas[n][z]*midx;
		    }
		}
	}	
//将矩阵回带
    int swap[] = {0,1,2};
    double* res = get_result(Gas,swap,3,4);
//输出解
	printf("解为");
	for(int t=0;t<i;t++) printf("%lf",Gas[t][i]); 
}

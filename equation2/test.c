#include"./matrix.h"
int main(){
    double a[][3] = {{2,3,1},{0,1,3},{1,2,5}};
    Matrix* mat = array2mat(a,3,3);
    inv(mat);

}
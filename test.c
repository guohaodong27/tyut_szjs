#include "matrix.h"
int main(){
    double a [3][4] = {{10,-1,-2,7.2},{-1,10,-2,8.3},{-1,-1,5,4.2}};
    Matrix* ax = array2mat(a,3,4);
    disp_m(ax);
    Matrix* bx = array2mat(ax->val,3,1);
    disp_m(bx);
}
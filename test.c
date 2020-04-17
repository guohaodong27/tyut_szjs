
#include "equation2/matrix.h"

int main(){
    double a[][3] = {{21,22,23},{31,32,33}};
    double* array = (double*)a;
    Matrix* mat = array2mat(array,2,3);
    disp_m(mat);
}
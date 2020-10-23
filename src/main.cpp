#pragma once

#include <includes/matrices.hpp>

int main(){
    int rows = 3;
    int cols = 3;
    matr * a = new matr;
    
    matr * b ;//= new matr;

    matrix_init(a,rows,cols);
    

    a->matrix[0][0] = 1;
    a->matrix[0][1] = 2;
    a->matrix[0][2] = 1;

    a->matrix[1][0] = 1;
    a->matrix[1][1] = 4;
    a->matrix[1][2] = 4;

    a->matrix[2][0] = 3;
    a->matrix[2][1] = 30;
    a->matrix[2][2] = 3;

    //printMtx(a);
    
    // b = upper_triangular(a);

    // printMtx(b);
    

    b = roots(a);

    printMtx(b);

    matrix_delete(b);
    matrix_delete(a);
    


    return 0;
}
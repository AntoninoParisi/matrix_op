#pragma once

#include <includes/matrices.hpp>

int main(){
    int rows = 5;
    int cols = 5;
    matr * a = new matr;
    
    matr * b ;//= new matr;

    matrix_init(a,rows,cols); // allocating the matrix dinamically
    

    a->matrix[0][0] = 1;
    a->matrix[0][1] = 100;
    a->matrix[0][2] = 1;
    a->matrix[0][3] = 1;
    a->matrix[0][4] = 1;

    a->matrix[1][0] = 1;
    a->matrix[1][1] = 20;
    a->matrix[1][2] = 1;
    a->matrix[1][3] = 1;
    a->matrix[1][4] = 1;

    a->matrix[2][0] = 1;
    a->matrix[2][1] = 1;
    a->matrix[2][2] = 20;
    a->matrix[2][3] = 1;
    a->matrix[2][4] = 1;



    a->matrix[3][0] = 1;
    a->matrix[3][1] = 1;
    a->matrix[3][2] = 1;
    a->matrix[3][3] = 20;
    a->matrix[3][4] = 1;

    a->matrix[4][0] = 1;
    a->matrix[4][1] = 1;
    a->matrix[4][2] = 1;
    a->matrix[4][3] = 20;
    a->matrix[4][4] = 18;


    printMtx(a);
    
    // b = upper_triangular(a);

    // printMtx(b);
    
    

    // sort(a);
    // b = roots(a);

    // printMtx(a);
    // printMtx(b);


    //matrix_delete(b);
    // double res = det(reshape(a,1,1,4),1,1,4);
    double res = det(a,0,0,5);
    std::cout << "determinante : " << res << std::endl;
    matrix_delete(a);
    


    return 0;
}
#include <iostream>
#include <cmath>

/**
 * @Author Antonino Parisi 
 * 
 * */
struct matr{
    double **matrix;
        int length;
        int width;
};

/**
 * @notes
 * it initialize the matrix pointers in base of the rows and cols passed through parameters
 * 
 * */
void matrix_init(matr * a,int rows,int cols){ // simply and usefull

    a->matrix = new double*[rows];
    
    for(int index =0;index<rows;index++)
        a->matrix[index] = new double[cols];

    for(int i=0;i<rows;i++)
        for(int j =0;j<cols;j++)
            a->matrix[i][j] = 0.0f;


    a->length = rows;
    a->width = cols;

}



void matrix_delete(matr * a){ // remeber to delete all dynamic structures allocated 

    for(int index =0;index<a->length;index++)
        delete [] a->matrix[index];
    delete [] a->matrix;

}

matr * sum(matr * a, matr * b){ // summation of matrix

    if(a->length != b->length || a->width != b->width)
    {
        std::cout << "cannot sum matrix that have different dimensions" << std::endl;
        return NULL;
    }
    matr * c = new matr;

    
    c->width = a->width;
    c->length = a->length;

    matrix_init(c,a->length,a->width);

    for(int i =0;i < a->length; i++)
        for(int j=0;j<a->width;j++)
            c->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];

    return c;
}


void printMtx(matr * a){ // simply and usefull
    
    for(int i =0;i < a->length; i++){
        std::cout << "[" ;
        for(int j=0;j<a->width;j++){
            std::cout << a->matrix[i][j];
            (j == a->length-1) ? std::cout << "]\n" :std::cout << ','; 
            
        }
    }

}

// sorting by pivot 
void sort(matr * a){ 

    int count =0;
    for(int j = 0;j < a->width;j++)
        for(int i=0; i < a->length ;i++)
            if( i == j && a->matrix[j][i] == 0)
                {
                    double tmp = 0;

                    for(int k = 0; k < a->width;k++) // swapping rows
                        {
                            tmp = a->matrix[i][k];
                            a->matrix[i][k] = a->matrix[i+1+count][k];
                            a->matrix[i+1+count][k] = tmp;
                        }
                    count++;
                    i--; // turn back and check
                }
                else // the element is > 0
                {
                    count = 0;
                }
                
}

// gauss alg.
matr * upper_triangular(matr * a){
    matr * b = (a);

    for(int cycle =0;cycle < b->length-1; cycle++) // the current operating line
        for(int i = cycle;i < b->width-1; i++){ // how much i have to repeat elimination ( each row below that)

            // - b / a where a is the pivot value that we are cosidering, and b is one of N terms below the pivot
            double val = - (b->matrix[i+1][cycle] / b->matrix[cycle][cycle]); // the term to mult.


            for(int j = cycle;j < b->length ; j++){ // actuating the elimination 

                b->matrix[i+1][j] = b->matrix[i+1][j] + b->matrix[cycle][j]*val;
            }
            
            
        }


    return b;
}

/**
 * @it finds the roots of the matrix
 **/
matr * roots(matr * a){
    matr * c = new matr;

    matrix_init(c,a->length,a->width);

    matr * d = upper_triangular(a); // gaussian alg.

    for(int i = 0;i < a->length;i++)
        c->matrix[i][i] = d->matrix[i][i];
   
    return c;
}

// reshape the input matrix
// avoiding the column where the det is calculated
matr * reshape(matr * a,int row,int col,int order){
    matr * b = new matr;
    matrix_init(b,order,order);
    int x = 0,y=0;
    

    for(int i = 1;i < a->length;i++){ 
        for(int j = 0;j < a->width;j++)
        {
          
            if(j!=col) // the column to avoid
            {
                b->matrix[x][y++] = a->matrix[i][j];
            }

        }
        x++;
        y=0;
    }




return b;
}


// determinant of matrix nb -> only NxN
double det(matr * a,int row,int col,int order){
    
    float res = 0.0;

    if(a->length != a->width){
        std::cout << "This isn't a squared matrix!" << std::endl;
        return 0;
    }
    
    if(order > 2) 
    {
       
            for(int f = 0; f < order;f++){
           

                    matr * b = reshape(a,row,f,order-1);

                    res = res + std::pow(-1,f+row)*a->matrix[row][f]*det(b,0,0,order-1);
                    matrix_delete(b); // avoiding memory leaks
            }

    }
    else
    {

            res =  a->matrix[0][0] * a->matrix[1][1] - a->matrix[1][0] * a->matrix[0][1];
     
    }
    


    return res;

}




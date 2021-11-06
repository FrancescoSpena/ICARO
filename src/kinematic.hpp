
#include <math.h>
#define LEN 1
#define ROWS 3
#define COLS 3


class Data{
    public:
    //costructor
    Data(int theta1, int theta2, int theta3){
        this->t1 = theta1;
        this->t2 = theta2;
        this->t3 = theta3;
        this->matrix = (double**)malloc(sizeof(double*)*ROWS);
        for(int i=0;i<ROWS;i++){
            this->matrix[i] = (double*)malloc(sizeof(double)*COLS);
        }
        matrix_init();
    }
    //method
    /*
    This matrix: with speeds of motors --> positions of motors
    Inverse matrix: with positions of motors --> speeds of motors
    */
    double **matrixSpeed(){
        if(control_value()){
            this->matrix[0][0] = -sin(this->t1);
            this->matrix[0][1] = -sin(this->t2);
            this->matrix[0][2] = -sin(this->t3);

            this->matrix[1][0] = cos(this->t1);
            this->matrix[1][1] = cos(this->t2);
            this->matrix[1][2] = cos(this->t3);

            this->matrix[2][0] = LEN;
            this->matrix[2][1] = LEN;
            this->matrix[2][2] = LEN;
            return this->matrix;
        }
        return NULL;
    }
    private:
    int t1,t2,t3;
    double **matrix;

    /*La funzione fa schifo ma la più semplice che mi viene*/
    int control_value(){
        if(this->t1 != 0 && this->t1 != M_PI){
            if(this->t2 != 0 && this->t2 != M_PI){
                if(this->t3 != 0 && this->t3 != M_PI){
                    return 1;
                }
            }
        }
        return 0;
    }
    void matrix_init(){
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                this->matrix[i][j] = 0;
            }
        }
    }
};

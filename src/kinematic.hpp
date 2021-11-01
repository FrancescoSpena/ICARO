
#include <math.h>
#define LEN 1


class Data{
    public:
    //costructor
    Data(int theta1, int theta2, int theta3){
        this->theta_1 = theta1;
        this->theta_2 = theta2;
        this->theta_3 = theta3;
        this->row = 3;
        this->col = 3;
        this->cinematic_matrix = (double**)malloc(sizeof(double*)*this->row);
        for(int i=0; i<this->row; i++){
            this->cinematic_matrix[i] = (double*)malloc(sizeof(double)*this->col);
        }
    }
    //method
    double **matrix_speed(){
        cinematic_matrix[0][0] = -sin(this->theta_1);
        cinematic_matrix[0][1] = -sin(this->theta_2);
        cinematic_matrix[0][2] = -sin(this->theta_3);

        cinematic_matrix[1][0] = cos(this->theta_1);
        cinematic_matrix[1][1] = cos(this->theta_2);
        cinematic_matrix[1][2] = cos(this->theta_3);

        cinematic_matrix[2][0] = LEN;
        cinematic_matrix[2][1] = LEN;
        cinematic_matrix[2][2] = LEN;

        return cinematic_matrix;
    }
    private:
    int theta_1;
    int theta_2;
    int theta_3;
    double **cinematic_matrix;
    int row;
    int col;
};

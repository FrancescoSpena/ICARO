

#include <math.h>

#define LEN 1

typedef struct Data{
    int theta_motor1;
    int theta_motor2;
    int theta_motor3;

    double **cinematic_matrix;
}Data;


void Data_init(Data *data,int theta1, int theta2, int theta3){
    data->theta_motor1 = theta1;
    data->theta_motor2 = theta2;
    data->theta_motor3 = theta3;
}


#include <math.h>

#define LEN 1

typedef struct Data{
    int theta_motor1;
    int theta_motor2;
    int theta_motor3;

    double **cinematic_matrix;
    int row;
    int col;
}Data;


void Data_init(Data *data,int theta1, int theta2, int theta3);
void cinematic_data_speed(Data *data);

#include "kinematic.h"

void Data_init(Data *data,int theta1, int theta2, int theta3){
    data->theta_motor1 = theta1;
    data->theta_motor2 = theta2;
    data->theta_motor3 = theta3;
    data->row = 3;
    data->col = 3;
    data->cinematic_matrix = (double**)malloc(sizeof(double*)*data->row);
    for(int i=0;i<data->row;i++){
        data->cinematic_matrix[i] = (double*)malloc(sizeof(double)*data->col);
    }
}

void cinematic_data_speed(Data *data){
    data->cinematic_matrix[0][0] = -sin(data->theta_motor1);
    data->cinematic_matrix[0][1] = -sin(data->theta_motor2);
    data->cinematic_matrix[0][2] = -sin(data->theta_motor3);

    data->cinematic_matrix[1][0] = cos(data->theta_motor1);
    data->cinematic_matrix[1][1] = cos(data->theta_motor2);
    data->cinematic_matrix[1][2] = cos(data->theta_motor3);

    data->cinematic_matrix[2][0] = LEN;
    data->cinematic_matrix[2][1] = LEN;
    data->cinematic_matrix[2][2] = LEN;
}
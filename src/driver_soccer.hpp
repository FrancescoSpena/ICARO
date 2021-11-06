
#include "motor_soccer.hpp"
#include "kinematic.hpp"

#define ROWS 3
#define COLS 3

class DriverSoccer{
    public:
    DriverSoccer(int theta1, int theta2, int theta3){
        this->speed_der[0] = 0;
        this->speed_der[1] = 0;
        this->speed_der[2] = 0;

        this->theta1 = theta1;
        this->theta2 = theta2;
        this->theta3 = theta3;
    }
    void driver_addMotor(MotorSoccer motor){
        this->motor[index] = motor;
        index++;
    }
    void driver_addMotors(MotorSoccer motor1, MotorSoccer motor2, MotorSoccer motor3){
        this->motor[0] = motor1;
        this->motor[1] = motor2;
        this->motor[2] = motor3;
    }
    void driver_setSpeed(double x, double y, double theta){
        this->speed_der[0] = x;
        this->speed_der[1] = y;
        this->speed_der[2] = theta;
    }
    void driver_handle(){
        if(isEmpty(this->matrix_pos)){
            printf("Attention: Change values of matrix");
            return;
        }else{
            //TODO
        }
    }
    void driver_changeMatrix(){
        double temp = 0.0;
        for(int i=0; i < ROWS; i++){
            for(int j=0;j<COLS;j++){
                printf("Value [%d][%d] = ", i,j);
                scanf("%lf", &temp);
                this->matrix_pos[i][j] = temp;
                temp = 0;
            }
        }
        printf("New matrix:\n");
        printMatrix();
    }
    void driver_reset(){
        for(int i=0;i<ROWS;i++){
            this->speed_der[i] = 0;
        }
        driver_handle();
    }
    private:
    int theta1;
    int theta2;
    int theta3;
    int index;

    double matrix_pos[ROWS][COLS] = 
    {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    int isEmpty(double const matrix[ROWS][COLS]){
        int accumulo = 0;
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                accumulo += this->matrix_pos[i][j];
            }
        }
        if(accumulo != 0){
            return 0;
        }else{
            return 1;
        }
    }
    void printMatrix(){
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                printf("%lf\t", this->matrix_pos[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    double speed_der[3]; //vel_x, vel_y, rotazione
    MotorSoccer motor[];
};
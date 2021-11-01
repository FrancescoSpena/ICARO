
#include "motor_soccer.hpp"
#include "kinematic.hpp"

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
        Data *data = (Data*)malloc(sizeof(Data));
        Data_init(data,this->theta1,this->theta2,this->theta3);
        cinematic_data_speed(data);
        for(int i=0;i<3;i++){
            double speed = 0;
            for(int j=0;j<3;j++){
                speed += data->cinematic_matrix[i][j]*this->speed_der[j];
            }
            this->motor[i].motor_setSpeed(speed*255);
        }

        for(int i=0;i<3;++i){
            this->motor[i].motor_handle();
        }
    }
    void driver_reset(){
        for(int i=0;i<3;i++){
            this->speed_der[i] = 0;
        }
        driver_handle();
    }
    private:
    int theta1;
    int theta2;
    int theta3;
    int index;
    double speed_der[3]; //vel_x, vel_y, rotazione
    MotorSoccer motor[];
};
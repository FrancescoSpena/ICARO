/**
 * motor_soccer.hpp
 * @author Francesco Spena
**/

#define NUM_PIN 3

#include <iostream>

class MotorSoccer{
    public:
    //costructor
    //dirA, dirB, pwm
    MotorSoccer(int *pin){
        this->pin_dirA = pin[0];
        this->pin_dirB = pin[1];
        this->pin_pwm = pin[2];
        this->dir = 1;
        this->speed = 0;
        this->pwm = 0;
        motor_init(pin);
    }
    //costructor
    MotorSoccer(int pin_dirA, int pin_dirB, int pin_pwm){
        this->pin_dirA = pin_dirA;
        this->pin_dirB = pin_dirB;
        this->pin_pwm = pin_pwm;
        this->dir = 1;
        this->speed = 0;
        this->pwm = 0;
        motor_init(pin_dirA,pin_dirB,pin_pwm);
    }
    //public method
    //set speed of single motor
    void motor_setSpeed(int speed){
        if(speed >= 0){
            this->speed = speed;
            this->dir = 0;
        }else{
            this->speed = - speed;
            this->dir = 1;
        }

        if(this->speed > 255){
            this->speed = 255;
        }
    }
    //write on pin new speeds
    void motor_handle(){
        /*
        digitalWrite(this->pin_dirA,this->dir);
        digitalWrite(this->pin_dirB,!this->dir);
        analogWrite(this->pin_pwm,this->speed);
        */
    }

    private:
    //pin
    int pin_dirA;
    int pin_dirB;
    int pin_pwm;

    //variable
    int dir;
    int speed;
    int pwm;

    //inizialized pin of motor
    void motor_init(int *pin){
        for(int i=0;i<NUM_PIN;i++){
            //pinMode(pin[i],OUTPUT);
            //analogWrite(pin[i],0);
        }
    }
    //inizialized pin of motor
    void motor_init(int pin_dirA, int pin_dirB, int pin_pwm){
        /*
        pinMode(pin_dirA,OUTPUT);
        pinMode(pin_dirB,OUTPUT);
        pinMode(pin_pwm,OUTPUT);
        analogWrite(pin[0],0);
        analogWrite(pin[1],0);
        analogWrite(pin[2],0);
        */
    }
};
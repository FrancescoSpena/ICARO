#include "sensor.hpp"

class LineSensor: public Sensor{
    public:
    void sensor_init(){
        //TODO
    }
    void sensor_handle(){
        //TODO
    }
    private:
    double x;
    double y;
    int soglia,misura,misura_min,misura_max;
    int detect_flag,calibra_flag;
};
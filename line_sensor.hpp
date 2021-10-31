
#include "sensor.hpp"

class LineSensor: public Sensor{
    public:
    void sensor_init(){

    }
    void sensor_handle(){

    }
    private:
    double x;
    double y;
    int soglia,misura,misura_min,misura_max;
    int decect_flag,calibra_flag;
};
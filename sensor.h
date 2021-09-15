#include <string>

using namespace std;

template<typename T>
class SensorIF
{
public:
    SensorIF(T min, T max) : min_value(min),max_value(max){}

virtual void setValue(T val) = 0;
virtual T readValue() 
{
    return value;
}

string getState()
{
    if(value < min_value) return "low state";
    else if (value > min_value && value < max_value) return "normal state";
    else if (value > max_value) return "high state";
    else return "state unknown";
}


protected:
    T value;
    T min_value;
    T max_value;
};

class TemperatureSensor : public SensorIF<float>
{
public:
    TemperatureSensor(float min, float max) : SensorIF(min, max){}

    void setValue(float val)
    {
        value = val; //ToDo implement update mechanism
    }

};

class HeartBeatSensor : public SensorIF<int>
{
public:
    HeartBeatSensor(int min, int max) : SensorIF(min, max){}

    void setValue(int val)
    {
        value = val; //ToDo implement update mechanism
    }

};

class So2Sensor : public SensorIF<int>
{
public:
    So2Sensor(int min, int max) : SensorIF(min, max){}

    void setValue(int val)
    {
        value = val; //ToDo implement update mechanism
    }

};

class BloodPressureSensor : public SensorIF<int>
{
public:
    BloodPressureSensor(int min, int max) : SensorIF(min, max){}

    void setValue(int val)
    {
        value = val; //ToDo implement update mechanism
    }


};
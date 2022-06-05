#ifndef Q4_H
#define Q4_H
#include<iostream>
#include<numeric>

namespace q4
{

struct Vector2D
{
    Vector2D(double inp1 , double inp2) : x{inp1} , y{inp2} {}  // constructor
    double x{};
    double y{}; 
};

struct Sensor
{
    Sensor(Vector2D position , double _accuracy) : pos{position} , accuracy{_accuracy} {} // constructor
	Vector2D pos;
	double accuracy;    
};

static Vector2D kalman_filter(std::vector<Sensor> my_sensor) // function to calculate kalman filter
    {
        
        double total_accuracy{std::accumulate(my_sensor.begin(), my_sensor.end(), 0.0, [](double total_sum, Sensor overall_of_sensors) { return total_sum + overall_of_sensors.accuracy; })}; // total accuracy of all sensors
        double x = std::accumulate(my_sensor.begin(), my_sensor.end(), 0.0, [](double sum_x, Sensor sensor_x) { return sum_x + sensor_x.pos.x * sensor_x.accuracy; }) / total_accuracy;       // x coordinate of the average of all sensors        
        double y = std::accumulate(my_sensor.begin(), my_sensor.end(), 0.0, [](double sum_y, Sensor sensor_y) { return sum_y + sensor_y.pos.y * sensor_y.accuracy; }) / total_accuracy;       // y coordinate of the average of all sensors
        Vector2D filter_result{x , y}; 
        return filter_result;

    }
}
#endif //Q4_H
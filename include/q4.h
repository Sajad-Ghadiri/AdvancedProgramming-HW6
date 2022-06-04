#ifndef Q4_H
#define Q4_H
#include<iostream>
#include<numeric>

namespace q4
{

struct Vector2D
{
double x{};
double y{}; 
};

struct Sensor
{
	Vector2D pos;
	double accuracy;    
};
    static Vector2D kalman_filter(std::vector<Sensor> my_sensor)
    {
        Vector2D filter_result{};
        double total_accuracy{std::accumulate(my_sensor.begin(), my_sensor.end(), 0.0, [](double total_sum, Sensor overall_of_sensors) { return total_sum + overall_of_sensors.accuracy; })};
        filter_result.y = std::accumulate(my_sensor.begin(), my_sensor.end(), 0.0, [](double sum_y, Sensor sensor_y) { return sum_y + sensor_y.pos.y * sensor_y.accuracy; }) / total_accuracy;
        filter_result.x = std::accumulate(my_sensor.begin(), my_sensor.end(), 0.0, [](double sum_x, Sensor sensor_x) { return sum_x + sensor_x.pos.x * sensor_x.accuracy; }) / total_accuracy;               
        return filter_result;

    }
}
#endif //Q4_H
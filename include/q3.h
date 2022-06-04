#ifndef Q3_H
#define Q3_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<regex>
#include<vector>

struct Flight
{
	std::string flight_number;
	size_t duration;
	size_t connections;
	size_t connection_times;
	size_t price;
};

////////////////////////////////////////////////////////////////
int duration_calculator(std::string flight_time)
{
    if(flight_time.empty()) {return 0;}

    std::regex pattern(R"((\d+)\h(\d+)\m?)");
    std::smatch match ;

    std::string hour{};
    std::string minute{};
    std::string second{};

    if(std::regex_search(flight_time , match , pattern))
    {
        hour = match[1] ;
        minute = match[2] ;
    }
    return std::stoi(hour)*60 + std::stoi(minute) ;
}
////////////////////////////////////////////////////////////////

auto gather_flights(std::string filename)
    {

    }
    std::ifstream file(filename);
	std::stringstream  buffer ;
	buffer << file.rdbuf();
	std::string txt = buffer.str() ;
	std::smatch match ;

    std::regex_search(txt , match , pattern)



#endif //Q3_H
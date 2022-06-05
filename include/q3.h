#ifndef Q3_H
#define Q3_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<regex>
#include<vector>
#include<queue>

namespace q3
{
    struct Flight
    {
        
        Flight(std::string flight_num , size_t _duration , size_t _connections , size_t _connection_times , size_t _price)
        : flight_number{flight_num} , duration{_duration} , connections{_connections} , connection_times{_connection_times} , price{_price}
        {
        }
        std::string flight_number;
        size_t duration;
        size_t connections;
        size_t connection_times;
        size_t price;
    };

static auto compare_q3
    {[](Flight inp1 , Flight inp2)
    {
        return ((inp1.duration + inp1.connection_times + 3*inp1.price) > (inp2.duration + inp2.connection_times + 3*inp2.price)) ;
    }
    } ;
static std::priority_queue<Flight , std::vector<Flight> , decltype(compare_q3)> flights_data{ compare_q3 } ;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static size_t duration_calculator(std::string flight_time)
    {
        
    if(flight_time.empty()) {return 0;}

    std::regex pattern_duration(R"((\d+)\h(\d+)?\m?)");
    std::smatch match ;

    size_t hour{};
    std::string minute{};

    std::regex_search(flight_time , match , pattern_duration) ;
    hour = static_cast<size_t>(std::stoi(match[1])) ;
    minute = match[2] ;
    if(minute.empty())
    {
        return hour*60 ;
    }
    else
    {
        return (hour* 60 )+ static_cast<size_t>(std::stoi(minute)) ;
    }

    }



////////////////////////////////////////////////////////////////

static auto gather_flights(std::string filename)
    {

    std::ifstream file(filename);
	std::stringstream  buffer ;
	buffer << file.rdbuf();
	std::string txt = buffer.str() ;

	std::smatch match ;
    std::regex pattern_gather_flights(R"(\d\- \w+\:(\w+) \- \w+\:(\w+) \- \w+\:(\w) \- \w+\:(\d+\h\d*\m*)\,?(\d*\h*\d*\m*)\,?(\d*\h*\d*\m*) \- \w+\:(\d+))") ;
    

    while(std::regex_search(txt , match , pattern_gather_flights))
    {
        
        std::string flight_number_file{match[1]} ;
        size_t duration_file{duration_calculator(match[2])} ;
        size_t connections_file{static_cast<size_t>(std::stoi(match[3]))} ;
        size_t connection_times_file{duration_calculator(match[4])+duration_calculator(match[5])+duration_calculator(match[6])} ;
        size_t price_file{static_cast<size_t>(std::stoi(match[7]))} ;
        
        flights_data.push(Flight{flight_number_file , duration_file , connections_file , connection_times_file , price_file}) ;
        txt = match.suffix().str() ;
	}
    return flights_data ;

    }



}


#endif //Q3_H
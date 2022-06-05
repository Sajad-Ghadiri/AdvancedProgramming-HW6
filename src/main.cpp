#include <iostream>
#include <gtest/gtest.h>

#include<fstream>
#include<sstream>
#include<string>
#include<regex>

#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
    std::ifstream file("flights.txt");
	std::stringstream  buffer ;
	buffer << file.rdbuf();
	std::string txt = buffer.str() ;
    

	std::smatch match ;
    std::regex pattern(R"(\d\- \w+\:(\w+) \- \w+\:(\w+) \- \w+\:(\w) \- \w+\:(\d+\h\d*\m*)\,?(\d*\h*\d*\m*)\,?(\d*\h*\d*\m*) \- \w+\:(\d+))") ;
    //std::regex pattern(R"(\d+\- \w+\:(\w+)\ - \w+\:(\d+\h\d*\m*))") ;
    while(std::regex_search(txt , match , pattern))
	{   
        
        
        std::cout << match[1] << " , " << match[2]<< " , " << match[3]<< std::endl;
        std::cout << match[4] << " , " << match[5]<< " , " << match[6]<<", " << match[7]<< std::endl;
        txt = match.suffix().str() ;
    }
        // debug section

    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;   
}
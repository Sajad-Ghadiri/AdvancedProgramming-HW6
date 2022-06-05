#ifndef Q2_H
#define Q2_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<regex>
#include<vector>

namespace q2
{

struct Patient
{
	Patient(const std::string& _name, const std::string& _lastname, const size_t& _age, const size_t& _smokes, const size_t& _area_q, const size_t& _alkhol)
        : name { _name + " " + _lastname }
        , age { _age }
        , smokes { _smokes }
        , area_q { _area_q }
        , alkhol { _alkhol }

	std::string name;
	size_t age;
	size_t smokes;
	size_t area_q;
	size_t alkhol;
};

static std::vector<Patient> read_file(std::string filename)
{
	// reading from file and store in txt variable
	std::ifstream file(filename);
	std::stringstream  buffer ;
	buffer << file.rdbuf();
	std::string txt = buffer.str() ;

	// regex pattern created with help of lung_cancer.csv file
	std::regex pattern(R"((\w+)\ ?,(\w+)\ ?,(\d+)\,(\d+)\,(\d+)\,(\d+))");
	std::smatch match ; // match is a container for the results of the regex_search function

	std::vector<Patient> patients; 

	//while loop to search the pattern in txt
	while(std::regex_search(txt , match , pattern))
	{
		Patient temp{} ; // temp is a temporary variable to store the data of each row

		std::string firstname{match[1]} ;
		std::string lastname{match[2]} ;
		temp.name = firstname + " " + lastname ;

		temp.age = std::stoi(match[3]) ;
		temp.smokes = std::stoi(match[4]) ;
		temp.area_q = std::stoi(match[5]) ;
		temp.alkhol = std::stoi(match[6]) ;

		// push the data of each row into patients vector
		patients.push_back(temp) ;
		// erase the data of each row from txt
		txt = match.suffix().str() ;
	}
	return patients ;

}
// function to calculate the probability of lung cancer by sorting the patients vector with README.md formula :)
static void sort(std::vector<Patient> &patients)
{
	std::sort(patients.begin() , patients.end() , 
	[](Patient inp1 , Patient inp2)
	{return (3*inp1.age + 5*inp1.smokes + 2*inp1.area_q + 4*inp1.alkhol) > (3*inp2.age + 5*inp2.smokes + 2*inp2.area_q + 4*inp2.alkhol) ;}) ;
}

}

#endif //Q2_H
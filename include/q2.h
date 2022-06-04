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
	std::string name;
	size_t age;
	size_t smokes;
	size_t area_q;
	size_t alkhol;
};

static std::vector<Patient> read_file(std::string filename)
{

	std::ifstream file(filename);
	std::stringstream  buffer ;
	buffer << file.rdbuf();
	std::string txt = buffer.str() ;
	std::regex pattern(R"((\w+)\ ?,(\w+)\ ?,(\d+)\,(\d+)\,(\d+)\,(\d+))");
	std::smatch match ;

	std::vector<Patient> patients;

	while(std::regex_search(txt , match , pattern))
	{
		Patient temp{} ;

		std::string firstname{match[1]} ;
		std::string lastname{match[2]} ;
		temp.name = firstname + " " + lastname ;

		temp.age = std::stoi(match[3]) ;
		temp.smokes = std::stoi(match[4]) ;
		temp.area_q = std::stoi(match[5]) ;
		temp.alkhol = std::stoi(match[6]) ;

		patients.push_back(temp) ;
		txt = match.suffix().str() ;
	}

	return patients ;

}

static void sort(std::vector<Patient> &patients)
{
	std::sort(patients.begin() , patients.end() , [](Patient inp1 , Patient inp2){return (3*inp1.age + 5*inp1.smokes + 2*inp1.area_q + 4*inp1.alkhol) > (3*inp2.age + 5*inp2.smokes + 2*inp2.area_q + 4*inp2.alkhol) ;}) ;
}



}

#endif //Q2_H
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

#include <string>
#include <vector>







int main () {

std::string from, to;

from = "D:\\data\\input.txt";
to = "D:\\data\\output.txt";

std::ifstream is{from};
std::ofstream os {to};

std::istream_iterator<std::string> ii{is};
std::istream_iterator<std::string> eos;
std::ostream_iterator<std::string> oi {os,"\n"};

std::vector<std::string>v(18);

std::copy(ii,eos,v.begin());

std::sort(v.begin(),v.end());
std::copy(v.begin(),v.end(),oi);


	
}
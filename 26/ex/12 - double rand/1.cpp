/*
Antonyuk I.V.

08/05/2018 
Belgorod

PPP C++ B.Stroustrup

ex. 26.12

*/


#include		<		random		>
#include		<		algorithm	>
#include		<		iostream	>		
#include		<		chrono		>	
#include		<		std_lib_facilities.h>	
#include		<		map			>

using namespace std;


double rand_double(double min, double max){
	
	static default_random_engine ran;
	
	
	
	return uniform_real_distribution<>{min,max}(ran);
	
}

string rand_string(int max, int min){
	
	string s;
	int curr_size = randint(max,min);
	
	for (int i = 0 ; i < curr_size; ++i)
	{
		s += '*';
	}
	
	
	
	return s;

}

int main(){
	
	
	auto t1 = chrono::system_clock::now();
	
	map<string,int>d;
	
	int number = 500000;
	
	for (int i =0; i < number; ++i){
		d[rand_string(0,100)]++;
	}
	
	//sort(d.begin(),d.end());
	
	auto t2 = chrono::system_clock::now();
	
	int t = chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
	cout << "time gerenate and sort " << number << " string elem is : " << t << '\n' ;
	
	char end;
	cin >> end;
}
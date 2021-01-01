#include <std_lib_facilities.h>

int main () {

int point = 1;
int num = 0;
vector<int>points;

while (point!=0) {
cin >> point;
points.push_back(point);
}

while (num<points.size()) {
++num;
}
cout 	<< num << "\n"; 
int a = 0;
a=num%2;
cout 	<< a << "\n"; 
sort (points);

if ((num%2)-1==0)
cout	<< "Mediana of points = " 
	<< "\n"
	<< "("
	<< points[points.size()/2] 
	<< ";"
	<< points[(points.size()/2)+1]
	<< ")"
	<< '\n';
else 
cout 	<< "Mediana of points = " 
	<< "\n" 
	<< points[points.size()/2] 
	<< '\n';
keep_window_open ();
}



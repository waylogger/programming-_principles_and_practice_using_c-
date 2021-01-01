#include <std_lib_facilities.h>
int area (int x, int y)
{
if (x<=0 || y<=0) 
error ("-A");
return x*y;
} 

int framed_area (int x, int y)
{
constexpr int frame_width = 2;
if (x-frame_width<=0 || y-frame_width<=0)
error ("Oshibka ramki");
return (x-frame_width)*(y-frame_width);
}

int main () 
try
{
int x = 0;
int y = 0;
int z = 0;

cout << "Insert x, y, z\n" ;
cin >> x >> y >> z;
area(x,y);
framed_area (y,z);

int area1 = area(x,y);
if (area1<=0) error ("Otrizatelnaya ploshad");
//int area2 = framed_area (1,z);
//if (area2<0) error ("Otrizatelnaya\n");
int area3 = framed_area (y,z);
double ratio = area1/area3;


cout 	<< "ratio = " << ratio << "\n"
	<< "area1 = " << area1 << "\n"
	<< "area2 = " << area1 << "\n"
	<< "area3 = " << area3 << "\n";
}

catch (runtime_error e) 
{
	cout << e.what () << '\n';
	keep_window_open ("~");
}















#include<std_lib_facilities.h>
//setlocale(0,"");
const string open_error= "Cant open file\n";

class Point
{
	public:
	int x = 0;
	int y = 0;
	Point(int xx, int yy) : x(xx), y(yy) {}
	Point() {}
};
ostream& operator<< (ostream& os, const Point& p)
{
	return os << '(' << p.x << ':' << p.y << ')\n';
}
ostream& operator<< (ostream& os, const vector<Point>& p)
{
	for (int i =0;i<p.size();++i) os << '(' << p[i].x << ':' << p[i].y << ")\n";
	return os;
}
istream& operator>> (istream& is, Point& p)
{
	int x =0;
	int y =0;
	char ch1,ch2,ch3;
	is >> ch1 >> x >> ch2 >> y >>ch3;
	p = Point(x,y);
	return is;
}
void file_stream_in (vector<Point>&points, const string open_error)
{
	string iname;
	cin >> iname;
	ifstream ist {iname};
	if (!ist) error (open_error);
	for (Point p; ist >> p;) {points.push_back(p);}
	
}
void file_stream_out (const vector<Point>&points, const string open_error)
{
	string oname;
	cin >> oname;
	ofstream ost {oname};
	if (!ost) error (open_error);
	ost << points;
	
}
int main () 
{
	cout << "Insert 7 pair\n";
	vector<Point>original_points;
	vector<Point>processed_points;
	int x,y;
	Point p;
	for (int i =0; i<7;++i) 
	{
		cin >> x >> y; 
		p = Point(x,y); 
		original_points.push_back(p);
	}
	cout << "File name\n";
	file_stream_out(original_points,open_error);
	cout << "File name\n";
	file_stream_in(processed_points,open_error);
	cout << "Original \n" << original_points << '\n';
	cout << "Processed \n" << processed_points << '\n';
	if (original_points.size()!=processed_points.size()) error ("error size");
 	
	keep_window_open();
}

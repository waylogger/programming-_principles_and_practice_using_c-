#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

const vector<Point>grid() 
{
	vector<Point>lines;
	Point a,b,c,d;
	a = {0,0};
	b = {1500,0};
	c = {1500,1500};
	d = {0,1500};
	for (int i =0; i < d.y;i+=5)
	{
		lines.push_back(Point{a.x,i});
		lines.push_back(Point{b.x,i});
	}
	return lines;
}
Point p_of_int (const Point& p1, const Point& p2, const Point& p3, const Point& p4){
	int x1 = p1.x; 	int x2 = p2.x;
	int x3 = p3.x;	int x4 = p4.x;
	int y1 = p1.y;	int y2 = p2.y;
	int y3 = p3.y;	int y4 = p4.y;
	int x =0;		int y =0;
	double denom = ((y4 - y3)*(x2-x1) - (x4-x3)*(y2-y1));
	if (denom==0) return Point{0,0};
		pair<double,double>	u	
							(((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3))/denom,
							((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3))/denom);
	if (u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1) return Point{0,0};
	
	x = x1 + u.first*(x2 - x1);
	y = y1 + u.first*(y2 - y1);

	return Point{x,y};
}

void striping (const vector<Point>&grid, const vector<Point>& vertex)
{
	vector<Point>intersections;
	Point p = {0,0};
	int i =0;	int j =1;	int vi =0;
	fl_color(FL_BLUE);
	while (i<grid.size() && j<grid.size())
	{
		while (vi<vertex.size())
		{
			if (vi+1>vertex.size()-1) 	break;
			p = p_of_int(grid[i],grid[j],vertex[vi],vertex[vi+1]);
			if (p.x!=0 && p.y != 0) intersections.push_back(p);	
			++vi;			
		}
		i+=2;		j+=2;		vi=0;
	}
		intersections.erase(intersections.begin(),intersections.begin()+2);	
		intersections.erase(intersections.end()-2,intersections.end());
		i=0;		j=1;
		int x1=0;		int x2=0;		int y1=0;		int y2=0;
		int nx1 =0;		int ny1 =0;		int nx2 =0;		int ny2 =0;
		vector<Point>true_ins;
		int diff=99999;
		int itd1 = 0; //index to del 1
		int itd2 = 0; //index to del 2
		
		while (true)
		{
		while (i < intersections.size()-1  && j < intersections.size())	{
			x1 = intersections[i].x;
			y1 = intersections[i].y;
			x2 = intersections[j].x;
			y2 = intersections[j].y;
			
			if (diff>sqrt(pow(x2-x1,2)+pow(y2-y1,2))) {
				
				diff = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
				nx1 = x1;				nx2 = x2;
				ny1 = y1;				ny2 = y2;
				itd1 = i;
				itd2 = j;
			
				
			}
			i+=2;			j+=2;
		
		}
		fl_line(nx1,ny1,nx2,ny2);
		true_ins.push_back(Point{nx1,ny1});
		true_ins.push_back(Point{nx2,ny2});
		//intersections.erase(intersections.begin()+itd1);
		//intersections.erase(intersections.begin()+itd2);
		if (intersections.size()==0) break;
		
		}
		
		cout << nx1 << ' ' << ny1 << '-' << nx2 << ' ' << ny2 << '\n';
		
		
}
		
		
	



class Striped_closed_polyline : public Closed_polyline
{
	public:
	Closed_polyline::Closed_polyline;
	void draw_lines() const override;
};

void Striped_closed_polyline::draw_lines() const
try
{
	Closed_polyline::draw_lines();
	vector<Point>vertexs;
	for (int i =0; i < number_of_points();++i)
	{
		vertexs.push_back(point(i));
	}
	
	vertexs.push_back(Point{point(0).x,point(0).y});
	
	striping(grid(),vertexs);
	
}
	catch (exception& e)
	{
	cerr << e.what() << '\n';
	keep_window_open();
	}
	catch(...)
	{
	cerr << "Unknown error" << '\n';
	keep_window_open();
	}

int main ()
try
{
	Simple_window win{Point{500,10},1000,1000,"Kansas"};
	Striped_closed_polyline scp;
	scp.add(Point{400,400});
	scp.add(Point{700,100});
	scp.add(Point{900,400});
	scp.add(Point{700,200});

	
	
	
	

	scp.set_color(Color::red);

	win.attach(scp);
	win.wait_for_button();
}

catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open();
}
catch(...)
{
	cerr << "Unknown error" << '\n';
	keep_window_open();
}
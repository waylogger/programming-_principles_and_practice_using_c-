#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

struct Person
{
	Person(string fn, string sn, int a);
	Person() {}
	string read_name() const {return first_name+" "+second_name;}
	int read_age() const {return age;}
	private:
	string first_name;
	string second_name;
	int age;
	
	
};
Person::Person(string fn, string sn, int a) : first_name(fn), second_name(sn), age(a)
{
	if (age<0 || age > 150) error ("Age uncorrect");
	istringstream ist {first_name+second_name};
	for (char c; ist >> c;) 
	{
		switch(c)
		{
			case ';': case ':': case '[': case ']': case '*':
			case '&': case '^': case '%':  case '$': case '#': case '@':
			case '!':
			error ("Name uncorrect");
			default:
			break;
		}
		if (isdigit(c)) error ("Name uncorrect");
	}
}

istream& operator >> (istream& ist, Person& p)
{
	string first_name;
	string second_name;
	int age;
	ist >> first_name;
	if (!ist) error ("Cant read first name");
	ist >> second_name;
	if (!ist) error ("Cant read second name");
	ist >> age;
	if (!ist) error ("Cant read age");
	p = {first_name,second_name,age};
	return ist;
}

ostream& operator << (ostream& ost, const Person& p)
{
	ost << p.read_name() << '-' << p.read_age() << '\n';
	return ost;
}



int main () try {
vector<Person>ps;
Person p;
for (int i =0; i < 1; ++i)
{
cin >> p;
ps.push_back(p);	
}
for (int i =0; i < ps.size(); ++i)
	cout << ps[i] << '\n';

keep_window_open();



}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}
#include <iostream>
#include <string>


using namespace std;

struct God
{
	string name;
	string story;
	string transport;
	string weapon;
	God(const string& n, const string& s="",const  string& t="", const string& w="")
	: name(n), story(s), transport(t), weapon(w) { }
 };


class Link
{
	Link* prev;
	Link* succ;
	God* god;
	public:
	Link(God* g, Link* p = nullptr, Link* s = nullptr) : god{g}, prev{p}, succ{s} {}
	Link* insert(Link*p, Link*x);
	Link* add(Link*p, Link*x);
	Link* erase(Link*p);
	Link* find_name(Link*p, const string& s);
	Link* find_country(Link* p, const string& s);
	Link* advice(Link* p, int n);
	Link* next() {return succ;}
	Link* previous() {return prev;}
	Link* add_ordered(Link* p, Link* n);
	God* show_god() {return god;}
	Link* first();
	Link* last();
	void print_all();
	
};
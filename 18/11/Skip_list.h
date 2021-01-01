#include <D:\\Programms\\18\\11\\Link.cpp>



class Skip_list
{
	private:
	Link* list {nullptr};
	Link* find_place(Link* q);
	
	
	public:
	
	Skip_list(Link* q) : list{q} {}
	~Skip_list() {list->deleting();}
	
	
	
	
	
	
	Link* find(Link* q);
	void erase();
	
	void insert(Link* p);
	
	Link* get_list() const {return list->zero();}
	Link* get() const {return list;}
	void set_list(Link* q) {list = q;}
};






class SL_exc 
{
	private:
	string s;
	public:
	SL_exc(const string &b) : s{b} {}
	string what() const {return s;}
};
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum class AI
{
	add,insert
};
class Link
{
	private:
	Link* prev{nullptr};
	Link* succ{nullptr};
	Link* head{this};
	Link* up{nullptr};
	Link* down{nullptr};
	bool insert_add_permiss {false};
	
	int key{546};
	string v{"def"};
	
	void erasing(); //безвозвратное верховое удаление
	Link* erase(); //возвратное удаление нижнего уроня, кроме заголовка
	Link* build(Link* p);
	public:
	
	Link* insert(Link* p);
	Link* add(Link* p);
	
	Link* advice(int i);
	Link* add_level(AI ai);
	Link* erase_tower();
	Link* erase_header(); //удаляем заголовок и полностью уничтожаем список
	Link* deleting(); //полное удаление списка
	
	Link* find(const int& i);
	Link* find(const string& v);
	
	Link* insert_ordered(Link* p);
	Link* add_ordered(Link* p);
	void sort();
	
	Link() : prev{nullptr}, succ{nullptr}, key{54}, v{""} {}
	Link(const int& i, const string vv, Link* s = nullptr, Link* p = nullptr) : key{i}, v{vv}, succ{s}, prev(p) {}
	Link(const int& i) : key{i}, v{""} {}
	//~Link();
	
	Link(const Link& e);
	Link operator=(const Link& e);
	
	Link( Link&& e);
	Link operator=( Link&&e);
	
	Link* previous() const {return prev;}
	Link* next() const {return succ;}
	
	int what_key() const {return key;}
	string data() const {return v;}
	Link* get_head() const {return head;}
	Link* get_up() const {return up;}
	Link* get_down() const {return down;}
	Link* zero();
	Link* sub_zero();
	
	
	void set_next(Link* p) {succ = p;}
	void set_previous(Link* p) {prev = p;}
	void set_key(const int& i) {key = i;}
	void set_data(const string& s) {v = s;}
	void set_head(Link* p);
	
};


struct Link_exceptions
{
	string what;
	Link_exceptions(const string& s) : what{s} {}
	
};

























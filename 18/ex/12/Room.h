
#include <std_lib_facilities.h>
#include <D:\\Programms\\18\\12\\Action.cpp>


enum class Content
{
	bat,wampus,whole,none
};



class Room
{
	private:
	int num {1};
	Content cont {Content::none};
	Room* succ {nullptr};
	Room* prev {nullptr};
	Room* jump {nullptr};
	Room* add(Room* r);
	Room* advice (int i );
	Room* first_room();
	void loop();
	
	
	public:
	Room(int i) : num{i} {	}
	Room* find(const Room* r);
	Room* find(const Content r);
	Room();
	int get_number() const {return num;}
	Room* get_succ() const {return succ;}
	Room* get_prev() const {return prev;}
	Room* get_jump() const {return jump;}
	Room* get_curr()  {return this;}
	Content get_content() const {return cont;}
	void set_content(Content c) {cont = c;}
	Room* step_prev(){ return this->prev;};
	void step_succ(){Room* k = this; k = this->succ;};
	void step_jump(){Room* k = this; k = this->jump;};
	
};

struct Content_engine
{
	int wamp {0};
	int whole{0};
	int bat{0};
	int none{0};
	
	Content content_engine();
	Content_engine() : wamp(0), whole(0), bat(0), none(0) {};
	
};

class EX_ROOM
{
	private:
	string s;
	public:
	EX_ROOM(string ss) : s(ss) {}
	string what() const {return s;}
};
























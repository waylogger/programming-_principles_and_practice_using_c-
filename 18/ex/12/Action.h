

enum class Act
{
	shooting,moving,start
};

struct Token
{
	int num;
	char kind;
	
	Token () : num(0), kind('0') {};
	Token (int i, char k) : num(i), kind(k) {};
	Token (int i) : num(i), kind('8') {};
	Token (char k) : num(0), kind(k) {};
};


class Action
{
	private:
	Act act ;
	char point;
	int r1 {0};
	int r2 {0};
	int r3 {0};
	Action(Act a, int q1, int q2, int q3) : act(a), r1(q1), r2(q2), r3(q3) {}
	Action(char p) : point(p) {};
	
	public:
	Token get();
	Token get_act();
	Action() {}
	Action get_action();
	Action get_direction(Act c);
	
	Act to_do() const {return act;}
	int act1 () const {return r1;};
	int act2 () const {return r2;};
	int act3 () const {return r3;};
	
};




class EX_TOKEN
{
	string e;
	public:
	EX_TOKEN(string q) : e(q) {};
	string what() const {return e;};
};

class EX_ACTION
{
	string e;
	public:
	EX_ACTION(string q) : e(q) {};
	string what() const {return e;};
};
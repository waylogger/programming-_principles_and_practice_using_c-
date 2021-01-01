#include <D:\\Programms\\18\\12\\Room.cpp>


class Game : public Room
{
	public:
	Room* r {nullptr};
	Game();
	void play();
};

class EX_GAME
{
	string e;
	public:
	EX_GAME(string q) : e(q) {};
	string what() const {return e;};
};





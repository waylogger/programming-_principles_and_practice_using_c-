#include <D:\\Programms\\18\\12\\Room.h>



void end()
{
	char c;
	cout << "\nTime of work is - " << clock() << '\n';
	cin >> c;
}



void print_cave(Room* p, int i)
{
	for (int k = 0; k < i; ++k)
	{
		cout << p->get_number() << ' ';
		p = p->get_succ();
		if (!p) break;
	}
	cout << '\n';
}


Room* find_def(Room* r)
{
	srand(time(0));
	int i = randint(1,20);
	r = r->find(new Room{i});
	return r;
};

Room* find_def_and_safety (Room *r)
{
	r = find_def(r);
	while (r->get_content() != Content::none)
	{
		r = find_def(r);
	}
	return r;
}


void swap_content(Room* a, Room* b)
{
	Room* k = new Room{0};
	
	k->set_content(a->get_content());
	a->set_content(b->get_content());
	b->set_content(k->get_content());
	
}

















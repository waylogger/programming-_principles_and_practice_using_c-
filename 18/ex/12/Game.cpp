#include <D:\\Programms\\18\\12\\Game.h>

Room* way(Room* r, int i)
{
		if (i == r->get_prev()->get_number()) 
			return r->get_prev();
		else if (i == r->get_succ()->get_number()) 
			return r->get_succ();
		else if (i == r->get_jump()->get_number()) 
			return r->get_jump();
		else 
		{
			cout << i << " - ";
			throw EX_ROOM{"Room with this number not found"};
		}
}

void path_analysis(const Action& a, Room* r)
{
	if (a.to_do() != Act::shooting) throw EX_ROOM{"I can not analyze the trajectory of walking"};
	
	int a1 = a.act1();
	int a2 = a.act2();
	int a3 = a.act3();
	int rn = r->get_number();
	
	r = way(r,a1);
	if (a2 == a1) throw EX_ROOM{"Can not shoot back"};
	r = way(r,a2);
	if (a2 == a3 || a3 == a1) throw EX_ROOM{"Can not shoot back"};
	r = way(r,a3);
	
	cout << "Shooting is successful!\n";
	
}


void wampus_wake(Room* k)
{
	k = k->find(Content::wampus);
	int i = 0;
	srand(time(0));
	i = randint(1,3);
	if (i == 1)				swap_content(k,k->get_prev());
	else if (i == 2)		swap_content(k,k->get_succ());
	else if (i == 3)		swap_content(k,k->get_jump());
}



void introducing(Room* r)
{
		Room* r1 = r->get_prev();
		Room* r2 = r->get_succ();
		Room* r3 = r->get_jump();
		
		cout 	<< setw(40) << "Current room is - " 
				<<  r->get_number() << '\n';
		cout 	<< "Move or shoting to - \n" 
				<< r1->get_number() << ',' 
				<< r2->get_number() << ','
				<< r3->get_number() << '\n';
		cout 	<< setw(40) 
				<< "And i am :" 
				<< '\n';
		
		if (r1->get_content() != Content::none) {cout << setw(40) <<  r1->get_content() << '\n';}
		if (r2->get_content() != Content::none) {cout << setw(40) <<  r2->get_content() << '\n';}
		if (r3->get_content() != Content::none) {cout << setw(40) <<  r3->get_content() << '\n';} 
		if (r1->get_content() == Content::none
		&& r2->get_content() == Content::none
		&& r3->get_content() == Content::none)
			{cout << setw(40) <<  "In the quiet rooms quietly" << '\n';} 
}


void Game::play()
{
	
	int c = 0; 	Action s;
	int arrow = 5;
 	while (true)
	{
		
		Room* r1 = r->get_prev();
		Room* r2 = r->get_succ();
		Room* r3 = r->get_jump();
		introducing(r);
		
		while (true)
		try
		{
		s = s.get_action();
		switch(s.to_do())
			{
			case Act::moving:
				{
				if (s.act1() == r1->get_number()) r = r1;
				else if (s.act1() == r2->get_number()) r = r2;
				else if (s.act1() == r3->get_number()) r = r3; 
				else throw EX_GAME{"I cant find this room"};
				}
			break;
			case Act::shooting:
				{
				path_analysis(s,r);
	
				Room* k = r->find(new Room{s.act3()});
				if (k->get_content() == Content::wampus)
					{cout << setw(40) <<"WAMPUS IS DEAD, YOU ARE WIN!\n";return;}
				--arrow;
				wampus_wake(r);
				if (r->get_content() == Content::wampus) {cout << setw(40) <<"WAMPUS EAT YOU!\n";return;	}
				cout << "You are have - " << arrow << " of arrows left\n";
				if (arrow == 0) {cout << setw(40) <<"You have run out of arrows, the game over!\n";return;}

				}
			break;
			} 
			break;
		}
		catch (EX_GAME& e) {cerr << e.what() << '\n';};
		
		if (r->get_content() == Content::wampus){cout << setw(40) <<"WAMPUS EAT YOU!\n";return;	}
		if (r->get_content() == Content::whole)	{cout << setw(40) << "You fell into the pit!\n";	return;	}
		if (r->get_content() == Content::bat)	{cout << "Bats moved you\n";r = find_def_and_safety(r);}
		
	} 
}



void greetings()
{
	cout << "Hellow\n";
	cout << "I propose to play the game 1972 of release\n";
	cout << "\nWAMPUS HUNT\n";
	cout << "This is the first adventure game in the history of mankind\n";
	
	cout.width(50);
cout  << "\nFundamental rules:\n"
"1. Each room is connected to 3 others.\n"
"2. You can move or shoot;\n"
"3. Move is allowed only by 1 step, for example m:5\n"
"4. Shooting is allowed only on 3 rooms, not less and no more, for example s:5-6-7\n"
"5. Each room can contain 3 types of obstacles: pit, bats and vampus;\n"
"6. If you get into a room in which a pit, you fail and the game is over;\n"
"7. If you get into the room where the vampus is, then he eats you and the game is over;\n"
"8. If you enter a room in which bats are sitting, they take you to an accidental safe room;\n"
"9. When you get into the room, you get a warning about that in the next room;\n"
"10. Purpose of the game = to find and kill the vampus, for this you have a bow and 5 arrows. \n"
"If the arrows are over, then the game ends in defeat; To kill a vampus, 1 arrow is enough.\n"
"11. If you shoot by, then the vampus wakes up wherever he goes to sleep and goes to any other room that may be yours;\n" 
"\nGOOD LUCK\n";
}
Game::Game() : r{this->get_curr()}
{
	
	greetings();
	
	
	while (true) 
		try
	{
		int i =0;
		while (true)
		{
		cout << "Choose level\n";
		cin >> i;
		if (cin) 
		{
			clear_stream(cin);
			break;
		}
		else 
			{
				cin.clear();
				string s;
				cin >> s;
			}
		
		}
		for (int k = 0; k <= i; ++k)
		{
			r = new Room{};
		}
		play();
		cout << "Try again Y/N ?\n";
		while (true)
		{
			char c = 0;
			cin.get(c);
			cin.unget();
			string s;
			getline(cin,s);
			if (c == 'Y') {r = new Room{}; break;}
				else if (c == 'N') return;
				else cout << "Try again\n";
		}
		
	} 
	catch(EX_ROOM& e) {cerr << e.what() << '\n';};
	 
	
}
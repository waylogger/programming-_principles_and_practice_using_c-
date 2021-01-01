


#include <D:\\Programms\\18\\12\\Action.h>


void clear_stream(istream& ist)
{
	ist.unget();
	string s;
	getline(ist,s);
}


Token  Action::get() 
{
	
	char c = 0;
	cin.get(c);
	switch(c)
	{
		case ':': return Token{':'};
		case '-': return Token{'-'};
		case 's': return Token{'s'};
		case 'm': return Token{'m'};
		case 'Y': return Token{'Y'};
		case 'N': return Token{'N'};

		case '1': case '2': case '3': 
		case '4': case '5': case '6': 
		case '7': case '8':
		case '9':
		{
			cin.putback(c);
			int i = 0;
			cin >> i;
			return Token(i);
		}
		case '\n': return Token('f');
		default:
		{
			clear_stream(cin);
			throw EX_TOKEN{"Unknown charaster"};
		}
		
	}
}

void checking(char c, char f)
{
	if (c != f)
	{
			clear_stream(cin);
			if (c == ':') throw EX_ACTION{"Expected ':', repeat input"};
			else if (c == '8')throw EX_ACTION{"Expected is number of the room, repeat input"};
			else if (c == 'f')throw EX_ACTION{"Expected 'Enter' "};
			else if (c == '-')throw EX_ACTION{"Expected '-' - Arrows fly through 3 rooms, no less, no more, repeat input"};
	}
}

Action Action::get_direction(Act a)
{
	int b = 0;	int c = 0;	int d = 0;
	Token t = this->get();
		checking(':',t.kind);
	
	t = this->get();
		checking('8',t.kind);			
	
	if (a == Act::moving)
		{
			b = t.num;
			t = this->get();
			checking('f',t.kind);
			return Action {a,b,c,d};
		}
	else b = t.num;
		
	t = this->get();
		checking('-',t.kind);
	
	t = this->get();
		checking('8',t.kind);
			c = t.num;
	
	t = this->get();
		checking('-',t.kind);
	
	t = this->get();
		checking('8',t.kind);
			d = t.num;
			
	t = this->get();		
		checking('f',t.kind);
	return Action{a,b,c,d};

}






Action Action::get_action()
{
	while (true)
	try
	{
	Token t = this->get();
	switch (t.kind)
	{
		case 's':
		{
			return this->get_direction(Act::shooting);
		}
		break;
		case 'm':
		{
			return this->get_direction(Act::moving);
		}
		break;
		case 'f':
		{
			clear_stream(cin);
			throw EX_ACTION {"Please enter an action"};
		}
		default:
		{
			clear_stream(cin);
			throw EX_ACTION {"Unknown action"};
		}
		
	}
	
	return Action{};
	}
	catch (EX_TOKEN& e) { cerr  << e.what() << '\n';}
	catch(EX_ACTION& e) { cerr  << e.what() << '\n';};
	
	
	
	
	
}




















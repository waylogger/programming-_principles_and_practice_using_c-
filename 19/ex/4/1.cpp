#include <iostream>
#include <string>

using namespace std;


class Bad_link
{
	private:
	string s;
	public:
	Bad_link(string ss) : s(ss) {}
	
	string what() const {return s;}
};

template <typename T>
class Link
{
	private:
	Link* succ;
	Link* prev;
	T t;
	
	public:
	Link* add(Link* p);
	Link* add_ordered(Link* p);
	Link* insert(Link* p);
	Link* erase();
	Link* find(Link* p);
	Link* advice(int i);
	
	const T& get() const {return t;}
	Link* next() const {return succ;}
	Link* previous() const {return prev;}
	
	explicit Link(T tt, Link* s = nullptr, Link* p = nullptr) : t(tt), succ(s), prev(p) {}
	Link() : succ(nullptr), prev(nullptr), t(T()) {} ;
	//~Link() {delete succ;}
	
};



template<typename T>
Link<T>* Link<T>::add(Link<T>* p)
{
 	Link* n = this;
	if (!n) return p;
	if (!p) return n;
	
	if (n->succ)
	{
		n->succ->prev = p;
		p->succ = n->succ;
	}
	
	n->succ = p;
	p->prev = n; 
	
	return p;
	
}

template<typename T>
Link<T>* Link<T>::insert(Link<T>* p)
{
	Link* n = this;
	if (!n) return p;
	if (!p) return n;
	
	if (n->prev)
	{
		n->prev->succ = p;
		p->prev = n->prev;
	}
	
	n->prev = p;
	p->succ = n;
	
	return p;
}


template<typename T>
void print(Link<T>* p)
{
	if (!p) return;
	while (p)
	{
		cout << p->get() << '\n';
		p = p->next();
	}
}

template<typename T>
void smth_else(Link<T>* p)
try
{
	delete p;
	throw Bad_link{"erase()"};
}
catch(Bad_link& e)
{
	cerr << e.what() << '\n';
	char c;
	cin >> c;
}

template<typename T>
Link<T>* Link<T>::erase()
{
	Link* n = this;
	
	if (!n) return nullptr;
	
	if (n->prev && !n->succ)
	{
		n->prev->succ = nullptr;
		Link* q = n->prev;
		delete n;
		return q;
	}
	
	else if (!n->prev && n->succ)
	{
		n->succ->prev = nullptr;
		Link* q = n->succ;
		delete n;
		return q;
	}
	
	else if (!n->prev && !n->succ)
	{
		delete n;
		return nullptr;
	}
	
	else if (n->prev && n->succ)
	{
		n->prev->succ = n->succ;
		n->succ->prev = n->prev;
		Link* q = n->succ;
		delete n;
		return q;
	}
	
	
	smth_else(n);
	return nullptr;
	
	
	
}


template<typename T>
Link<T>* Link<T>::advice(int i)
{
	Link* n = this;
	if (!n) return n;
	if (i == 0) return n;
	while (i > 0)
	{
		--i;
		if (n->succ) n = n->succ;
		
	}
	
	while (i<0)
	{
		++i;
		if (n->prev) n = n->prev;
		
	}
	
	return n;
	
	
	
}

template<typename T>
Link<T>* Link<T>::find(Link<T>* i)

{
	Link* n = this;
	while (n)
	{
		if (n->t == i->t) return n;
		n = n->succ;
	}
	return nullptr;
}

int num(const char c)
{
	if (c == 'A' || c == 'a') return 1;
	else if (c == 'B' || c == 'b') return 2;
	else if (c == 'C' || c == 'c') return 3;
	else if (c == 'D' || c == 'd') return 4;
	else if (c == 'E' || c == 'e') return 5;
	else if (c == 'F' || c == 'f') return 6;
	else if (c == 'G' || c == 'g') return 7;
	else if (c == 'H' || c == 'h') return 8;
	else if (c == 'I' || c == 'i') return 9;
	else if (c == 'J' || c == 'j') return 10;
	else if (c == 'K' || c == 'k') return 11;
	else if (c == 'L' || c == 'l') return 12;
	else if (c == 'M' || c == 'm') return 13;
	else if (c == 'N' || c == 'n') return 14;
	else if (c == 'O' || c == 'o') return 15;
	else if (c == 'P' || c == 'p') return 16;
	else if (c == 'Q' || c == 'q') return 17;
	else if (c == 'R' || c == 'r') return 18;
	else if (c == 'S' || c == 's') return 19;
	else if (c == 'T' || c == 't') return 20;
	else if (c == 'U' || c == 'u') return 21;
	else if (c == 'V' || c == 'v') return 22;
	else if (c == 'W' || c == 'w') return 23;
	else if (c == 'X' || c == 'x') return 24;
	else if (c == 'W' || c == 'w') return 25;
	else if (c == 'Z' || c == 'z') return 26;
	
	return 999;
																										
}






struct God
{
	string name;
	string weapon;
	string transport;
	string history;
	
	God(string n, string h = "", string t = "", string w = "") : name(n), history(h), weapon(w), transport(t)
	{
		
	}
};



bool operator > (const string s1, const string s2)
{
	int a = 0;
	if (s1.size() > s2.size()) a = s2.size();
	else if (s1.size() < s2.size()) a = s2.size();
	else if (s1.size() == s2.size()) a = s2.size();
	
	for (int i =0; i < a; ++i)
	{
		int b = num(s1[i]);
		int c = num(s2[i]);
		if (b != c)
		{
			if (b < c) return true;
			else return false;
		}			
	}
	return false;
}

bool operator < (const string s1, const string s2)
{
	int a = 0;
	if (s1.size() > s2.size()) a = s2.size();
	else if (s1.size() < s2.size()) a = s2.size();
	else if (s1.size() == s2.size()) a = s2.size();
	
	for (int i =0; i < a; ++i)
	{
		int b = num(s1[i]);
		int c = num(s2[i]);
		if (b != c)
		{
			if (b > c) return true;
			else return false;
		}			
	}
	return false;
}

bool operator > (God g1, God g2)
{
	if (g1.name > g2.name) return true;
	return false;
}

bool operator < (God g1, God g2)
{
	if (g1.name < g2.name) return true;
	return false;
}

template <typename T>
bool is_ordered(Link<T>* p)
{
	while (p->next())
	{
		if (p->get() < p->next()->get()) return false;
		p = p->next(); 
	}
	return true;
}


template<typename T>
void not_on_order(Link<T>* p)
try
{
	throw Bad_link{"not ordered\n"};
}
catch(Bad_link& e)
{
	cerr << e.what() << '\n';
}

template<typename T>
Link<T>* Link<T>::add_ordered(Link<T>* p)
{
	Link* n = this;
	if (!n) return p;
	if (!p) return n;
	
	if (!is_ordered(n)) not_on_order(n);
	
	if (n->get() < p->get()) 
	{
		return n->insert(p);
	}
	
	
	else if (n->get() > p->get())
	{
		while (n->get() > p->get())
		{
			if (!n->succ) 
			{
				return n->add(p);
			}
			n = n->succ;
		}
		 return n->insert(p);
	}
 
	return n->add(p);
}


ostream& operator << (ostream& ost, God g1)
{
	cout << g1.name << " - " << g1.history;
	return ost;
}

int main ()
{

Link<God>* g = nullptr;
g = g->add (new Link<God>{God{"Zeus","Greece"}});
g = g->add (new Link<God>{God{"Hera","Greece"}});
g = g->add (new Link<God>{God{"Afina","Greece"}});
g = g->add (new Link<God>{God{"Gefest","Greece"}});
g = g->add (new Link<God>{God{"Appolon","Greece"}});
g = g->add (new Link<God>{God{"Artemida","Greece"}});
g = g->add (new Link<God>{God{"Poseidon","Greece"}});
g = g->add (new Link<God>{God{"Diana","Greece"}});
g = g->add (new Link<God>{God{"Demetra","Greece"}});
g = g->add (new Link<God>{God{"Germes","Greece"}});
g = g->add (new Link<God>{God{"Gestia","Greece"}});
g = g->add (new Link<God>{God{"Jupiter","Rome"}});
g = g->add (new Link<God>{God{"Mars","Rome"}});
g = g->add (new Link<God>{God{"Diana","Rome"}});
g = g->add (new Link<God>{God{"Up","Rome"}});
g = g->add (new Link<God>{God{"Atlant","Rome"}});
g = g->add (new Link<God>{God{"Minevra","Rome"}});
g = g->add (new Link<God>{God{"Venera","Rome"}});
g = g->add (new Link<God>{God{"Appolo","Rome"}});
g = g->add (new Link<God>{God{"Akvilon","Rome"}});
g = g->add (new Link<God>{God{"Uventa","Rome"}});
g = g->add (new Link<God>{God{"Trivia","Rome"}});
g = g->add (new Link<God>{God{"Plunt","Rome"}});
g = g->add (new Link<God>{God{"Plunt","Rome"}});

g = g->add (new Link<God>{God{"Thor","Norway"}});
g = g->add (new Link<God>{God{"Batild","Norway"}});
g = g->add (new Link<God>{God{"Bragi","Norway"}});
g = g->add (new Link<God>{God{"Hed","Norway"}});
g = g->add (new Link<God>{God{"Vidar","Norway"}});
g = g->add (new Link<God>{God{"Vali","Norway"}});
g = g->add (new Link<God>{God{"Ull","Norway"}});
g = g->add (new Link<God>{God{"Nerd","Norway"}});
g = g->add (new Link<God>{God{"Freia","Norway"}});
g = g->add (new Link<God>{God{"Loki","Norway"}});
g = g->add (new Link<God>{God{"Odin","Norway"}});
g = g->add (new Link<God>{God{"Velund","Norway"}});

g = g->advice(-500);

Link<God>* greese = nullptr;
Link<God>* norway = nullptr;
Link<God>* rome = nullptr;



 while (g)
{
	if (g->get().history == "Norway") 
	{
		norway = norway->advice(-500);
		norway = norway->add_ordered(new Link<God>{g->get()});
	}
 	else if (g->get().history == "Rome") 
	{
		rome = rome->advice(-500);
		rome = rome->add_ordered(new Link<God>{g->get()});
		
	}
	else if (g->get().history == "Greece") 
	{
		greese = greese->advice(-500);
		greese = greese->add_ordered(new Link<God>{g->get()});
	} 
	g = g->next();
}
 

	norway = norway->advice(-500);
	greese = greese->advice(-500);
	rome = rome->advice(-500);
	print (norway);
	print (greese);
	print (rome);

	char c;
	cin >>c;
	
};


















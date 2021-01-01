#include <D:\\Programms\\18\\12\\Room_help.cpp>

Content Content_engine::content_engine()
{
	srand(time(0));
	int i = randint(1,4);
	if (i == 2 && this->wamp > 0 ) ++i;
	if (i == 3 && this->bat > 1) ++i;
	if (i == 4 && this->whole > 1) ++i;
	if (i > 4) i = 1;
	switch (i)
	{
		case 1: 
		{
			++this->none;
			return Content{Content::none};
		}
		case 2:
		{
			++this->wamp;
			return Content{Content::wampus};
		}
		
		case 3:
		{
			++this->bat;
			return Content{Content::bat};
		}
		
		case 4:
		{
			++this->whole;
			return Content{Content::whole};	
		}
	}
	 return Content{Content::none};
}

	/*
	Алгоритм добавления комнаты
	
	Если и текущий и аргумент - нули, то генерируем исключения
	Если текущий - нулевой, то возвращаем аргумент и наоборот.
	
	Если есть следующая комната после текущего, то переводим указатели
	Инициализируем указатели для прыжка на 2 назад для аргумента
	и для находящегося на 2 назад на аргумент
	
	Следующий текущего указывает на аргумент
	Предыдущий аргумента указывает на текущий
	*/
Room* Room::add(Room* p)
{

	Room* n = this;
	if (!n && !p) throw EX_ROOM {"Room* Room::add(Room* p) - !n && !p"};
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
/*
Алгоритм создания петли

Если хоть один указатель - нулевой, то генерируем исключение
Берем два текущих указателя и один перематываем до упора назад
Последующий первого указывает на перемотанный второй

Переводим указатали для прыжка и обратного прыжка для трех последних элементов в цепи
Первый переводится на 3 сначала
Второй с конца переводится на 2 сначала
Третий с конца переводится на первый в цепи



*/
void Room::loop()
{
	Room *r = this,*k = this;
	while (k->prev) k = k->prev;
	if (!k) throw EX_ROOM{"void Room::loop() - k is null"};
	if (!r) throw EX_ROOM{"void Room::loop() - r is null"};
	r->succ = k;
	k->prev = r;
}


/*
Алгорити перемотки пещеры на заданное число шагов
Аналог Link::advice(int i);
*/

Room* Room::advice(int i)
{
	Room* t = this;
	if (!t) throw EX_ROOM{"advice(int i) - !this"};
	for (;i > 0; --i)
	{
		if (t->succ) t = t->succ; 
	}
	
	for (; i < 0; ++i)
	{
		if (t->prev) t = t->prev; 
	}
	return t;	
}

/*
Конструктор по умолчанию
Создается карта по топологии додэкадра
Карта имеет 3 уровня циклов
в первом 5 комнат
втором - 10 
нижнем 5

Каждая комната первого уровня прыжком ведет вниз на 1 уровень
Каждая четная комната второго уровня прыжком ведет на 1 уровень,
а нечетная на нижний уровень
Каждая функция нижнего уровня ведет на 2 уровень

Не знаю насколько все криво сделано, работаем пошагово, см комментарии.
*/

Room::Room()
{
	
	Room* q  = this;
	Content_engine ce;
	q ->cont = Content::none;
		for (int i =2; i <=5;++i)
		{
			q = q->add(new Room{i}); //создаем комнаты 1 уровня
			q->cont = ce.content_engine();
		}
	q->loop(); // замыкаем цикл
	q->jump = new Room{6}; //добавляем первый элемент 2 уровня
	q->jump->jump = q; //обратный прыжок
	q = q->jump; //переходим на 2 уровень
		for (int i = 7; i <=15;++i) //добавляем элементы второго уровня
		{
			q = q->add(new Room{i});
			q->cont = ce.content_engine();
				if (q->num%2 == 0) 
				{
					q->jump = q->prev->prev->jump->prev; //инициализируем прыжки четных комнат
					q->prev->prev->jump->prev->jump = q;
					
				}
		}
	q->loop();// замыкаем цикл
	q->jump = new Room{16};//добавляем первый элемент 3 уровня
	q->jump->jump = q;//обратный прыжок
	q = q->jump; //переходим на 3 уровень
		for (int i = 17; i <=20; ++i)
		{
			q = q->add(new Room{i}); //добавляем элементы третьего уровня
			q->cont = ce.content_engine();
			q->jump = q->prev->jump->succ->succ; //инициализируем прыжки на нечетный комнаты второго уровня
			q->prev->jump->succ->succ->jump = q;
			
		}
	q->loop();
	
	
}

ostream& operator<< (ostream& ost, Content c)
{
	
	if (c == Content::none) ost << "Empty";
	else if (c == Content::bat) ost << "I hear a bat!!!";
	else if (c == Content::wampus) ost << "I smell a wampus!!!";
	else if (c == Content::whole) ost << "I feel the wind!!!";
	return ost;
	
	
}

Room* Room::find(const Room* r)
{
	Room* k = this;
	k = k->first_room();
	if (r->num > 20 || r->num <= 0) throw EX_ROOM {"No room with this number"};
	while (true)
	{
		if (k->num == r->num) return k;
		if (k->num == 20) 
		{
			k = this;
	
		} 
		
		if (k->succ->num < k->num)
		{
			k = k->jump;
		}
		else k = k->succ;
		
	}
	return 0;
}

Room* Room::find(const Content r)
{
	Room* k = this;
	k = k->first_room();
	while (true)
	{
		if (k->cont == r) return k;
		if (k->num == 20) 
		{
			k = this;
	
		} 
		
		if (k->succ->num < k->num)
		{
			k = k->jump;
		}
		else k = k->succ;
		
	}
	return 0;
}


Room* Room::first_room()
{
	Room* r = this;
	
	while (r->num != 1)
	{
		r = r->prev;
		if (r->prev->num < r->num) r = r->jump;
	}	
	
	return r;	
}










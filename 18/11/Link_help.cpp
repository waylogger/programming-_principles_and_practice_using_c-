/*
Содержит вспомогательные фукнции к Link

*/
void end()
{
	cout << '\n';
	cout << "Time of working process is - ";
	cout << clock() << '\n';
	cout << "Press eny key for exit\n";
	char c;
	cin >> c;
}

enum class Direction
{
	back,forward,up,down
};
 
void print_back(Link*p)
{
		if (!p) return;
		
		while (p)
			{
			cout.width(4);
			cout << p->what_key();
			if (p->data() != "") cout << '-' << p->data() << ' ';
			else cout << ' ';
			p = p->previous();
		}
}

void print_forward(Link*p)
{
		if (!p) return;
		while (p)
			{
			cout.width(4);
			cout << p->what_key();
			if (p->data() != "") cout << '-' << p->data() << ' ';
			else cout << ' ';
			p = p->next();
		}
}

void print_up(Link* p)

{
	if (!p) return;
	
while (p)
{
	cout.width(4);
	cout  << p->what_key();
	if (p->data() != "") cout << '-' << p->data() << '\n';
	
	p = p->get_up();
}
	
}

void print_down(Link* p)

{
	if (!p) return;
	while (p)
	{
		cout.width(4);
		cout << p->what_key();
		if (p->data() != "") cout << '-' << p->data() << '\n';
		p = p->get_down();
	}
	
}


/*
Алгоритм печати
Все просто, какую переменную класса Direction передали, в такую сторону и печатаем
*/
void print(Link* p, Direction d)


{
		if (!p) return;
		int i =0;
	switch(d)
	{
		case Direction::forward:
		print_forward(p);
		return;
		
		case Direction::back:
		print_back(p);
		return;
		
		case Direction::up:
		print_up(p);
		return;
		case Direction::down:
		print_down(p);
		return;

	}

}

void print(Link* p)
{
	int i =0;
	if (!p) return;
	while (p)
	{
		cout << ++i ;
		cout.width(4);
		cout << " : ";
		
		print(p,Direction::forward);
		cout << '\n';
		p = p->get_down();
	}
	
}


int calc_nodes(Link* p)
{
	if (!p) return 0;
	int i =1;
	while (p->next())
	{
		++i;
		p = p->next();
	}
	return i;
}

/*
Алгоритм вычисления разницы между ключами указателей
Если какой-либо из указателей равен нулю, то генерируем соответствующее исключение

Сфера применения функции - вычисление разницы между указателями, чтобы опредилить насколько
они будут далеко друг от друга стоять в упорядоченном списке
Мы искходим из того, то "n" всегда больший ключ, чем "p"

При
Если "p" отрицателен, то возвращаем сумму ключей;
Если "p" равен или больше нуля, то возвращаем разницу ключей

*/

int difference_of_keys(const Link* n, const Link* p)
{

if (!n || !p) throw Link_exceptions{"difference_of_keys somes of arg is null"};

if (p < 0) return n->what_key()+p->what_key();
else  return n->what_key()-p->what_key();

throw Link_exceptions{"difference_of_keys - somes wrong"};
return 0;
}

/*
Алгоритм поиска ближайшего большего ключа
Тут нас интересуют только те случаи, когда "p" меньше "n"
Если мы попытаемся искать в нулевом списке или нулевой элемент, то нужно сгенерировать исключение

Предполагается, что "n" больше "p"
Если "n" != 0 и "p" != 0, то начинаем искать наименьшую разницу между ключами данных узлов

Вычисляем разницу "n" и "p", 
Если если "n" больше  или равно "p"" записываем разницу в переменную "dif", одновременно сохраняем найденный "n"
Сдвигаем "n" вправо,
повторяем вычисления, при этом записываем только ту разницу, которая меньше уже сохраненный

Возвращаем сохраненный буффер


*/

Link* closer_and_more_of(Link* n, Link* p)
{
	if (!n || !p) throw Link_exceptions{"closer_and_more_off :: zero"};
	int dif = 2000000;
	Link* buffer = nullptr;
	
	while (n)
	{
		int d = 2000000;
		if 		(n->what_key() >= p->what_key())  	d = difference_of_keys(n,p);
		if (d < dif)
		{
			dif = d;
			buffer =n;
			
		}
		n = n->next();
	}
	return buffer;
	
}
/*
Алгоритм поиска ближайшего меньшего ключа

Тут нас интересуют только те случаи, когда "p" больше "n"
Если мы попытаемся искать в нулевом списке или нулевой элемент, то нужно сгенерировать исключение

Предполагается, что "n" меньше "p"
Если "n" != 0 и "p" != 0, то начинаем искать наименьшую разницу между ключами данных узлов

Вычисляем разницу "n" и "p", 
Если если "n" больше  или равно "p"" записываем разницу в переменную "dif", одновременно сохраняем найденный "n"
Сдвигаем "n" вправо,
повторяем вычисления, при этом записываем только ту разницу, которая меньше уже сохраненный

Возвращаем сохраненный буффер


*/
Link* closer_and_less_of(Link* n, Link* p)
{
	if (!n || !p) throw Link_exceptions{"closer_and_less_off :: zero"};
	int dif = 2000000;
	Link* buffer = nullptr;
	while (n)
	{
		int d = 2000000;
		if 		(n->what_key() < p->what_key())  	d = difference_of_keys(p,n);
		if (d < dif)
		{
			dif = d;
			buffer = n;
		}
		n = n->next();
	}
	return buffer;
	
}


/*
Алгоритм поиска ближайшего ключа
Тут нас интересуют только те случаи, когда "p" больше "n"
Если мы попытаемся искать в нулевом списке или нулевой элемент, то нужно сгенерировать исключение

Вычисляем ближайшее большее, если есть, то возвращаем его, если нет, то ищем и возвращаем ближайшее меньшее
Очень жутко выглядящая функция играет очень важную роль, она определяют ближайший элемент для возврата в ряду 
одинаковых ключей
Нас они интересуют, если вставляемый элемент больше, чем одинаковый в ряду.
Если он меньше, то нам не важно сколько одинаковых стоит в ряд, мы просто вставляем перед первым.
Когда же вставляемый больше, мы должны вставить его после самого последнего в одинаковом ряду.
Поэтому, если b инициализирован, а "a" - нет, у него есть последователь и их ключи равны, то мы сдвигаем b до последнего одинакового
в ряду, его и возвращаемю
*/

Link* closer_for_insert(Link* n, Link* p)
{
	if (!n || !p) throw Link_exceptions{"closer_for_insert :: zero"};
	
	Link* a = closer_and_more_of(n,p);
		
		if (!a)
	{
		Link* b = closer_and_less_of(n,p);
		while (b->next() && (b->what_key() == b->next()->what_key())) b = b->next();
		return b;
	}
	else return a;	
	
	throw Link_exceptions{"closer_to :: something wrong"};
}

/*
Тот же самый алгоритм, только приоритет отдается ближайшему меньшему ключу
*/
Link* closer_for_add(Link* n, Link* p)
{
	if (!n || !p) throw Link_exceptions{"closer_for_add :: zero"};
	
	Link* a = closer_and_less_of(n,p);
		
		if (a)
	{
		while (a->next() && (a->what_key() == a->next()->what_key())) a = a->next();
		return a;
	}
	
	Link* b = closer_and_more_of(n,p);
	if (!b) throw Link_exceptions{"closer_for_add :: something wrong with second"};
	return b;
	throw Link_exceptions{"closer_for_add :: something wrong"};
}

bool is_ordered(Link* p)
{
	if (!p) return false;
	
	bool k = true;
	while (p->next())
	{
		if (p->what_key() > p->next()->what_key())
		{
			cout <<  p->what_key() <<  " - more then - " << p->next()->what_key() << '\n';
			k = false;
		}			
		p = p->next();
	}
	return k;
}


/*
Функция замены двух узлов
Если хоть один из узлов равен нулю, то генерируем исключение

Если нет, то выполняем глубокое копирование "n" в "buffer"
Передаем значения из "р" в "n"
Передаем значения из "buffer" в "р"

*/
void swap(Link* n, Link* p)
{
Link* buffer = new Link{};
buffer->set_key(n->what_key());
buffer->set_data(n->data());

n->set_key(p->what_key());
n->set_data(p->data());

p->set_key(buffer->what_key());
p->set_data(buffer->data());
	
}


/*
Алгоритм изменения ключа по вертикали
Если текущий нулевой, то генерируем исключение
изменяем текущее значение ключа
Пока есть что сверху - изменяем значение ключа, что сверху


*/

void change_tower_keys(Link* n, const int& i)
{
	if (!n) throw Link_exceptions{"void change_tower_keys(Link* n, const int& i) - n is null"};
	
	n->set_key(i);
	while (n)
	{
		n=n->get_up();
		if (n) n->set_key(i);
	}
}



/*
Алгорим нахождения последнего этажа
Если "p" нулевой, то генерируем исключение

Если нет, то проверяем есть ли верхний узел,
если нет, то возвращаем "р"
Если есть, то сдвигаем "p" ввехр и повторяем проверку
так до конца
*/

Link* last_floor(Link* p)
{
	if (!p) throw Link_exceptions{"Link* last_floor(Link* p) - p is null"};
	while (p->get_up()) p = p->get_up();
	return p;
}

/*
с первым этажем все так же, только наоборот
*/

Link* first_floor(Link* p)
{
	if (!p) throw Link_exceptions{"Link* last_floor(Link* p) - p is null"};
	while (p->get_down()) p = p->get_down();
	return p;
}


/*
Алгоритм последнего в ряду
Пока есть вправо, двигаем вправо
*/
Link* last(Link*p)
{
	if (!p) throw Link_exceptions{"Link* last(Link*p) - arg is null"};
	
	while (p->next()) p = p->next();
	return p;
}



/*
Алгоритм выдачи разрешений на удаление узла
Выполняется только через erase() и только если нижних узлов нет;

Если "!n", то генерируем исключение
Если "n->down", то генерируем исключение

Идем вверх и переводим erase_permiss в состояние true
*/
/* 
void permiss_to_erase(Link* p)
{
if (!p) throw Link_exceptions{"permiss_to_erase(Link* p) - arg is null"};
if (p->get_down())	Link_exceptions{"permiss_to_erase(Link* p) - permission denied - level is not first"};

while (p)
{
	p->set_erase_permiss(true);
	p = p->get_up();
}
} */





















































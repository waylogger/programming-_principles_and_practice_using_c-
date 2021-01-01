#include <D:\\Programms\\18\\11\\Link.h>
#include <D:\\Programms\\18\\11\\Link_help.cpp>

const char go_to_back = 'a';
const char go_to_forward = 'b';
/*
Алгоритм вставки
Если n = 0, то возвращаем p;
Если p = 0, то возвращаем n;

Если у n есть предшественник, то его (предшественника) указатель на следующий элемент 
переводится на p, а указатель на предыдущий эллемент p переводится на предшественника n;

Затем, а так же, если у n нет предшественника,
то указатель на следующий элемент p переводится на n, 
а указатель на предыдущий элемент n переводится на p; 

*/

/*
Поддержка заголовка
Необходимо обрабатывать 2 случая:
1. Если вставка осуществляется вначало списка, то 
вызывается функция set_head(), которая меняе заголовок по всему списку
2. Если не вначало, то просто копируем заголовок "n"

Так же необходимо менять заголовки всех уровней, что выше текущего
Для этого сначала меняем заголовки в данном списке - set_head();
После этого берем верхний элемент предыдущего заголовка "p->succ->up"
и переводим его нижний узел "p->succ->up->down" на новый заголовок, а "up" заголовка
на "p->succ->up";
Теперь необходимо поменять старые значения ключей - функция set_tower_keys();
*/

/*
Вставка или добавление не может производтся не на первом уровне, поэтому если есть нижний уровень, то генерируем
исключение
Более того верхние уровни предназначены только для хранения ключей, поэтому передавать туда данные нельзя
Каждый раз при вызове вставки или добавления проверяется разрешение на добавление, переменная "insert_add_permiss"
По умолчанию такое добавление запрещено, но исключение генерируется только если наряду с запрещением у заголовка есть
нижний уровень

Втавки с нижнем уровнем разрешена только в функции add_level()
*/
Link* Link::insert(Link* p)
{
	Link* n = this;
	if (!n) return p;
	if (!n && !p) throw Link_exceptions{"Link* Link::add(Link* p) try return in nullptr"};
	if (!p) return n;
	n->insert_add_permiss = n->head->insert_add_permiss; //перемещаем разрешение из заголовка
	if (!insert_add_permiss && n->head->down) 
		throw Link_exceptions{"Link::insert(Link* p) - level diffrent by first"};
	
	if (n->prev)
	{
		n->prev->succ = p;
		p->prev = n->prev;
	}
	
	n->prev = p;
	p->succ = n;
	if (!p->prev)
	{
		p->set_head(p);
		if (p->succ->up)
		{
			p->succ->up->down = p;
			p->up = p->succ->up;
			p->succ->up = nullptr;
			change_tower_keys(p,p->key);
		}
	} 
	else p->head = p->succ->head;
	return p;
}

/*
Алгоритм добавления
Если n = 0, то возвращаем p;
Если p = 0, то возвращаем n;

Если у n есть указатель на последующий элемент, то его (последующего) предыдущий указатель переводтся на p;
Указатель на последующий элемент p переводится на на последующий указатель n


Затем, а так же, если у n нет последующего указателя, то
но последующий указатель n переводится на p,
а предыдущий указатель p переводится на n;
*/

/*
Поддержка передачи ключа
Все очень просто, перед возвратом меняем заголовок аргумента на заголовок this
*/

/*
Вставка или добавление не может производтся не на первом уровне, поэтому если есть нижний уровень, то генерируем
исключение
Более того верхние уровни предназначены только для хранения ключей, поэтому передавать туда данные нельзя
Каждый раз при вызове вставки или добавления проверяется разрешение на добавление, переменная "insert_add_permiss"
По умолчанию такое добавление запрещено, но исключение генерируется только если наряду с запрещением у заголовка есть
нижний уровень

Втавки с нижнем уровнем разрешена только в функции add_level()
*/
Link* Link::add(Link* p)
{
	Link* n = this;
	if (!n) return p;
	if (!n && !p) 
		throw Link_exceptions{"Link* Link::add(Link* p) try return in nullptr"};
	n->insert_add_permiss = n->head->insert_add_permiss; //перемещаем разрешение из заголовка
	if (!insert_add_permiss && n->head->down)
		throw Link_exceptions{"Link::add(Link* p) - level diffrent by first"};
	if (!p) return n;
	if (n->succ)
	{
		n->succ->prev = p;
		p->succ = n->succ;
	}
	
	n->succ = p;
	p->prev = n;
	p->head = n->head;
	
	
	return p;
	
}



/*
Алгоритм возвратного удаления на первом уровне списка


Если n = 0, то возвращаем 0;

Если у n нет ни последователя, ни предыдушего элемента, то так же возвращаем 0

Если у n нет последователя, но есть предшественник, то значит он последний. Тогда обнуляем последующий указатель
прелшественника n и возвращаем значение предшественника n;

Если у n нет предшественника, но есть последователь, то значит он первый.
Обнуляем предшественника последователя n;
Возвращаем значение последователя n;

Если у n есть и предшественник и последователь, 
то последователь предшественника n переводится на последователя n;
предшестевнник последоваетля n переводится на на предшественника n;


*/

/*
Поддержка заголовка

Передача заголовка нам нужна тогда мы удаляем первый, 
то возвращаем то что следом и вызываем функцию set_head();
*/

/*
Контроль доступа
Функция приватная, удаление допускается только на первом уровне

*/
Link* Link::erase()
{
	Link* n = this;
	if (!n) 
		throw Link_exceptions{"Link* Link::erase() - try erase null"};
	if (n->down) 
		throw Link_exceptions{"Link* Link::erase() - permiss denied"};
	
	
	if (!n->prev && !n->succ) 
	{
		delete n;
		return nullptr;
	}
	else if (!n->prev && n->succ)
	{
		n->succ->set_head(n->succ);
		if (n->up) 
		{
			n->up->down = n->succ;
			n->succ->up =n->up;
		}
		change_tower_keys(n->succ,n->succ->key);
		n->up = nullptr;
		n->succ->prev = nullptr;
		Link* q =n->succ;
		delete n;
		return q;
		
	}
	else if (n->prev && !n->succ)
	{
		n->prev->succ = nullptr;
		Link* q =n->prev;
		delete n;
		return q;
	}
	else
	{
		n->succ->prev = n->prev;
		n->prev->succ = n->succ;
		Link* q = n->succ;
		delete n;
		return q;
	}
}

/*
Алгоритм поиска по ключу
Если список пустой, то возвращаем 0;
Если ключ равен искомому, то возвращаем указатель на узел;
Если нет, то берем следующий узел;
Если следующего узла нет, то возвращаем ноль;
*/


Link* Link::find(const int& i)
{
	Link* n = this;
	if (!n) throw Link_exceptions{"Link* Link::find(Link* p) try find in nullptr"};
	
	while (n)
	{
		if (n->key == i) return n;
		else n = n->succ;
	}
	return nullptr;
}

/*
Алгоритм поиска по значению
Если список пустой, то возвращаем 0;
Если значение равно искомому, то возвращаем указатель на узел;
Если нет, то берем следующий узел;
Если следующего узла нет, то возвращаем ноль;
*/


Link* Link::find(const string& i)
{
	Link* n = this;
	if (!n) throw Link_exceptions{"Link* Link::find(Link* p) try find in nullptr"};
	
	while (n)
	{
		if (n->v == i) return n;
		else n = n->succ;
	}
	return nullptr;
}

/*
Алгоритм продвижения
Если n равен нулю, то возвращаем 0

Если q = 0, то возвращаем текущий узел;

Если q больше 0, то уменьшаем q пока оно не будет равно 0;
Вместе с этим сдвигаем текущий узел вправо;

Если q меньше 0, то увеличиваем q пока оно не будет равно 0ж
Одновременно сдвигаем текущий узел влево.

*/

Link* Link::advice(int q)
{
	Link* n = this;
	if (!n) throw Link_exceptions{"Cant advice nullptr"};
	if (q == 0) return n;
	else if (q > 0)
	{
		while (q != 0)
		{
			if (n->succ) n = n->succ;
			--q;
		}
		return n;
	}
	
	else if (q < 0) 
	{
		
		while (q != 0)
		{
			if (n->prev) n = n->prev;
			++q;
		}
		return n;
	}
	return n;
}






/*
Алгорит копирующего конструктора
Если мы копируем ноль, то this = 0;

Пока l != 0, добавляем значения в n

В конце меняем значения по умолчанию this
*/

Link::Link(const Link& l)
{
	
	Link* n = nullptr; 
	Link* pl = new Link{l.key,l.v,l.succ,l.prev};
	while (pl)
	{
		n = n->add(new Link{pl->key,pl->v});
		pl = pl->succ;
	}
	this->key = n->key;
	this->v = n->v;
	this->prev = n->prev;
	this->succ = n->succ;
}


Link Link::operator= (const Link& l)
{
	Link* n = nullptr; 
	Link* pl = new Link{l.key,l.v,l.succ,l.prev};
	while (pl)
	{
		n = n->add(new Link{pl->key,pl->v});
		pl = pl->succ;
	}
	this->key = n->key;
	this->v = n->v;
	this->prev = n->prev;
	this->succ = n->succ;
	
	return Link{this->key,this->v,this->succ,this->prev};
}



/*
Алгоритм перемещающего конструктора
Инициализируем указатель "d" данными и указателями аргумента
Определяем направление перемещения списка, если вперед нельзя, то идем назад, и наоборот
обнуляем обратный указатель
Обнуляем аргумент, чтобы избежать возврата адреса статической переменной в динамическую память

Сохраняем адрес "d" в "sd " 
Инициализируем "p" нулем

Пока "d" != 0
Добавляем в "p" текущий узел "d" (или вставляем)
Сохраняем B "sp" первый "р";
Передвигаем "d" вправо
или
Передвигаем "d" влево
Проверяем "d"
переносим данные "sp" в "this"

Если "d" = 0, то удалаем d через "sd"
*/

Link::Link(Link&& a)

{
	Link* d = new Link{a.key,a.v,a.succ,a.prev};
	char c = 0;
	if (!d -> succ) c = go_to_back;
	else if (!d->prev) c = go_to_forward;
	a.key = 0;
	a.v = "";
	a.prev = nullptr;
	a.succ = nullptr;

	Link* sd = d;
	Link* p = nullptr;
	Link* sp = nullptr;
	switch (c)
	{
		case go_to_forward:
		{
			while (d)
			{
			p = p->add(new Link{d->key,d->v});
			if (!p->prev) sp = p;
			d = d->succ;
			}
		break;
		}
		case go_to_back:
		while (d)
			{
			p = p->insert(new Link{d->key,d->v});
			if (!p->prev) sp = p;
			d = d->prev;
			}
	break;	
	}
	if (sp) 
	{
		this->key = sp->key;
		this->v = sp->v;
		this->succ = sp->succ;
		this->prev = sp->prev;
	}
	
		
	delete sd;
}


/*
Алгоритм перемещающего конструктора
Инициализируем указатель "d" данными и указателями аргумента
Определяем направление перемещения списка, если вперед нельзя, то идем назад, и наоборот
обнуляем обратный указатель
Обнуляем аргумент, чтобы избежать возврата адреса статической переменной в динамическую память

Сохраняем адрес "d" в "sd " 
Инициализируем "p" нулем

Пока "d" != 0
Добавляем в "p" текущий узел "d" (или вставляем)
Сохраняем B "sp" первый "р";
Передвигаем "d" вправо
или
Передвигаем "d" влево
Проверяем "d"
переносим данные "sp" в "this"

Если "d" = 0, то удалаем d через "sd"

Возвращаем разыменованный this

NB порядок перемещаемого списка обязательно должен быть сохранен
*/

Link Link::operator= (Link&&a)
{
	
Link* d = new Link{a.key,a.v,a.succ,a.prev};
	char c = 0;
	if (!d -> succ) c = go_to_back;
	else if (!d->prev) c = go_to_forward;
	a.key = 0;
	a.v = "";
	a.prev = nullptr;
	a.succ = nullptr;
	Link* sd = d;
	Link* p = nullptr;
	Link* sp = nullptr;
	switch (c)
	{
		case go_to_forward:
		{
			while (d)
			{
			p = p->add(new Link{d->key,d->v});
			if (!p->prev) sp = p;
			d = d->succ;
			}
		break;
		}
		case go_to_back:
		while (d)
			{
			p = p->insert(new Link{d->key,d->v});
			if (!p->prev) sp = p;
			d = d->prev;
			}
	break;	
	}
	if (sp) 
	{
		this->key = sp->key;
		this->v = sp->v;
		this->succ = sp->succ;
		this->prev = sp->prev;
	}
	delete sd;
	return *this;
}

/*
Алгоритм вставки по порядку
Вставка или добавление не может производтся не на первом уровне, поэтому если есть нижний уровень, то генерируем
исключение
Более того верхние уровни предназначены только для хранения ключей, поэтому передавать туда данные нельзя
Каждый раз при вызове вставки или добавления проверяется разрешение на добавление, переменная "insert_add_permiss"
По умолчанию такое добавление запрещено, но исключение генерируется только если наряду с запрещением у заголовка есть
нижний уровень

Втавки с нижнем уровнем разрешена только в функции add_level()


Базируется на вспомогательной функции closer_to(...);

Если "n" = 0, то возвращаем p, затем наоборот.

Инициализируем "n" упомянутой функцией closer_to(n,p);

Сравниваем "n" и "p"
Если n больше, то вызываем insert
Иначе вызываем add

Если что-то иное, то вызываем исключение


*/

Link* Link::insert_ordered(Link*p)
{
	Link* n = this;
	if (!n) return p;
	if (!p && !n) throw Link_exceptions{"Link* Link::insert_ordered(Link* p) try retutn nullptr"};
	if (!p) return n;
	if (!insert_add_permiss && n->head->down) 
		throw Link_exceptions{"Link::insert_ordered(Link* p) - level diffrent by first"};
	
	n = closer_for_insert(n,p);
	
	if (n->key >= p->key) 
	{
		return n->insert(p);
	}
	else if (p->key > n->key) 
	{
		return n->add(p);
	}
	throw Link_exceptions{"insert_ordered :: smth wrong"};
	
	return 0;
}

/*
Тот же insert_ordered, главное отличие в том, что в приоритете ближайшее меньшее значение
нашли его - вставили после него, не нашли - вставили перед списком
*/
Link* Link::add_ordered(Link* p)
{
	Link* n = this;
	if (!n) return p;
	if (!p && !n) throw Link_exceptions{"Link* Link::add_ordered(Link* p) try retutn nullptr"};
	if (!p) return n;
	if (!insert_add_permiss && n->head->down)
		throw Link_exceptions{"Link::add_ordered(Link* p) - level diffrent by first"};
	n = closer_for_add(n,p);
	
	if (n->key <= p->key) 
	{
	return n->add(p);
	}
		
	return n->insert(p);
}




/*
Алгоритм сортировки
Если узел нулевой, то генерируем исключение

Если нет следующего узла, то прекращаем выполнение функции
Вызываем функцию для определения упорядоченности списка
Если функция выдает истинное значение, то зачем продолжать? Прекращаем!!
Если ложное, то сохраняем начальный узел и сравниваем ключи текущего и следуюшего узла,  
если текущий больше или равен следующему, то просто сдвигаем текущий, предварительно проверив есть ли он
Если текущий меньше, то вызываем функцию перемещения значений
И сравниваем значения текущего узла и последующего, если функция swap() справилась, то двигаемся дальше
достигнув конца списка переходим вновь к началу и вызываем функцию для определения упорядоченности списка.
Так пока список не упорядочится

*/

void Link::sort()
{
	Link* e = this;
	if (!e) throw Link_exceptions{"Try sorting null"};
	else if (!e->next()) return;
	Link* se = e;
	while (true)
	{
		if (is_ordered(e)) return;
		while (e->next())
		{
			if (e->what_key() > e->next()->what_key()) swap(e,e->next());
			e = e->next();
		}
		e = se;
	}
}

/*
Алгоритм изменения ключа
Применяется ко всему списку от текущего положения

Если или аргумент или текущий узел = 0, то генерируем исключение

Если текущий узел не имеет последователя, то изменяем заголовок текущего и возвращаем текущий указатель
Если имеет, то изменяем текущий узел и передвигаем его вправо пока не достигнем последнего узла

По достижении последнего узла - меняем его заголовок и возвращаем его
*/

void Link::set_head(Link* p)
{
	Link* n = this;
	if (!n || !p) throw Link_exceptions{"set_head(Link* p - this or arg is null"};

	while (n->succ)
	{
		n->head = p;
		n = n->succ;
	}
	n->head = p;
}

/*
Алгоритм надстройки
!!!!!NB Эта функция находится в разделе private, вызываться она может только применительно к заголовку!!!!
и только через другую функци.
и только через другую функцию
Реализует ту же концепцию, что и функция add, но только для узлов связанных в цепочку "up->down"
Если нет "n", то возвращаем "р"
Если нет "р", то возвращаем "n"

Если у "n" уже есть уровень выше, то нижний указатель этого узла переводится на "р"
А верхний указатель "р" переводтся на нижний верхнего "n"

Далее как обычно, верхний "n" переводится на "p", 
а нижний "р" на "n"
*/


Link* Link::build(Link* p)
{
	Link* n = this;
	if (!n) return p;
	else if (!p && !n) throw Link_exceptions{"Link* Link::build(Link* p) try retutn nullptr"};
	else if (!p) return n;
	
	if (n->up)
	{
		n->up->down = p;
		p->up = n->up;
	}
	
	n->up = p;
	p->down = n;
	
	
	return p;
}

/*
Алгоритм надстройки узла
Для ключей, больших чем заголовок

Если "!a" || "!b", то генерируем исключение

Делее порядок работы алгорима зависит от того, есть верхний уровень у заголовка
Если есть, то мы просто долбавляем к нему "p" по порядку
Если верхнего уровня нет, то сначала добавляем верхний уровень к заголовку
и только затем добавляем к нему "p" по порядку

После чего устанавливаем вертикальную связь "р" и "n"

Елси мы вызываем функцию над заголовком, то после добавления возвращаем значение.
*/



Link* Link::add_level(AI ai)
{
	
	Link* n = this;
	Link* p = new Link{n->key};
	if (!n || !p) 
		throw Link_exceptions{"Link* Link::add_level() - !n || !p"};
	if (!n->head)
		throw Link_exceptions{"Link* Link::add_level() - cant find head"};
	if (n == n->head)
	{
		cout << n->key << '\n';
		throw Link_exceptions{"Link* Link::add_level() - cant build on head"};
	}
		
	if (n->up) 
		throw Link_exceptions{"Link* Link::add_level() - we have high level"};
	
	if (!n->head->up) n->head->build(new Link{n->head->key});
	if (!n->head->up)
		throw Link_exceptions{"Link* Link::add_level() - cant find head->up"};
	n->head->up->insert_add_permiss = {true}; // разрешаем вставку на верхнем уровне
	if (ai == AI::add) n->head->up->add_ordered(p);
	if (ai == AI::insert) n->head->up->insert_ordered(p);
	p->down=n;
	n->up = p;
	n->head->up->insert_add_permiss = {false};// запрещаем вставку на верхнем уровне
	return p;

}

/*
Алгоритм вычисления нулевого элемента

Все просто = возвращаем результат функции last_floor() в отношении заголовка
Если "n" нулевое, то генерируем исключение, потому что вызывая эту функцию мы предполагаем, что значение ненулевое

*/


Link* Link::zero()
{
	Link* n = this;
	if (!n) throw Link_exceptions{"Link* zero() - this is null"};
	return last_floor(n->head);
}

/*
Алгоритм вычисления первого нижнего практически тот же, только возвращается функция first_floor();
*/

Link* Link::sub_zero()
{
	Link* n = this;
	if (!n) throw Link_exceptions{"Link* sub_zero() - this is null"};
	return first_floor(n->head);
}




/*
Алгоритм безвозвратного удаления
Применияется для очистки верхний списков
Если текущего нет, то генерируем исключение
Если есть, то проверяем есть ли последующий("a") и предыдущий("с"), 
соответственно могут быть следующие комбинации

Если "!а" и "с", то элемент первый
Обрываем предыдущий указатель у "с", обрываем текущий и прекращаем выполнение функции.
Если "а" и "!с", то элемент последний
Обрываем следующий указатель у "а", обрываем текущий и прекращаем выполнение функции
Если "!а" и "!с", то узел единственный,
Обрываем его и прекращаем выполенение функции

Если "а" и "с", то аргумент по центру
Выполняем перехлест последующий "а" теперь "с"
предыдуший "с" теперь "а"
обрываем текущий
пекращаем выполнение функции
Если что-то другое, то генерируем исключение
*/

/*
Контроль доступа
Функция приватная, выполняется только если снизу есть еще один уровень
*/

void Link::erasing()
{
	Link* n = this;
	if (!n) 
		throw Link_exceptions{"void Link::erasing() - try erase null"};
	if (!n->down) 
		throw Link_exceptions{"void Link::erasing() - level is first"};
	
	if (n->succ && !n->prev)
	{
		n->succ->prev = nullptr;
		delete n;
		return;
	}
	else if (n->prev && !n->succ)
	{
		n->prev->succ = nullptr;
		delete n;
		return;
	}
	else if (!n->prev && !n->succ)
	{
		delete n;
		return;
	}
	else if (n->prev && n->succ)
	{
		n->prev->succ = n->succ;
		n->succ->prev = n->prev;
		delete n;
		return;
	}
	else throw Link_exceptions{"void Link::erasing() - smth wrong"};
	
	
}


/*
Удаление столбца


Если текущего нет, то генерируем исключение;

Если что-то есть, то переходим на самый верх, функция last_floor();

Цикл

Если снизу пусто, то выходим из цикла
Если что-то есть, то переводим указатель вниз
Удаляем верхний безвозвратным удалением erasing();

Конец цикла

Если ниже текущего ничего нет, то возвращаем функцию erase();
*/

/*
Контроль доступа
Единственное удаление, которое можно вызвать непосредственно
Вызывается только с первого списка
*/

Link* Link::erase_tower()
{
	Link* p = this;
	if(!p) throw Link_exceptions{"Link* Link::erase_tower() - erasing nullptr"};
	if (p->down) throw Link_exceptions{"Link* Link::erase_tower() - cant erase high level"};
	if (!p->prev) throw Link_exceptions{"Link* Link::erase_tower() - cant erase header"};
	
	p = last_floor(p);
	
	while (p->down)
	{
		
		p = p->down;
		if (p->up) p->up->erasing();
		p->up = nullptr;
		
	}
	return p->erase();
}

/*
Алгоритм удаления заголовка
Тождественнен erase_tower(), но позволяет удалить только заголовок и только если остальной список уже удален

*/
Link* Link::erase_header()
{
	Link* p = this;
	if(!p) throw Link_exceptions{"Link* Link::erase_header() - erasing nullptr"};
	if (p->succ || p->prev) throw Link_exceptions{"void Link::erase_header() - header is not single colomn"};
	p = last_floor(p);
	
	while (p->down)
	{
		
		p = p->down;
		if (p->up) p->up->erasing();
		p->up = nullptr;
		
	}
	
	
	return p->erase();;
	
	
}


/*
Алгоритм полного удаления списка
Если текущего нет, то возвращаем ноль

Это единственная функция, котоорая самостоятельно осущствляет навигацию по списку, 
когда переходит сначала на нижний ноль, а потом на последний в этом списке

Пока "р" не равен заголовку вызываем функцию erase_tower();

Как только "p" сравнялся с заголовком, то возвращаем функцию erase_header();

*/
Link* Link::deleting()
{
	Link* p = this;
	if (!p) return nullptr;
	p=p->sub_zero();
	p=last(p);
	
	while (p != p->head)
	{
		p=p->erase_tower();
	}
	return p->erase_header();
		
}























































































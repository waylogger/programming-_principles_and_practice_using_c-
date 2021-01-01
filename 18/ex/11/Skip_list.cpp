#include <D:\\Programms\\18\\11\\Skip_list.h>
#include <D:\\Programms\\18\\11\\Skip_list_help.cpp>


/*
Алгоритм поиска места для вставки в списке с пропусками

Проверяем на нули и герерируем исключения

Возвращаем значение функции insert_level(), передаем ей как аргументы узел скип-листа, и вставляемый узел

*/

Link* Skip_list::find_place(Link* p)
{
	if (!this->list) throw SL_exc{"fnc() is - find_place, this is null"};
	if (!p) throw SL_exc{"fnc() is - find_place, second arguments is null"};
	
	return insert_level(this->list,p);
}

/*
Простой поиск
Работает так же как и поиск места, только возвращает указатель на узел, если он равен искомому
в иных случаях возвращает ноль
*/
Link* Skip_list::find(Link* p)
{
	if (!this->list) throw SL_exc{"fnc() is - find_place, this is null"};
	if (!p) throw SL_exc{"fnc() is - find_place, second arguments is null"};
	this->list = this->list->zero();
	Link* a = insert_level(this->list,p);
	
	if (a->what_key() == p->what_key()) return a;
	else 
	{
		//cout << a->next()->what_key() << '\n';
		return nullptr;
	}
}
	


/*
Алгоритм упорядоченной вставки в скип-лист

Если текущий нулевой, то возвращаем аргумент и наоборот
Переводим текущий узел в нулевое состояние

Инициализируем узел "е" местом для вставки

сравниваем ключи места для вставки и аргумента

Если аргумент больше или равен, то вызываем функция add
Если меньше, то insert

NB функция ничего не возвращает, так как всегда стартует с места zero()
*/
void Skip_list::insert(Link* p)
{
		if (!this->list) 
		{
			
			this->list = p;
			return;
		}
		if (!p) return;
		
		this->list = this->list->zero();
			
		Link* e = find_place(p);
		
		if (e->what_key() <= p->what_key())
		{
			e = e->add(p);
			int k = flip();
			for (;k != 0; --k) 
			{
				e = e->add_level(AI::add);
			}	
			return;
		}
		else 
		{
			
			e = e->insert(p);
			if (e = e->get_head()) return;
			int k = flip();
			for (; k != 0; --k) 
			{
				e =e->add_level(AI::insert);
			}
			return;
		}
		throw SL_exc{"fnc() is - insert, smth wrong"};

}




/*
Алгоритм удаления
Если текущий список - ноль, то вызвааем delete

Идем вниз до упора, если это заголовок, то вызываем функцию удаления заголовка
Если нет, то фунцию удаления столбца
*/


void Skip_list::erase()
{
	Link* e = this->list;
	if (e == nullptr) 
	{
		return;
	}
	
	if (e == e->get_head())
	{
		e = e->erase_header();
		this->list = e;
		return;
	}
	else 
	{
		e = e->erase_tower();
		this->list = e;
		return;
	}
}































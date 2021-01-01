#include <iostream>
#include <memory>


template <typename T, typename PA = std::allocator<T*>>
class pvector_base {
	// как я себе представляю работу этого класса :
	//в других частяъ программы мы создаем указатели на объеты и помещаем
	//их в объект классa pvector, что позволит нам не беспокоиться об удалении указателей
	//и освобождении памяти - это всё сделает класс pvector
public:
int sz = 0;
int space = 0;
T** elem = nullptr;

public:
pvector_base(int i = 0);
virtual ~pvector_base();

pvector_base(const pvector_base&) = delete;
pvector_base& operator = (const pvector_base&) = delete;

pvector_base(pvector_base&&);
pvector_base& operator = (pvector_base&&);

int size() const {return sz;}
void set_size(const int a) {sz = a;}

int capacity() const {return space;} 
void set_space(const int a) {space = a;}


};

template <typename T, typename PA>
pvector_base<T,PA>::pvector_base(int n =0) : sz {0}, space{n} {
	// работа конструктора состоит в инициализации учетных едениц
	// и выделении памяти под массиив указателей

	PA palloc;
	elem = palloc.allocate(n);
	
}

template <typename T, typename PA>
pvector_base<T,PA>::~pvector_base() {
//работа деструктора состоит в уничтожении не только массива указателей elem
//но и в уничтожении каждого указателя массива и особождении его памяти
if (!elem) return;
std::allocator<T> alloc;
PA palloc;


for (int i =0; i < sz; ++i){
	if (elem[i]) { 
	
		alloc.destroy(elem[i]);
		
	}
	
}

for (int i =0; i < sz; ++i){
	if (elem[i]) 
	alloc.deallocate(elem[i],1);
	elem[i] = nullptr;
	}	

//после уничтожения и очистки указателей можно удалять массив указателей
palloc.deallocate(elem,space);
elem = nullptr;
}	

template <typename T, typename PA>
pvector_base<T,PA>::pvector_base(pvector_base&& b) {
// перемещение массива указателей в отличие от копирования разрешено
// поскольку оно не порождает риск повторного удаления указателей
//std::cout << "MOVE\n";
this->sz = b.sz;
this->space = b.space;
this->elem = b.elem;
b.elem = nullptr;
}	


template <typename T, typename PA>
pvector_base<T,PA>& pvector_base<T,PA>::operator=(pvector_base&&b) {
this->~pvector_base(); //разница с конструктором только в этом

this->sz = b.sz;
this->space = b.space;
this->elem = b.elem;
b.elem = nullptr;

return *this; // и в этом
}


template <typename T, typename A = std::allocator<T*>>
class ownership_base : public pvector_base<T,A> {
/*
Этот класс - саботажкик
он запрещает удалять указатели, обнуляя их
*/
public:
using pvector_base::pvector_base;

ownership_base(ownership_base&& b) {
	sz = b.sz;
	space = b.space;
	elem = b.elem;
	b.elem = nullptr;
}

ownership_base& operator = (ownership_base&& b) {
	sz = b.sz;
	space = b.space;
	elem = b.elem;
	b.elem = nullptr;
	
	return *this;
	
}

~ownership_base() {

if (!elem) return;
for (int i =0; i < sz; ++i) {
	elem[i] = nullptr; //чтобы блокировать работу деструктора родительского класса
	}
}

};



template<typename T, typename A = std::allocator<pvector_base<T>>> 
class pvector{
	// этот класс должен иметь вид стандартного контейнера, который хранит указатели
	// особенность заключается в том, что это хранение подразумевает удаление содержимого 
	// указателей
	// во всем остальном он должен быть подобен std::vector
		
	protected:
	pvector_base<T>* base= nullptr; // содержит указатель на представление pvector_base
	//держим это предаставление на расстоянии вытянутой руки
	public:
	using iterator = T**;
	using const_iterator = const T**;
	using type_name = T;
	
	pvector(int i =0);
	virtual ~pvector();	

	pvector(const pvector&) = delete;
	pvector& operator= (const pvector&) = delete;
	
	pvector(pvector&&b) {this->base = b.base; b.base = nullptr;};
	pvector& operator=(pvector&&b) {
		this->~pvector();
		this->base = b.base;
		b.base = nullptr;
		return *this;
	}
	int size() const {return base->size();}
	void set_size(const int a) {base->set_size(a);}
	
	int capacity() const {return base->capacity();}
	int set_space(const int a) {base->set_space(a);}
	
	virtual void reserve(const int);
	virtual void push_back(T* const);
	void resize(const int);
	
	iterator begin() {return &base->elem[0];}
	iterator end() {return &base->elem[size()];}
	
	 T* operator[](const int n) {return base->elem[n];}
	 T* operator*() {return base->elem[0];}
	 
	 virtual  iterator insert(iterator p, T* const);
	 iterator erase(iterator p);
	 iterator erase(iterator b, iterator e);
	
	
	
};

template<typename T, typename A>
pvector<T,A>::pvector(int i=0) { 
	// выделяем память под представление
	// и вызываем его конструктор
	A alloc;
	base = alloc.allocate(1);
	alloc.construct(base,pvector_base<T>{i});
	}
	
template<typename T, typename A>
pvector<T,A>::~pvector() {
		if (!base) return;
		//деструктор должен уничтожить представление и освободить память
		A alloc;
		alloc.destroy(base);
		alloc.deallocate(base,1);
		base = nullptr;
	}
	
template<typename T, typename A> 
void pvector<T,A>::reserve(const int newalloc) {
/*
смысл данной функции в выделении новой памяти для вектора указателей,
если вся выделенная ранее память была исчерпана
Для чего нужно выполнить следующие действия:
1. Создать новый объект класса pvector_base
2. Скопировать в него хранимые адреса
3. переместить в новый вектор на место имеющегося
*/
if (newalloc <= capacity()) return;

pvector_base<T> b {newalloc};

for (int i =0; i < this->size(); ++i) {
//копируем элементы тут
b.elem[i] = this->base->elem[i];
}
b.set_size(size());
std::swap(b,*base);

for (int i =0; i < b.size(); ++i)
	//нужно защитить имевшиеся указатели от удаления в деструкторе b
	b.elem[i] = nullptr;


}

template <typename T,typename A>
void pvector<T,A>::push_back(T* const t) {
if (capacity() == size())
	reserve(size()==0?8:size()*2);

base->elem[size()] = t;
base->set_size(size()+1);

}

template <typename T,typename A>
void pvector<T,A>::resize(const int newsize) {
/*
Функция необходима для увеличения размерности вектора указателей

*/
if (newsize <= size()) return;

if (newsize >= capacity())
	reserve(newsize*2);

for (int i = size(); i < newsize; ++i)
	base->elem[i] = nullptr;  //заполняем пустые адреса нулевыми указателями

base->set_size(newsize);

}


template <typename T, typename A>
typename pvector<T,A>::iterator pvector<T,A>::insert
(typename pvector<T,A>::iterator p, T* const t) {
	/*
	Идея вставки нового элемента в вектор заключается в следующем:
	1. Сохранение индекса вставляемого элемента, определяемый как количество элементов
	стоящих в векторе от начала и до него.
	2. При нехватке выделить новую память;
	3. Выполнить копирование элементов с последнего элемента вправо на один щаг
	4. Присвоить осбоводившемуся элементу передаваемый аргумент
	*/
	int index = p-begin(); //индекс вставляемого элемента
	
	if(size() == capacity())
			reserve(size()==0?8:2*size());
	
	iterator b = begin()+index;
	
	
	std::allocator<T>{}.construct(base->elem+size(),base->elem[size()-1]);
	set_size(size()+1);
	for (auto g = end()-1; g != b; --g) {
	*g = *(g-1);
	}
	
	*(begin()+index) = t;
		
	
	return p;
}
template <typename T, typename A>
typename pvector<T,A>::iterator pvector<T,A>::erase
(typename pvector<T,A>::iterator p) {
	/*
	процедура удаления состоит в перемещении всех стоях впереди элементов вектора 
	на одну позицию назад
	*/
	
if (p == end() || size() ==0) return p;

for (auto q = p+1; q != end(); ++q) {
*(q-1) = *q;

}

std::allocator<int>{}.destroy(&*(end()));
set_size(size()-1);

return p;
}

template <typename T, typename A>
typename pvector<T,A>::iterator pvector<T,A>::erase
(typename pvector<T,A>::iterator b, typename pvector<T,A>::iterator e) {
	/*
	удаление диапазона описывает два сценария: 
	1. мы удаляем вектор до конца
	2. мы удаляем кусок вектора в середине
	
	в первом случае мы вызываем деструкторы всех указателей до конца
	и по ходу движения уменьшаем размерность вектора
	
	во втором случае мы переносим всё то, что стоит за концом диапазона в начало диапазона
	до конца вектора и вызываем деструкторы дублирующих элементов
	
	для корректного освобождения заменяемых адресов мы их включаем в pvector
	*/
	if (b == e) return e;
	
	if (e == end()) {
		for (auto s = b; s != e; ++s) {
			std::allocator<T>{}.destroy(*s);
			set_size(size()-1);
		}
		return e;
	}
	
int copies = end() - e; //сколько элементов стоит после удаляемого диапазона
int step = e - b; //подсчет элементов в диапазоне для уменьшения размерности 


//заносим указатели, которые требуется удалить в вектор указателей
pvector<T>to_del;
for (auto d = b; d != e; ++d)
	to_del.push_back(*d); 



iterator pos = b;
for (int i = 0; i <= copies; ++i) {
	//переносим элементы стоящие за удаляемым диапазоном
*pos = *(e+i);
++pos;
}

set_size(size()-step);

for (int i = 0; i < step; ++i) {
	// уничтожаем лишние копии
	std::allocator<T>{}.destroy(base->elem[size()+i]);
}
	
return e;
}


template <typename T, typename A = std::allocator<pvector_base<T>>>
class ovector : public pvector<T,A> {
public:
using pvector<T,A>::pvector;
T& operator[](const int i) {return *base->elem[i];}
};



template <typename T, typename A = std::allocator<pvector_base<T>>> 
class ownership_vector : public pvector<T,A> {
/*
Данный класс полностью повторяет класс pvector за исключением следующих особенностей.
он содержит ещё производный от pvector_base класс ownership_base

этот класс не удаляет хранимые указатели

деструктор данного класса вводит следующий порядок удаления - указатели хранимые в ownervector_base
в результате поиска в base обнуляются, тем самым предохраняются от удаления

следом удаляется ownervector_base

1. заполняем ownervector_base указателями, которые нельзя удалять
2. при удалении объекта класса обнуляем их в массиве данных - base
3. вызываем деструктор ownervector_base, который не удаляет хранимые указатели

*/

ownership_base<T>* save_base = nullptr;
public:

ownership_vector(int i =0);
~ownership_vector();

bool permiss_to_delete(T* const t);

void reserve(const int) override;
void push_back(T* const, bool permiss = true);


};

template <typename T, typename A>
ownership_vector<T,A>::ownership_vector(int i =0) : pvector<T,A>{i} {
	std::allocator<ownership_base<T>> alloc;
	save_base = alloc.allocate(1);
	alloc.construct(save_base,ownership_base<T>{i});
}

template <typename T, typename A>
ownership_vector<T,A>::~ownership_vector()  {
	
	if (!base) return;
	if (!save_base) return;
	
	
	for (int i = 0; i < base->sz; ++i) 
		if (base->elem[i])
			if (!permiss_to_delete(base->elem[i])) {
				base->elem[i] = nullptr;
			}
	
	std::allocator<ownership_base<T>> alloc;
	
	alloc.destroy(save_base);
			
	alloc.deallocate(save_base,1);
	
	save_base = nullptr;
				
}
 

template <typename T, typename A>
bool ownership_vector<T,A>::permiss_to_delete(T* const t)  {
	
	if (!save_base) return true;
	for (int i = 0; i < save_base->sz; ++i)
			if (t == save_base->elem[i]) {
				
				return false;
		}
			
		
	
	return true;
}



template <typename T, typename A>
void ownership_vector<T,A>::reserve(const int newalloc) {


if (newalloc <= save_base->space) return;

ownership_base<T> b {newalloc};

for (int i =0; i < save_base->size(); ++i) {
//копируем элементы тут
b.elem[i] = this->save_base->elem[i];
}
b.set_size(save_base->size());
std::swap(b,*save_base);

for (int i =0; i < b.size(); ++i)
	//нужно защитить имевшиеся указатели от удаления в деструкторе b
	b.elem[i] = nullptr;


pvector::reserve(newalloc);
}


template <typename T, typename A>
void ownership_vector<T,A>::push_back(T* const t, bool permiss = true) {

if (!permiss) {
	if (save_base->sz == save_base->space)
		reserve(save_base->sz ==0 ? 8 : 2*save_base->sz);
	
	save_base->elem[save_base->sz] = t;
	++save_base->sz;

}
pvector::push_back(t);
}
int main() {

int** qwe = new int*[250];
ownership_vector<int>q;

for (int i =0; i < 250; ++i) {
qwe[i] = new int(i);
q.push_back(qwe[i],false);
}

for (int i =0; i < 15; ++i)
q.push_back(new int(i*10));

std::allocator<ownership_vector<int>>{}.destroy(&q);
for (int i =0; i < 250; ++i) {
	
std::cout << *qwe[i] << '\n';
}

//std::cout << *qwe << '\n';
//for (auto w : q) std::cout << *w << '\n';

	
	
	char c;
	std::cin >> c;
	
	
}
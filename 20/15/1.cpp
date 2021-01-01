#include <iostream>
#include <memory>

template <typename T, typename PA = std::allocator<T*>>
class pvector_base {
	private:
	int sz = 0;
	int space = 0;
	T** elem = nullptr; //для того, чтобы вектор мог корректно хранить содержимое указателей первого уровня
						//мы должны иметь указатель на последовательность указателей
	PA palloc;
	public:
	pvector_base(const int n = 0);
	~pvector_base();
	
	pvector_base(const pvector_base&) = delete; //копирование вектора указателей недопустимо
	pvector_base& operator=(const pvector_base&) = delete; //ради избежания повторного удаления указателей
	pvector_base(pvector_base&&);
	pvector_base& operator=(pvector_base&&);
	
	int size() const {return sz;}
	void set_size(int a) {sz = a;}
	
	int capacity() const {return space;}
	void set_capacity(int a) {space = a;}
	
};


template <typename T, typename PA = std::allocator<T*>>
pvector_base<T,PA>::pvector_base(int n = 0)  : sz {0}, space{n} 
												//инициализируем последовательность
{												//значение по умолчанию в размер вектора не включаются
	
	/*
	класс pvector_base должен выделять память под определенное число указателей, которое передается как "n"
	*/
	PA palloc;
	elem = palloc.allocate(n);

}

template <typename T, typename PA = std::allocator<T*>>
pvector_base<T,PA>::~pvector_base() {	

/*											
	деструктор не только освобождает  ресурсы занятые под массив указателей
	но и вызывает деструктор по каждому адресу, освобождает его и только после этого уничтожает elem
*/
	std::allocator<T> alloc;
	PA palloc;
	
	if (!elem) return;
	
	for (int i =0; i < sz; ++i) {
		alloc.destroy(elem[i]);
	}
	//если использовать один цикл, то после деаллокации мы переместимся в далекую область памяти
	//и потеряем преимущества индексации
	for (int i =0; i < sz; ++i) {
		alloc.deallocate(elem[i],1);
	}
		
	palloc.deallocate(elem,space);
	

}

template <typename T, typename PA = std::allocator<T*>>
pvector_base<T,PA>::pvector_base(pvector_base&&b) {
	/*
	перемещение по сравнению с копированием более безобидно, так как оно помогает обеспечить только 
	однократное удаление одного адреса, который только перемесчается
	*/	
	//std::cout << "MOVE!\n";
	this->sz = b.sz;
	this->space = b.space;
	this->elem = b.elem;
	
	
	b.elem = nullptr; //отключаем возможность удаления адресов
	
	
}

template <typename T, typename PA = std::allocator<T*>>
pvector_base<T,PA>& pvector_base<T,PA>::operator=(pvector_base&& b) {
/*
оператор применяется к уже созданному объекту, а потому он должен его сначала удалить.
*/
//std::cout << "MOVE!!!\n";
this->~pvector_base();
this->sz = b.sz;
this->space = b.space;
this->elem = b.elem;
b.elem = nullptr;

return *this;

}

template <typename T, typename PA = std::allocator<T*>>
pvector_base<T,PA> ret(int q){ 
pvector_base<T> a {q};
return a;
}



int main ()
{


		
		
		
	char c;
	std::cin >> c;
}
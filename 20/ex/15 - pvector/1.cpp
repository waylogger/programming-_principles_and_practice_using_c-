#include <iostream>
#include <memory>


template <typename T, typename PA = std::allocator<T*>>
class pvector_base {
	// ��� � ���� ����������� ������ ����� ������ :
	//� ������ ������ ��������� �� ������� ��������� �� ������ � ��������
	//�� � ������ �����a pvector, ��� �������� ��� �� ������������ �� �������� ����������
	//� ������������ ������ - ��� �� ������� ����� pvector
public:
int sz = 0;
int space = 0;
T** elem = nullptr;

public:
pvector_base(int i = 0);
~pvector_base();

pvector_base(const pvector_base&) = delete;
pvector_base& operator = (const pvector_base&) = delete;

pvector_base(pvector_base&&);
pvector_base& operator = (pvector_base&&);

int size() const {return sz;}
void set_size(const int a) {sz = a;}

int capacity() const {return space;} 
void set_space(const int a) {space = a;}

T* operator[] (const int n) {return base->elem[i];}
T* operator[] (const int n) const {return base->elem[i];}

};

template <typename T, typename PA>
pvector_base<T,PA>::pvector_base(int n =0) : sz {0}, space{n} {
	// ������ ������������ ������� � ������������� ������� ������
	// � ��������� ������ ��� ������� ����������

	PA palloc;
	elem = palloc.allocate(n);
	
}

template <typename T, typename PA>
pvector_base<T,PA>::~pvector_base() {
//������ ����������� ������� � ����������� �� ������ ������� ���������� elem
//�� � � ����������� ������� ��������� ������� � ����������� ��� ������

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
	}	

//����� ����������� � ������� ���������� ����� ������� ������ ����������
palloc.deallocate(elem,space);
	


}	

template <typename T, typename PA>
pvector_base<T,PA>::pvector_base(pvector_base&& b) {
// ����������� ������� ���������� � ������� �� ����������� ���������
// ��������� ��� �� ��������� ���� ���������� �������� ����������
//std::cout << "MOVE\n";
this->sz = b.sz;
this->space = b.space;
this->elem = b.elem;
b.elem = nullptr;

}	


template <typename T, typename PA>
pvector_base<T,PA>& pvector_base<T,PA>::operator=(pvector_base&&b) {
this->~pvector_base(); //������� � ������������� ������ � ����

this->sz = b.sz;
this->space = b.space;
this->elem = b.elem;
b.elem = nullptr;

return *this; // � � ����

}

template<typename T, typename A = std::allocator<pvector_base<T>>> 
class pvector{
	// ���� ����� ������ ����� ��� ������������ ����������, ������� ������ ���������
	// ����������� ����������� � ���, ��� ��� �������� ������������� �������� ����������� 
	// ����������
	// �� ���� ��������� �� ������ ���� ������� std::vector
		
	private:
	pvector_base<T>* base= nullptr; // �������� ��������� �� ������������� pvector_base
	//������ ��� �������������� �� ���������� ��������� ����
	public:
	using iterator = T**;
	using const_iterator = const T**;
	using type_name = T;
	
	pvector(int i =0);
	~pvector();	

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
	
	void reserve(const int);
	void push_back(T* const);
	void resize(const int);
	
	iterator begin() {return &base->elem[0];}
	iterator end() {return &base->elem[size()];}
	
	T* operator[](const int n) {return base->elem[n];}
	
	T* operator*() {return base->elem[0];}
	
	
	
};

template<typename T, typename A>
pvector<T,A>::pvector(int i=0) { 
	// �������� ������ ��� �������������
	// � �������� ��� �����������
	A alloc;
	base = alloc.allocate(1);
	alloc.construct(base,pvector_base<T>{i});
	}
	
template<typename T, typename A>
pvector<T,A>::~pvector() {
		if (!base) return;
		//���������� ������ ���������� ������������� � ���������� ������
		A alloc;
		alloc.destroy(base);
		alloc.deallocate(base,1);
	}
	
template<typename T, typename A> 
void pvector<T,A>::reserve(const int newalloc) {
/*
����� ������ ������� � ��������� ����� ������ ��� ������� ����������,
���� ��� ���������� ����� ������ ���� ���������
��� ���� ����� ��������� ��������� ��������:
1. ������� ����� ������ ������ pvector_base
2. ����������� � ���� �������� ������
3. ����������� � ����� ������ �� ����� ����������
*/
if (newalloc <= capacity()) return;

pvector_base<T> b {newalloc};

for (int i =0; i < this->size(); ++i) {
//�������� �������� ���
b.elem[i] = this->base->elem[i];
}
b.set_size(size());
std::swap(b,*base);

for (int i =0; i < b.size(); ++i)
	//����� �������� ��������� ��������� �� �������� � ����������� b
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
������� ���������� ��� ���������� ����������� ������� ����������

*/
if (newsize <= size()) return;

if (newsize >= capacity())
	reserve(newsize*2);

for (int i = size(); i < newsize; ++i)
	base->elem[i] = nullptr;  //��������� ������ ������ �������� �����������

base->set_size(newsize);

}





int main() {

	pvector<int>s;
	s.push_back(new int(12));
	
	std::cout << *s << '\n';

	char c;
	std::cin >> c;
	
	
}
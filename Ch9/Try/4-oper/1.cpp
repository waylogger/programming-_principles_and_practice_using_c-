#include <std_lib_facilities.h>

class S 
{
public:
S() {}	
S& operator = (S& ss)
{return *this;}
};



int main () {}


/*
class Integer
{
private:
    int value;
public:
    Integer(int i): value(i) 
    {}

    Integer& operator=(const Integer& right) {
        //проверка на самоприсваивание
        if (this == &right) {
            return *this;
        }
        value = right.value;
        return *this;
    }
};
*/
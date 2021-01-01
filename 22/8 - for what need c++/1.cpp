
#include <iostream>
#include <Eigen\\Eigen>


using Eigen::MatrixXd;
using std::cout;
using std::cin;

constexpr float exp(float x, int n)  
{  
    return n == 0 ? 1 :  
        n % 2 == 0 ? exp(x * x, n / 2) :  
        exp(x * x, (n - 1) / 2) * x;  
};  
/*
constexpr int p(int x, int y){
	int val = 2;
	//for (int i = y;i > 0; --i)
		//val = val*val;
	
	return val;
}
*/
int main()
{
MatrixXd mx(2,2);

constexpr double d = 0;
cout << d << '\n';

char c;
cin >>c;	
}




#include <iostream>
using namespace std;

class A
{
public:
	int x, y;
	A()
	{
		cout << "调用类A：默认构造函数" << endl;
	}
	A(int a, int b)  // 基类初始化
	{
		cout << "调用类A：带参构造函数" << endl;
		x = a;
		y = b;
	}

	void print()
	{
		cout << "x=" << x << ",y=" << y << endl << endl;
	}
	
};

// 这个代码错误，大家可以思考一下，解决不了再找我搞定。
class B :public A
{
public:
	B(int a, int b, int c) :A(a, b) // 可以在派生类调用A的构造函数
	{
		cout << "调用类B：带参构造函数" << endl;
		m = c;
	}
	void print()
	{
		cout << "x=" << x << ",y=" << y <<",m="<<m<< endl << endl;
	}

private:
	int m;
	A obj; // 在派生类中也不可以定义A的对象，实际上还是类外调用
};

int main()
{
	B obj(1, 2, 3); // 可以定义派生类对象
	obj.print(); 


	return 0;
}
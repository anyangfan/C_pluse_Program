#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "调用基类A：默认构造函数.\n";
	}
	A(int a)
	{
		cout << "调用基类A：构造函数.\n";
		x = a;
	}
	~A()
	{
		cout << "调用基类A：析构函数.\n";
	}

private:
	int x;
};

class B
{
public:
	B(int a)
	{
		cout << "调用基类B：构造函数.\n";
		y = a;
	}
	~B()
	{
		cout << "调用基类B：析构函数.\n";
	}

private:
	int y;
};

class C :public A, public B
{
public:
	C(int a, int b) :A(a), B(100)
	{
		cout << "调用派生类C：构造函数.\n";
		z = a;
	}
	~C()
	{
		cout << "调用派生类C：析构函数.\n";
	}

private:
	int z;
	A obj1,obj2;
};


int main()
{
	C obj(10, 20);

	return 0;
}
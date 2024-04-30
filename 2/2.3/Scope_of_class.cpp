#include <iostream>
using namespace std;
//冲突原则，类作用域运算符
class A
{
public:
	int x;
	void print()
	{
		cout << "调用类A的print()函数.\n";
		cout << "x=" << x << endl;
	}
};

class B
{
public:
	int y;
	void print()
	{
		cout << "调用类B的print()函数.\n";
		cout << "y=" << y << endl;
	}
};

class C:public A,public B
{
public:
	int y;  // 类B的和类C均有y的数据成员	
};

int main()
{
	C c1;
	c1.x = 100;
	c1.y = 200;  // 未指明的情况下，给派生类中的y赋值
	c1.B::y = 300; // 给基类B的y赋值

	c1.A::print();
	c1.B::print();

	cout << "y=" << c1.y << endl;  // 输出派生类中的y的值
	cout << "y=" << c1.B::y << endl; // 输出基类B中的y的值

	return 0;
}


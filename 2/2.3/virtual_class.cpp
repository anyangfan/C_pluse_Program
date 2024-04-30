#include <iostream>
using namespace std;
//虚基类
class A {
public:
	int x;
	A(int a = 0)
	{
		cout << "调用类A：构造函数." << endl;
		x = a;
	}
};

class B : virtual public A {
public:
	int y;
	B(int a = 0, int b = 0) :A(a) {
		cout << "调用类B：构造函数." << endl;
		y = b;
	}
};
class C :virtual public A {
public:
	int z;
	C(int a = 0, int c = 0) :A(a) {
		cout << "调用类C：构造函数." << endl;
		z = c;
	}
};

class D :public B, public C
{
public:
	int dx;
	D(int a1, int b, int c, int d, int a2) :B(a1, b), C(a2, c)
	{
		cout << "调用类D：构造函数." << endl;
		dx = d;
	}
};

int main()
{
	D obj(100, 200, 300, 400, 500);

	//cout << "\nobj.x=" << obj.x << endl;
	//obj.x = 20000;

	cout << obj.x << endl;
	cout << obj.y << endl;
	cout << obj.z << endl;

	return 0;
}
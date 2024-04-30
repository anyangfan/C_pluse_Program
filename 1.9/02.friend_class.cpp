#include <iostream>
using namespace std;

class CTestFClassA
{
public:
	CTestFClassA(double a, double b) {
		x = a;
		y = b;
	}
	double getx() {
		return x;
	}
	double gety() {
		return y;
	}
	friend class CTestFClassB; // 定义类CTestFClassB为类CTestFClassA友元
private:
	double x, y;
};

class CTestFClassB
{
public:
	CTestFClassB(int n = 1)
	{
		k = n;
	}
	void disp(CTestFClassA &obj) {
		cout <<"结果为:"<< obj.x + obj.y + k;
	} // 求类CTestFClassA的某个数据成员到这边来操作。

private:
	int k;
};

int main()
{
	CTestFClassA obj1(1, 2), obj2(3, 4);
	
	CTestFClassB objb(5);
	objb.disp(obj1);
	cout << endl;
	objb.disp(obj2);
	cout << endl;

	return 0;
}

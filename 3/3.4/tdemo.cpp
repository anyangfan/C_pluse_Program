#include <iostream>
#include <string>
using namespace std;

// 创建一个类
class TestC
{
public:
	// 普通构造函数
	TestC(string s, int d) :_data(d), _str(s)
	{
		cout << "程序执行：普通构造函数的函数体" << endl;
	}

	// 委托构造函数
	TestC(int d) :TestC("测试TestC(int d)", d)
	{
		cout << "程序执行：委托构造函数TestC(int d) 的函数体" << endl;
	}

	void printdata()const
	{
		cout << "-------------------------------------" << endl;
		cout << "_str=" << _str << endl;
		cout << "_data=" << _data << endl;
		cout << "-------------------------------------" << endl << endl;
	}

private:
	int _data;
	string _str;
};


int main()
{
	TestC objc1("测试普通构造函数:TestC(string s, int d) ", 250);
	objc1.printdata();

	TestC objc2(890);
	objc2.printdata();

	// 委托构造函数字符串_str赋值操作，这个大家自己完成。

	return 0;
}



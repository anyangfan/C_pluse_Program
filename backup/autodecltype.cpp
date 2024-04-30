#include <iostream>
using namespace std;

int main()
{
	auto var1 = 250;
	decltype(199.88) var2;

	cout << "var1占据字节个数:" << sizeof(var1) << endl;
	cout << "var2占据字节个数:" << sizeof(var2) << endl;

	return 0;
}

/*
1.decltype: 这是C++11引入的一个特性，允许您查询某个表达式或变量的声明类型。它返回在使用上下文中该类型的推断结果。

2.199.88: 这是decltype要求获取其类型的表达式。它代表一个具有值199.88的十进制浮点数字面量。在C++中，此类字面量默认类型为 double。

3.var2: 这是使用由decltype推导出的类型声明的变量。由于 decltype(199.88) 解析为 double，因此 var2 现在是一个类型为 double 的变量。
*/
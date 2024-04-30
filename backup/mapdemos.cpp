#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	// 创建一个空mm容器
	map<string, string, greater<string>> mm;

	// 直接向mm容器指定位置构造新键值对
	mm.emplace("C语言程序设计", "http://www.baidu.com");
	mm.emplace("C++语言程序设计", "http://www.google.com");

	cout << "\n输出mm容器存储键值对的个数为:" << mm.size() << endl
		 << endl;

	if (!mm.empty())
	{
		for (auto iter = mm.begin(); iter != mm.end(); iter++)
		{
			cout << iter->first << "\t" << iter->second << endl;
		}
	}
	cout << endl;

	return 0;
}

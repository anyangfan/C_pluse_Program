
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	// 创建一个set容器，为空的
	set<string> mys;
	cout << "\n\n测试容器mys长度:" << mys.size() << endl;
	cout << endl;

	mys.insert("www.baidu.com");
	mys.insert("www.163.com");
	mys.insert("www.126.com");
	mys.insert("www.0vice.com");

	cout << "\n输出mys容器所有元素:" << endl;
	for (auto it = mys.begin(); it != mys.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;

	return 0;
}



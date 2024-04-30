#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
	std::forward_list<int> values{ 10,20,30 };
	values.emplace_front(40);
	cout << "输出结果为1：" << endl;
	for (auto it = values.begin(); it != values.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	values.emplace_after(values.before_begin(), 50);
	cout << "输出结果为2：" << endl;
	for (auto it = values.begin(); it != values.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	values.reverse();
	cout << "输出结果为3：" << endl;
	for (auto it = values.begin(); it != values.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


}





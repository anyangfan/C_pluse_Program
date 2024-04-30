#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparefunc(int x, int y)
{
	return x < y;
}

int main()
{
	vector<int> myvr{ 93,78,133,21,89 };
	vector<int> lvec{8,3,5,2,1};

	// 平时常用的方法如下
	sort(myvr.begin(), myvr.end(), comparefunc);
	cout << "常用输出结果为：" << endl;
	for (int it : myvr)
		cout << it << ' ';
	cout << endl;

	// 下面我们使用lambda表达式
	sort(lvec.begin(), lvec.end(), [](int a, int b)->bool {return a < b; });
	cout << "lambda表达式输出结果为：" << endl;
	for (int il : lvec)
		cout << il << ' ';
	cout << endl;

	return 0;
}


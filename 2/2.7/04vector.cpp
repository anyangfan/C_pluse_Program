#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 定义一个空的vector容器
	vector<char> vi;

	// 向容器添加S T L T E M P L A T E
	vi.push_back('S');
	vi.push_back('T');
	vi.push_back('L');
	vi.push_back('T');
	vi.push_back('E');
	vi.push_back('M');
	vi.push_back('P');
	vi.push_back('L');
	vi.push_back('A');
	vi.push_back('T');
	vi.push_back('E');

	// 输出容器vi元素的个数 size()
	cout << "元素个数为:" << vi.size() << endl;

	// 遍历容器
	cout << "\n输出vi容器数据元素:\n";
	for (auto i = vi.begin(); i < vi.end(); i++)
		cout << " " << *i << " ";
	cout << endl;

	//------------------------------------------------------------------------
	// 插入数据元素到头部
	vi.insert(vi.begin(), 'V');

	// 遍历容器
	cout << "\n输出vi容器数据元素:\n";
	for (auto i = vi.begin(); i < vi.end(); i++)
		cout << " " << *i << " ";
	cout << endl;


	//------------------------------------------------------------------------
	// 插入数据元素到尾部
	vi.insert(vi.end(), 'I');

	// 遍历容器
	cout << "\n输出vi容器数据元素:\n";
	for (auto i = vi.begin(); i < vi.end(); i++)
		cout << " " << *i << " ";
	cout << endl;

	cout << "\n输出vi容器首个元素为:" << vi.at(0) << endl << endl;


	return 0;
}


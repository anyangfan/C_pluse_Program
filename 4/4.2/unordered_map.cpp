#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef unordered_map<string, string> strmap;

strmap merge(strmap str1, strmap str2)
{
	strmap temp(str1);
	temp.insert(str2.begin(), str2.end());
	return temp;
}

int main()
{
	strmap s1;
	strmap s2({{"apple", "red"}, {"lemon", "yellow"}});		  // 使用数组初始化
	strmap s3({{"orange", "orange"}, {"strawberry", "red"}}); // 使用数组初始化

	/* -------------------------------------------------------------------------- */
	/*                                    复制初始化                                   */
	/* -------------------------------------------------------------------------- */
	strmap s4(s2);
	/* ------------------------------- 向s4容器中添加元素 ------------------------------- */
	s4.insert({{"banana", "yellow"}, {"grape", "green"}});
	s4.insert({{"pear", "green"}});
	cout << "\n输出s4容器:\n";
	for (auto &x : s4)
		cout << " " << x.first << ":" << x.second << " |";
	cout << endl;

	/* --------------------------------- 移动初始化操作 -------------------------------- */
	strmap s5(merge(s3, s4));
	cout << "\n输出s5容器:\n";
	for (auto &x : s5)
		cout << " " << x.first << ":" << x.second << " |";
	cout << "\n"
		 << endl;
	/* --------------------------------- 范围初始化操作 -------------------------------- */
	strmap s6(s5.begin(), s5.end());
	cout << "\n输出s6容器:\n";
	for (auto &x : s6)
		cout << " " << x.first << ":" << x.second << " |";
	cout << "\n"
		 << endl;

	return 0;
}

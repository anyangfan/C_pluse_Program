#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	for (const auto var : { 54,67,90,12,53,88,77,123,54,20 })
		cout << var << " ";
	cout << endl;

	for (const auto str : { "ABC","DEF","GHI","JKL" })
		cout << str << " ";
	cout << endl<<endl;

	list<int> lst{ 54,67,90,12,53,88,77,123,54,20 };
	list<string> lst2{ "ABC","DEF","GHI","JKL" };

	for (const auto var : lst)
		cout << var << " ";
	cout << endl;

	for (const auto str : lst2)
		cout << str << " ";
	cout << endl;

	return 0;
}
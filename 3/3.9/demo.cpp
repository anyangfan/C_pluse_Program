#include <iostream>
using namespace std;

int main()
{
	int x = 400;
	int y = 2000;
	cout << "x=" << x << endl;

	constexpr int p = 400;

	cout << "p=" << p << endl;
	
	cout << "x=" << x << endl;

	// p = &y; 错误

	return 0;
}
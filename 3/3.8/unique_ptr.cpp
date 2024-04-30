#include <iostream>
#include <memory>

using namespace std;

int main()
{
	std::unique_ptr<int> p1(new int(24));
	cout << "*p1=" <<* p1 << endl << endl;

	std::unique_ptr<int> p2 = std::move(p1);
	cout << "*p2=" << *p2 << endl << endl;

	p2.reset(); // 显式释放内存
	p1.reset(); 

	std::unique_ptr<int>p3(new int(250));
	p3.reset(new int(666)); // 绑定动态对象
	cout << "*p3=" << *p3 << endl << endl;

	p3 = nullptr; // 显式销毁指向对象，同时智能指针变为空，p3.reset()

	std::unique_ptr<int> p4(new int(999));
	int* p = p4.release(); // 只是释放控制权，不会释放内存
	cout << "*p=" << *p << endl << endl;

	//cout << "*p4=" <<*p4 << endl;

	delete p; // 释放区资源数据

	return 0;
}
//
//#include <iostream>
//#include <deque>
//using namespace std;
//
//int main()
//{
//    // 创建deque容器，没有任何数据元素
//    deque<int> d1;
//
//    // 创建deque容器且有50个元素
//    deque<int> d2(50);
//
//    // 创建一个具有9个元素的deque容器，并且进行初始化值
//    deque<int> d3(9, 888);
//
//    // 容器之间可以赋值
//    deque<int> d4(10);
//    deque<int> d5(d4); 
//
//    return 0;
//}



#include <iostream>
#include <deque>
using namespace std;

int main()
{
	// 定义空的容器
	deque<int> d1;   

	// 向容器的尾部插入数字
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	d1.push_back(50);
	d1.push_back(60);
	d1.push_back(70);
	d1.push_back(80);
	d1.push_back(90);
	d1.push_back(100);

	// 输出d1元素的个数
	cout << "输出d1容器元素的个数为:" << d1.size() << endl << endl;

	// 向d1容器头部添加数据元素值
	d1.push_back(888);

	// 输出容器所有元素值
	cout << "输出d1容器所有元素的值:" << endl;
	for (auto i = d1.begin(); i < d1.end(); i++)
		cout << " " << *i << " ";
	cout << endl << endl;

	// 删除容器头部的数据元素值
	d1.pop_front();
	// 输出容器所有元素值
	cout << "输出d1容器所有元素的值:" << endl;
	for (auto i = d1.begin(); i < d1.end(); i++)
		cout << " " << *i << " ";
	cout << endl << endl;

	return 0;
}


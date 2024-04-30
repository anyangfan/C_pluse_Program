
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

	// 1.set::begin/end set::cbegin/cend
	int myints[] = {75, 23, 65, 42, 13};
	std::set<int> myset(myints, myints + 5);

	std::cout << "myset contains(begin/end):";
	for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';

	std::cout << "myset contains(cbegin/cend):";
	for (auto it = myset.cbegin(); it != myset.cend(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n'
			  << endl;

	// 2.set::clear
	myset.clear();
	myset.insert(1101);
	myset.insert(2202);

	std::cout << "myset contains:";
	for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << endl
			  << endl;

	// 3.set::count
	//  set some initial values:
	for (int i = 1; i < 5; ++i)
		myset.insert(i * 3); // set: 3 6 9 12

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i;
		if (myset.count(i) != 0)
			std::cout << " is an element of myset.\n";
		else
			std::cout << " is not an element of myset.\n";
	}
	cout << '\n'
		 << endl;

	std::set<std::string> myset_string;

	myset_string.emplace("foo");
	myset_string.emplace("bar");
	auto ret = myset_string.emplace("foo");

	if (!ret.second)
		std::cout << "foo already exists in myset\n";

	cout << '\n'
		 << endl;

	// 4.set::erase set::find
	myset.clear();
	std::set<int>::iterator it;

	// insert some values:
	for (int i = 1; i < 10; i++)
		myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

	it = myset.begin();
	++it; // "it" points now to 20

	myset.erase(it);

	myset.erase(40);

	it = myset.find(60);
	myset.erase(it, myset.end());

	std::cout << "myset contains:";
	for (it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n'
			  << endl;

	// 5.set::get_allocator
	int *p;
	unsigned int i;

	std::cout << "Myset array contains:";
	for(auto i = myset.begin(); i != myset.end(); i++)
	{
		std::cout << *i << " ";
	}
	cout<<endl;

	// allocate an array of 5 elements using myset's allocator:
	p = myset.get_allocator().allocate(5);

	// assign some values to array
	for (i = 0; i < 5; i++)
		p[i] = (i + 1) * 100;

	std::cout << "The allocated array contains:";
	for (i = 0; i < 5; i++)
		std::cout << ' ' << p[i];
	std::cout << '\n';

	std::cout << "Myset array contains:";
	for(auto i = myset.begin(); i != myset.end(); i++)
	{
		std::cout << *i << " ";
	}

	myset.get_allocator().deallocate(p, 5);
	cout << "\n"<<endl;
	return 0;
}

/* ---------------------------------- 仿函数类 ---------------------------------- */
#include <iostream>
#include <set>

using namespace std;

class TestA
{
public:
	TestA(string lname, string fname):_fname(fname),_lname(lname)
	{
		cout << "执行TestA类的构造函数\n";
	}
	string firstname()const
	{
		return _fname;
	}
	string lastname()const
	{
		return _lname;
	}

private:
	string _fname = nullptr;
	string _lname = nullptr;
};

class TestB
{
public:
	bool operator() (const TestA& t1, const TestA& t2)const
	{
		return t1.lastname() < t2.lastname() || t1.lastname() == t2.lastname() &&
			t1.firstname() < t2.firstname();
	}
};

int main()
{
	
	set<TestA, TestB> sett;
	/* ---------------------------------- 仿函数类 ---------------------------------- */
	/*
	在 main() 函数中，类 TestB 并没有被直接调用，而是在定义 set<TestA, TestB> sett; 中作为模板参数传递给 set 容器。
	在这里，TestB 被用作容器 sett 的排序准则，而不是被直接调用。
	在这个示例中，TestB 类是一个仿函数类，用于定义 set<TestA, TestB> 中元素的排序方式。
	当元素被插入到 sett 集合中时，set 容器会使用 TestB 类中定义的比较规则来排序这些元素。
	*/
	TestA t1("liu", "san");
	TestA t2("xiao", "ming");
	TestA t3("zhang", "san");
	TestA t4("wang", "xiao");
	
	sett.insert(t1);
	sett.insert(t2);
	sett.insert(t3);
	sett.insert(t4);

	for (auto i : sett)
	{
		cout << i.lastname() << "," << i.firstname() << endl;
	}

	cout << endl;

	return 0;
}
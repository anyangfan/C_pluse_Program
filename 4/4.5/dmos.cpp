#include <iostream>
#include <stdexcept>
using namespace std;

class TestA
{
	virtual void Func() {

	}
};

class TestB :public TestA
{
public:
	void disp() {
		cout << "TestB OK." << endl;
	}
};

void erro_dispObject(TestA& t)
{
	try 
	{
		TestB& tb = dynamic_cast<TestB&>(t);
		// 在此转换若不安全，会抛出bad_cast异常
		tb.disp();		
	}
	catch (bad_cast& e)
	{
		cerr << e.what() << endl;
	}
}

void correct_dispObject(TestB& t)
{
	try 
	{
		TestB& tb = dynamic_cast<TestB&>(t);
		// 在此转换若不安全，会抛出bad_cast异常
		tb.disp();		
	}
	catch (bad_cast& e)
	{
		cerr << e.what() << endl;
	}
}

int main()
{
	TestA obja;
	erro_dispObject(obja);

	TestB objb;
	correct_dispObject(objb);

	return 0;
}

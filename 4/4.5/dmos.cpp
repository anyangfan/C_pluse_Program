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

void dispObject(TestA& t)
{
	try 
	{
		TestB& tb = dynamic_cast<TestB&>(t);
		// �ڴ�ת��������ȫ�����׳�bad_cast�쳣
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
	dispObject(obja);

	return 0;
}

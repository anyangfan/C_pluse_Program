#include <iostream>
using namespace std;

class CNewDelete
{
public:
	CNewDelete() {
		cout << "\n调用默认的构造函数CNewDelete::CNewDelete()." << endl;
		str = new char[10];
	}
	~CNewDelete() {
		cout << "\n调用析构函数CNewDelete::~CNewDelete()." << endl;
		delete[]str;
	}
private:
	char *str;
};

int main()
{
	char buffer[100]; 
	CNewDelete *pobj = new(buffer) CNewDelete();
	pobj->~CNewDelete();  // 主动调用析构函数，避免内存泄漏

	char *buffer2 = new char[100];
	CNewDelete *pobj2 = new(buffer2) CNewDelete();
	pobj2->~CNewDelete(); // 必须记住，主动调用析构函数

	delete[]buffer2; // 堆内存需要主动释放操作

	return 0;
}

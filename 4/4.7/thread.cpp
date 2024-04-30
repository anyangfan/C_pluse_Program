#include <iostream>
#include <thread>
using namespace std;

void ThreadFunc1()
{
	cout << "ThreadFunc1()--A\n" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));
	cout << "ThreadFunc1()--B" << endl;
}
void ThreadFunc2(int args,string sp)
{
	cout << "ThreadFunc2()--A" << endl;
	this_thread::sleep_for(std::chrono::seconds(7));
	cout << "ThreadFunc2()--B" << endl;
}
int main()
{
	thread ths1(ThreadFunc1);
	thread ths2(ThreadFunc2,10,"LS");

	ths1.join();
	cout << "join" << endl;
	ths2.detach();
	cout << "detach" << endl;

	return 0;
}



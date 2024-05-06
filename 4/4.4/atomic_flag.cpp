#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <unistd.h>
using namespace std;
// ATOMIC_FLAG_INIT-->定义能以语句用于初始化操作，清除状态的初始化器
std::atomic_flag lock = ATOMIC_FLAG_INIT; //

void FuncAt(int args)
{
	//获取当前线程的ID
	if(lock.test_and_set(std::memory_order_acquire)){
		cout << "Thread" << args << ":" << std::this_thread::get_id() << " is running" <<endl;
	}
	lock.clear(std::memory_order_release);
	for (int i = 0; i < 10; i++)
	{
		while (lock.test_and_set(std::memory_order_acquire))
			; // 获得锁
		std::cout << "Output Threads:" << i << std::endl;
		lock.clear(std::memory_order_release); // 释放锁
	}
}

int main()
#include <unistd.h> // Include the <unistd.h> header file for usleep()

{
	std::vector<std::thread> vct;
	for (int i = 0; i < 2; i++)
	{
		vct.emplace_back(FuncAt, i);
	}
	usleep(100000); // Replace sleep(0.1) with usleep(100000)
	for (auto &t : vct)
	{	
		cout << "Thread-" << t.get_id() << " is over" << endl;
		t.join();
	}

	return 0;
}

/*
设置编译器选项：cd "/userdata/Desktop/C_pluse_Program/4/4.4/" && g++ atomic_flag.cpp -o atomic_flag -lpthread && "/userdata/Deskto
p/C_pluse_Program/4/4.4/"atomic_flag
*/
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

std::mutex mx;
std::condition_variable scv;
bool ready = false; 

void PrintID(int id)
{
	std::unique_lock <std::mutex> lock(mx);

	while (!ready)
	{
		scv.wait(lock); // 当前线程被阻塞，当全局标志位变为true之后，才唤醒
	}
	std::cout << "Threads : " << id << std::endl;
}

void RunFunc()
{
	std::unique_lock <std::mutex> lock(mx);

	ready = true; // 设置全局标志位为true
	scv.notify_all(); // 唤醒所有线程
}

int main()
{
	std::thread thrs[5];

	for (int i = 0; i < 5; i++)
		thrs[i] = std::thread(PrintID, i);

	std::cout << "5 threads ready to race......\n";
	RunFunc();

	for (auto& t : thrs)
		t.join();

	return 0;
}

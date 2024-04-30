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
		scv.wait(lock); // ��ǰ�̱߳���������ȫ�ֱ�־λ��Ϊtrue֮�󣬲Ż���
	}
	std::cout << "Threads : " << id << std::endl;
}

void RunFunc()
{
	std::unique_lock <std::mutex> lock(mx);

	ready = true; // ����ȫ�ֱ�־λΪtrue
	scv.notify_all(); // ���������߳�
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

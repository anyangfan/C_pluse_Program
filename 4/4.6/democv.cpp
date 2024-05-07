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
		/*
		在C++中，`scv.wait(lock)`是一个用于处理条件变量的语句。这里的`scv`是一个条件变量对象，而`lock`是一个独占的互斥锁对象。

		`wait()`函数是一个阻塞函数，它会释放传入的锁，并使当前线程进入睡眠状态，直到其他线程调用同一条件变量的`notify_one()`或`notify_all()`函数唤醒它。
		当线程被唤醒后，`wait()`函数会再次尝试获取传入的锁，然后返回。

		这个函数通常用于线程同步，特别是当某些条件不满足时，你希望线程等待而不是忙等。
		例如，你可能有一个生产者线程和一个消费者线程，消费者线程在队列为空时需要等待，直到生产者线程向队列中添加了一个元素。
		在这种情况下，你可以使用条件变量和`wait()`函数来使消费者线程在队列为空时进入睡眠状态，然后在生产者线程向队列中添加元素后，
		使用`notify_one()`或`notify_all()`函数唤醒消费者线程。

		需要注意的是，`wait()`函数应该在一个循环中调用，并且循环的条件应该是你希望等待的条件。
		这是因为`wait()`函数可能会因为所谓的"虚假唤醒"而返回，即没有其他线程调用`notify_one()`或`notify_all()`函数，
		`wait()`函数也可能返回。因此，当`wait()`函数返回时，你应该检查你的条件是否已经满足，如果没有满足，你应该再次调用`wait()`函数。
		*/
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

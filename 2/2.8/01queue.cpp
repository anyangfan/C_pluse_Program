// constructing queues
#include <iostream> // std::cout
#include <deque>    // std::deque
#include <list>     // std::list
#include <queue>    // std::queue

int main()
{
    using namespace std;
    std::deque<int> mydeck(3, 100); // deque with 3 elements
    std::list<int> mylist(2, 200);  // list with 2 elements

    std::queue<int> first;          // empty queue
    std::queue<int> second(mydeck); // queue initialized to copy of deque

    std::queue<int, std::list<int>> third; // empty queue with list as underlying container
    std::queue<int, std::list<int>> fourth(mylist);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';

    // queue::back
    std::queue<int> myqueue;

    myqueue.push(12);
    myqueue.push(75); // this is now the back

    myqueue.back() -= myqueue.front();

    std::cout << "myqueue.back() is now " << myqueue.back() << '\n';

    // queue::emplace
    cout << "**********************" << endl;
    std::queue<std::string> string_myqueue;

    string_myqueue.emplace("First sentence");
    string_myqueue.emplace("Second sentence");

    std::cout << "myqueue contains:\n";
    while (!string_myqueue.empty())
    {
        std::cout << string_myqueue.front() << '\n';
        string_myqueue.pop();
    }
    
    // queue::empty
    cout << "**********************" << endl;

    // std::queue<int> myqueue;
    int sum(0);
    // 清空队列
    while (!myqueue.empty())
    {
        myqueue.pop();
    }
    for (int i = 1; i <= 10; i++)
        myqueue.push(i);

    while (!myqueue.empty())
    {
        cout << "Popping " << myqueue.front() << '\n';
        sum += myqueue.front();
        myqueue.pop();
    }

    std::cout << "total: " << sum << '\n';

    // queue::push/pop
    cout << "***********" << endl;
    //std::queue<int> myqueue;
    while(!myqueue.empty()){
        myqueue.pop();
    }
    int myint;

    std::cout << "Please enter some integers (enter 0 to end):\n";

    do
    {
        std::cin >> myint;
        myqueue.push(myint);
    } while (myint);

    std::cout << "myqueue contains: ";
    while (!myqueue.empty())
    {
        std::cout << ' ' << myqueue.front();
        myqueue.pop();
    }
    std::cout << '\n';
    return 0;
}
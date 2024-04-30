
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    // 创建deque容器，没有任何数据元素
    deque<int> d1;

    // 创建deque容器且有50个元素
    deque<int> d2(50);

    // 创建一个具有9个元素的deque容器，并且进行初始化值
    deque<int> d3(9, 888);
    cout << "d3: ";
    for (int i = 0; i < d3.size(); i++)
    {
        cout << d3[i] << " ";
    }
    cout << endl;
    for (auto i = d3.begin(); i != d3.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    // 容器之间可以赋值
    deque<int> d4(10, 1);
    deque<int> d5(d4);
    cout << "d5: ";
    for (int i = 0; i < d5.size(); i++)
    {
        cout << d5[i] << " ";
    }
    cout << endl;
    for (auto i = d5.begin(); i != d5.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
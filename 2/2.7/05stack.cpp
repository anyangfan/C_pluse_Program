
#include <iostream>
#include <stack>
#include <list>
using namespace std;

int main()
{
    // 创建一个stack容器适配器
    list<int> LS{ 11,22,33,44,55,66,77,88,99 };
    stack<int, list<int>> mystack(LS);

    // 查询mystack存储元素的个数
    cout << "\nmystack栈容器数据元素个数为:" << mystack.size() << endl;

    // 输出栈容器数据元素的值:
    cout << "\n\n输出栈容器数据元素的值:" << endl;
    while (!mystack.empty())  // 没有元素返回真true,否则返回false
    {
        cout << mystack.top() << " ";
        // 将栈顶元素弹出去
        mystack.pop();
    }
    cout << endl;

    return 0;
}

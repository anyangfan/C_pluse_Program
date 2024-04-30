#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;

    // 压入元素
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // 访问栈顶元素
    std::cout << "Top element: " << myStack.top() << std::endl;

    // 弹出栈顶元素
    myStack.pop();

    // 打印栈中所有元素
    std::cout << "Stack elements: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
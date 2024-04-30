#include <iostream>
#include <memory>

class MyClass {
public:
    ~MyClass() { std::cout << "Destructor called" << std::endl; }
};

int main() {
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();
    std::weak_ptr<MyClass> weakPtr = sharedPtr; // 创建一个weak_ptr观察sharedPtr

    if (auto observer = weakPtr.lock()) { // 尝试获取指向对象的shared_ptr
        std::cout << "Object is still alive" << std::endl;
    } else {
        std::cout << "Object has been destroyed" << std::endl;
    }

    sharedPtr.reset(); // 释放sharedPtr所有权

    if (auto observer = weakPtr.lock()) {
        std::cout << "Object is still alive" << std::endl;
    } else {
        std::cout << "Object has been destroyed" << std::endl;
    }

    return 0;
}
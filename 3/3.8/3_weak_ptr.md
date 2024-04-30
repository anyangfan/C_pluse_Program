# weak_ptr

## 作用

在 C++ 中，`std::weak_ptr` 是一种智能指针，用于解决 `std::shared_ptr` 可能引发的循环引用问题。它是 C++11 标准库的一部分。

`std::weak_ptr` 的主要作用是：

1. **避免循环引用**：当两个或多个对象之间相互持有 `std::shared_ptr` 指针，并且存在循环引用时，这些对象将永远不会被销毁，导致内存泄漏。通过使用 `std::weak_ptr`，可以打破循环引用，避免此类问题的发生。

2. **不增加引用计数**：与 `std::shared_ptr` 不同，`std::weak_ptr` 不会增加所指向对象的引用计数。即使 `std::weak_ptr` 指向某个对象，该对象的引用计数也不会增加。因此，即使对象被 `std::weak_ptr` 持有，只要没有其他 `std::shared_ptr` 持有，该对象就会被正确地销毁。

3. **获取shared_ptr的临时观察**：`std::weak_ptr` 通常用于观察一个由 `std::shared_ptr` 管理的对象，但是不会拥有其所有权。通过调用 `std::weak_ptr` 的 `lock()` 成员函数，可以尝试获取一个指向所观察对象的 `std::shared_ptr`，如果对象仍然存在的话。这样可以安全地使用对象，同时不会导致对象的生命周期延长。

4. **与shared_ptr协同工作**：`std::weak_ptr` 通常与 `std::shared_ptr` 一起使用，用于确保 `std::shared_ptr` 所管理的资源在不再需要时能够被正确释放，同时避免循环引用。

## 典型用法

下面是一个简单示例说明 `std::weak_ptr` 的用法：

```cpp
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
```

在这个示例中，`weakPtr` 观察了 `sharedPtr`，但是并不拥有它。通过 `lock()` 函数，我们可以尝试获取一个指向所观察对象的 `shared_ptr`。当 `sharedPtr` 被释放后，`weakPtr` 也不再持有任何有效的指针。

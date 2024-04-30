# 2.shared_ptr

## 2.1作用

在C++中，`shared_ptr` 是一个智能指针，用于管理动态分配的内存。它是C++11引入的标准库中的一部分，旨在解决原始指针的一些问题，如内存泄漏和悬挂指针。

以下是 `shared_ptr` 的主要作用：

1. **自动内存管理**：`shared_ptr` 能够自动管理动态分配的内存，当其不再被引用时会自动释放分配的内存，避免了内存泄漏的问题。当 `shared_ptr` 所有权的最后一个实例被销毁时，它所管理的内存会被释放。

2. **共享所有权**：与 `unique_ptr` 不同，`shared_ptr` 允许多个指针共享同一块内存。这意味着可以将同一份资源传递给多个部分使用，而不必担心在其中一个地方释放了资源后，其他地方访问到悬挂指针的问题。共享所有权也意味着不需要手动管理指针的生命周期，从而减少了程序中的错误。

3. **引用计数**：`shared_ptr` 内部维护了一个引用计数，用于跟踪有多少个 `shared_ptr` 实例共享同一块内存。每当一个新的 `shared_ptr` 实例指向相同的内存时，引用计数会增加；当 `shared_ptr` 实例销毁时，引用计数会减少。当引用计数为零时，表明没有任何 `shared_ptr` 指向该内存，此时内存会被释放。

4. **自定义删除器**：`shared_ptr` 允许指定一个自定义的删除器，用于在释放内存时执行特定的操作，比如关闭文件或释放其他资源。

总的来说，`shared_ptr` 提供了一种安全且方便的方式来管理动态分配的内存，避免了手动管理内存时可能出现的错误和内存泄漏问题。

## 2.2典型用例

当需要在 C++ 中动态管理资源且多个部分可能需要访问同一块内存时，`std::shared_ptr` 提供了一种方便且安全的方式来处理这种情况。以下是 `std::shared_ptr` 的一些典型用法：

1. **共享动态分配的对象**：`std::shared_ptr` 可以用于共享动态分配的对象，以便多个部分可以共享对同一对象的访问。

    ```cpp
    std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
    std::shared_ptr<int> ptr2 = ptr1; // ptr2 和 ptr1 共享同一个int对象
    ```

2. **作为容器元素**：`std::shared_ptr` 可以作为容器的元素，使得多个容器可以共享相同的资源。

    ```cpp
    std::vector<std::shared_ptr<int>> vec;
    vec.push_back(std::make_shared<int>(42));
    ```

3. **避免循环引用**：在处理对象间存在循环引用的情况下，使用 `std::shared_ptr` 可以解决内存泄漏问题。通过弱引用 `std::weak_ptr` 配合 `std::shared_ptr` 使用，可以防止循环引用导致的内存泄漏。

    ```cpp
    class B; // forward declaration

    class A {
        std::shared_ptr<B> b_ptr;
    public:
        void setB(std::shared_ptr<B> b) { b_ptr = b; }
    };

    class B {
        std::shared_ptr<A> a_ptr;
    public:
        void setA(std::shared_ptr<A> a) { a_ptr = a; }
    };

    int main() {
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<B> b = std::make_shared<B>();

        a->setB(b);
        b->setA(a);

        return 0;
    }
    ```

### 2.3代码解析

这段代码定义了两个类 `A` 和 `B`，它们之间相互引用，即 `A` 类中有一个指向 `B` 类对象的 `std::shared_ptr`，而 `B` 类中也有一个指向 `A` 类对象的 `std::shared_ptr`。这种情况常见于对象之间存在关联关系或者组合关系时。

1. **类定义**：
   - `class A`：定义了一个类 `A`，其中包含一个名为 `b_ptr` 的 `std::shared_ptr<B>` 类型的成员变量。
   - `class B`：定义了一个类 `B`，其中包含一个名为 `a_ptr` 的 `std::shared_ptr<A>` 类型的成员变量。

2. **成员函数**：
   - `A::setB(std::shared_ptr<B> b)`：设置 `A` 类对象的 `b_ptr` 成员变量为传入的 `std::shared_ptr<B>`。
   - `B::setA(std::shared_ptr<A> a)`：设置 `B` 类对象的 `a_ptr` 成员变量为传入的 `std::shared_ptr<A>`。

3. **`main()` 函数**：
   - 首先在堆上分别创建了一个 `A` 类对象和一个 `B` 类对象，分别用 `std::make_shared<A>()` 和 `std::make_shared<B>()`。
   - 然后将 `B` 类对象的 `shared_ptr` 设置为指向 `A` 类对象，并将 `A` 类对象的 `shared_ptr` 设置为指向 `B` 类对象，这样就形成了一个循环引用。
   - 最后，`main()` 函数结束，所有 `shared_ptr` 的引用计数减少并销毁，由于循环引用，两个对象的引用计数不会归零，导致内存泄漏。

这段代码展示了当两个类对象相互持有对方的 `shared_ptr` 时，可能会导致的循环引用问题。为了避免这种情况，可以使用 `std::weak_ptr` 来解决。

### 2.4代码优化

使用 `std::weak_ptr` 可以优化上述代码，避免循环引用导致的内存泄漏问题。下面是优化后的代码：

```cpp
    #include <memory>

    class B; // forward declaration

    class A {
        std::shared_ptr<B> b_ptr;
    public:
        void setB(std::shared_ptr<B> b) { b_ptr = b; }
    };

    class B {
        std::weak_ptr<A> a_ptr; // 使用 weak_ptr 代替 shared_ptr
    public:
        void setA(std::shared_ptr<A> a) { a_ptr = a; }
    };

    int main() {
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<B> b = std::make_shared<B>();

        a->setB(b);
        b->setA(a);

        return 0;
    }
    ```

    在这个优化版本中，`B` 类的 `a_ptr` 成员变量被改为 `std::weak_ptr<A>`，这意味着它不会增加 `A` 对象的引用计数。当 `std::shared_ptr<A>` 所有权的最后一个实例被销毁时，`a_ptr` 会自动被设置为 nullptr，从而避免了循环引用导致的内存泄漏。

    使用 `std::weak_ptr` 可以在对象之间存在关联关系时，防止循环引用导致的内存泄漏问题，同时保持了对象之间的联系。

1. **线程安全的资源共享**：`std::shared_ptr` 可以在多线程环境中安全地共享资源，因为其内部引用计数的操作是原子的。

```cpp
#include <iostream>
#include <thread>
#include <memory>

void func(std::shared_ptr<int> ptr) {
    std::cout << "Value: " << *ptr << std::endl;
}

int main() {
    std::shared_ptr<int> ptr = std::make_shared<int>(42);
    std::thread t(func, ptr);
    t.join();
    return 0;
}
```

总的来说，`std::shared_ptr` 提供了一种便捷而安全的方式来管理动态分配的内存，并支持多个指针共享同一份资源，避免了内存泄漏和悬挂指针等问题。

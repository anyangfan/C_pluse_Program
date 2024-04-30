# atomic vs atomic_flag

## atomic

C++中的`std::atomic`提供了对多线程环境下的原子操作的支持。它能够确保对共享数据的操作是原子的，即不会被其他线程中断。以下是`std::atomic`的典型用法：

1. **保护共享变量**：`std::atomic`可用于保护共享变量，确保在多线程环境下对该变量的读写操作是线程安全的。

    ```cpp
    #include <atomic>
    #include <thread>

    std::atomic<int> shared_counter(0);

    void increment_counter() {
        for (int i = 0; i < 1000; ++i) {
            shared_counter++;
        }
    }

    int main() {
        std::thread t1(increment_counter);
        std::thread t2(increment_counter);

        t1.join();
        t2.join();

        std::cout << "Final counter value: " << shared_counter << std::endl;

        return 0;
    }
    ```

2. **使用原子操作**：`std::atomic`提供了多种原子操作函数，如`load()`、`store()`、`exchange()`、`compare_exchange_weak()`、`fetch_add()`、`fetch_sub()`等，可以对原子类型进行特定的原子操作。

    ```cpp
    #include <atomic>
    #include <thread>

    std::atomic<int> shared_counter(0);

    void increment_counter() {
        for (int i = 0; i < 1000; ++i) {
            shared_counter.fetch_add(1); // 原子的增加操作
        }
    }

    int main() {
        std::thread t1(increment_counter);
        std::thread t2(increment_counter);

        t1.join();
        t2.join();

        std::cout << "Final counter value: " << shared_counter << std::endl;

        return 0;
    }
    ```

3. **原子布尔操作**：`std::atomic<bool>`常用于实现简单的锁。

    ```cpp
    #include <atomic>
    #include <thread>

    std::atomic<bool> lock(false);

    void critical_section() {
        while (lock.exchange(true, std::memory_order_acquire)) {
            // 如果锁已经被占用，等待
        }
        // 执行临界区代码
        lock.store(false, std::memory_order_release); // 释放锁
    }

    int main() {
        std::thread t1(critical_section);
        std::thread t2(critical_section);

        t1.join();
        t2.join();

        return 0;
    }
    ```

这些是`std::atomic`的一些典型用法，它提供了一种在多线程环境中进行原子操作的可靠方式。

## atomic_flag

在C++中，`std::atomic_flag` 是一种特殊的原子类型，通常用于实现简单的自旋锁。它提供了一种轻量级的原子标志，可以在多线程环境中对其进行原子测试和设置操作。以下是`std::atomic_flag`的典型用法示例：

```cpp
#include <iostream>
#include <atomic>
#include <thread>

std::atomic_flag lock = ATOMIC_FLAG_INIT; // 初始化为清除状态

void critical_section(int id) {
    while (lock.test_and_set(std::memory_order_acquire)) {
        // 如果锁已经被占用，等待
    }
    std::cout << "Thread " << id << " entered critical section" << std::endl;
    // 模拟临界区代码
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Thread " << id << " exited critical section" << std::endl;
    lock.clear(std::memory_order_release); // 释放锁
}

int main() {
    std::thread t1(critical_section, 1);
    std::thread t2(critical_section, 2);

    t1.join();
    t2.join();

    return 0;
}
```

在上面的示例中，我们使用 `std::atomic_flag` 来实现了一个简单的自旋锁。其中的 `test_and_set()` 函数会原子地将 `lock` 的标志设置为 `true`（表示锁已被占用），并返回先前的值。如果先前的值为 `true`，则表示锁已被占用，此时线程将进入自旋等待；如果先前的值为 `false`，则表示成功获取了锁，线程可以进入临界区执行任务。临界区执行完毕后，使用 `clear()` 函数来释放锁。

`std::atomic_flag` 是一种适用于简单互斥的原子类型，但它没有 `std::atomic` 那样丰富的操作函数。它只提供了 `test_and_set()` 和 `clear()` 两个成员函数，分别用于测试并设置标志以及清除标志。

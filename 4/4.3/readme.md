# 仿函数类

在C++中，仿函数（Functor）是一个类或结构体，它定义了函数调用操作符 `operator()`。这使得该类的实例可以像函数一样被调用。仿函数类经常被用于STL（标准模板库）中的算法和容器，用于提供自定义的操作和排序准则。

在你提供的代码中，`TestB` 类就是一个仿函数类。它定义了一个调用运算符 `operator()`，接受两个参数 `const TestA& t1` 和 `const TestA& t2`，并返回一个布尔值。

详细解释 `bool operator() (const TestA& t1, const TestA& t2)const`：

- `bool`: 这是函数的返回类型，说明 `operator()` 将返回一个布尔值。
- `operator()`: 这是函数调用运算符，使得 `TestB` 的对象可以被像函数一样调用。
- `(const TestA& t1, const TestA& t2)`: 这是参数列表，指定了该函数接受两个常量引用参数，这两个参数是 `TestA` 类型的对象。
- `const`: 这修饰了函数，表示这个操作符函数不会修改 `TestB` 对象的状态。
- 函数体内部实现了一个比较逻辑，首先比较两个 `TestA` 对象的姓氏（last name），如果姓氏不同，则直接返回比较结果；如果姓氏相同，则比较名字（first name），并返回比较结果。

这个操作符函数实现了 `TestB` 类的仿函数功能，

在 `main()` 函数中，类 `TestB` 并没有被直接调用，而是在定义 `set<TestA, TestB> sett;` 中作为模板参数传递给 `set` 容器。在这里，`TestB` 被用作容器 `sett` 的排序准则，而不是被直接调用。
在这个示例中，`TestB` 类是一个仿函数类，用于定义 `set<TestA, TestB>` 中元素的排序方式。当元素被插入到 `sett` 集合中时，`set` 容器会使用 `TestB` 类中定义的比较规则来排序这些元素。

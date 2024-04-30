# STL

## 列表，队列，容器，迭代器的区别

1. 列表：在C++中，列表（list）通常使用标准库中的std::list实现。与队列相比，列表是一种双向链表数据结构，可以在任意位置插入或删除元素，
2. 队列：在C++中，队列（queue）是一种先进先出（FIFO）的数据结构，只能在队尾插入元素，在队头删除元素。
3. 列表与队列区别：列表与队列的主要区别在于其操作的灵活性。列表允许在任意位置进行插入和删除操作，而队列只能在队尾插入元素，在队头删除元素。这使得列表更适合需要频繁在中间位置插入或删除元素的场景，而队列更适合按照先进先出的顺序处理数据的场景。
4. 容器：容器（container）是指用来存储数据的数据结构，C++中常用的容器包括vector、list、deque、set、map等。
5. 迭代器：迭代器（iterator）是用来遍历容器中元素的对象。
6. 队列和容器是两种不同的概念，队列是一种特定的数据结构，而容器是一种通用的数据存储结构。迭代器是用来遍历容器中元素的工具，可以用于访问和操作容器中的元素。

## queue

队列也是一种逻辑数据结构，其具有先进先出的特性，只能在队的前端进行删除， 在队的后端进行插入。针对这种特性，可以实现一些较为复杂的逻辑。在实际应用中，部分程序也正需要这样一种顺序进出的数据处理方式。使用这样的逻辑处理方式，使得我们可以将更多精力放在如何处理顺序逻辑之外的事情，对于编程、开发来讲，提供了极大的方便。
只能访问 `queue<T>` 容器适配器的第一个和最后一个元素。只能在容器的末尾添加新元素，只能从头部移除元素。许多程序都使用了 queue 容器。queue 容器可以用来表示商场结账队列或服务器上等待执行的数据库事务队列。对于任何需要用 FIFO 准则处理的序列来说，使用 queue 容器适配器都是好的选择。

### 01queue.cpp

1. queue基本用法
2. queue::back,queue::emplace,queue::push/pop

## set集合

STL 对这个序列可以进行查找、插入、删除序列中的任意一个元素，而完成这些操作的时间同这个序列中元素个数的对数成比例关系，并且当游标指向一个已删除的元素时，删除操作无效。而一个经过更正的和更加实际的定义应该是：`一个集合(set)是一个容器，它其中所包含的元素的值是唯一的`。这在收集一个数据的具体值的时候是有用的。集合中的元素按一定的顺序排列，并被作为集合中的实例。`一个集合通过一个链表来组织，在插入操作和删除操作上比向量(vector)快`，但查找或添加末尾的元素时会有些慢。具体实现采用了红黑树的平衡二叉树的数据结构。

### begin与cbegin

在C++的set容器中，begin()和cbegin()都用于获取指向第一个元素的迭代器。它们的主要区别在于const修饰符的使用：

begin()返回的迭代器可以用于修改set中的元素，因此如果set对象不是const对象，begin()返回的迭代器是一个普通迭代器。
cbegin()返回的迭代器是一个常量迭代器，它指向set中的第一个元素，并且不能用于修改set中的元素。即使set对象本身是非const的，cbegin()返回的迭代器也是常量迭代器，因此不能用于修改元素，只能用于读取元素。
因此，cbegin()通常用于在不需要修改set中元素的情况下进行迭代，而begin()可以用于需要修改元素的情况下进行迭代。

### set::emplace

```cpp
 std::set<std::string> myset_string;
 myset_string.emplace("foo");
 myset_string.emplace("bar");
 auto ret = myset_string.emplace("foo");
 if (!ret.second)
  std::cout << "foo already exists in myset\n";
```

这段代码使用了C++中的std::set容器，该容器存储了std::string类型的元素。下面是对代码的解释：

1. `std::set<std::string> myset_string;` - 创建了一个空的std::set容器，该容器存储std::string类型的元素。

2. `myset_string.emplace("foo");` - 向set中插入了一个字符串"foo"。

3. `myset_string.emplace("bar");` - 向set中插入了另一个字符串"bar"。

4. `auto ret = myset_string.emplace("foo");` - 尝试向set中插入字符串"foo"，由于"foo"已经存在于set中，所以插入操作将失败。emplace函数返回一个pair对象，其中pair.first是一个迭代器，指向包含"foo"的元素，pair.second是一个bool值，表示插入是否成功。在这种情况下，ret.second将是false。

5. `if (!ret.second)` - 检查插入操作的结果。如果插入失败（即ret.second为false），则输出"foo already exists in myset"。

总结：这段代码首先向set中插入了两个字符串"foo"和"bar"，然后尝试再次插入"foo"，但由于"foo"已经存在于set中，插入操作失败。最后输出了一个空行。

### set::get_allocator()

`set::get_allocator()`是一个成员函数，用于获取set对象的分配器。
`get_allocator()` 是 C++ 中 std::set 容器的一个成员函数，其作用是获取当前 set 对象使用的内存分配器。

用法如下：

```cpp
std::allocator<std::string> alloc = myset_string.get_allocator();
```

这将返回一个分配器对象，该对象与当前 set 对象使用的分配器相同。可以使用这个分配器来分配内存以及构造和销毁对象。
通常情况下，对于大多数使用场景来说，使用默认的分配器就足够了，但是在某些特殊情况下，你可能需要检索和使用 set 容器的分配器。

## map

在 C++ 中，map 是一种关联容器，它存储键值对，并确保键的唯一性。map 的键是唯一的，并且用于快速查找和排序。map 的键必须能够进行比较，以确定其排序顺序。

### 03mapdemos.cpp

1. map容器的声明
2. mymap::at map::begin map::end map::clear map::erase map::emplace map::find map::count map::count

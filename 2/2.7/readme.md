# STL

STL是Standard Template Library的简称，中文名标准模板库，惠普实验室开发的一系列软件的统称。它是由Alexander Stepanov、Meng Lee和David R Musser在惠普实验室工作时所开发出来的。从根本上说，STL是一些“容器”的集合，这些“容器”有list,vector,set,map等，STL也是算法和其他一些组件的集合。这里的“容器”和算法的集合指的是世界上很多聪明人很多年的杰作。STL的目的是标准化组件，这样就不用重新开发，可以使用现成的组件。STL是C++的一部分，因此不用安装额外的库文件。
STL的版本很多，常见的有HP STL、PJ STL、 SGI STL等。
在C++标准中，STL被组织为下面的13个头文件：`<algorithm>`、`<deque>`、`<functional>`、`<iterator>`、`<vector>`、`<list>`、`<map>`、`<memory.h>`、`<numeric>`、`<queue>`、`<set>`、`<stack>`和`<utility>`。

## vector

序列式容器vector：向量(vector) 连续存储的元素`<vector>`
vector 容器是 STL 中最常用的容器之一，它和 array 容器非常类似，都可以看做是对 C++ 普通数组的“升级版”。不同之处在于，array 实现的是静态数组（容量固定的数组），而 vector 实现的是一个动态数组，即可以进行元素的插入和删除，在此过程中，vector 会动态调整所占用的内存空间，整个过程无需人工干预。
vector 常被称为向量容器，因为该容器擅长在尾部插入或删除元素，在常量时间内就可以完成，时间复杂度为O(1)；而对于在容器头部或者中部插入或删除元素，则花费时间要长一些（移动元素需要耗费时间），时间复杂度为线性阶O(n)。

### 1.1 vector分配的空间是连续的吗

是的，标准库中的 std::vector 会分配连续的内存空间以存储其元素。这是 std::vector 的一个关键特性，它保证了元素在内存中是紧密排列的，这也是其快速访问和随机访问的基础。
当您向 std::vector 添加元素时，如果空间不足以容纳新元素，它会重新分配更大的内存空间，并将所有元素复制到新的内存位置。这确保了 std::vector 的元素在内存中是连续存储的。
这种连续存储的特性使得 std::vector 的随机访问非常高效，因为可以直接通过指针算术（例如 &vec[0] + index）来访问特定索引处的元素，而不需要像链表等数据结构那样遍历整个结构。

## deque

前面已接触过vector 容器，值得一提的是，deque 容器和 vecotr 容器有很多相似之处，比如：deque 容器也擅长在序列尾部添加或删除元素（时间复杂度为O(1)），而不擅长在序列中间添加或删除元素。deque 容器也可以根据需要修改自身的容量和大小。
和 vector 不同的是，deque 还擅长在序列头部添加或删除元素，所耗费的时间复杂度也为常数阶O(1)。并且更重要的一点是，deque 容器中存储元素并不能保证所有元素都存储到连续的内存空间中。
当需要向序列两端频繁的添加或删除元素时，应首选 deque 容器。

### 2.1 deque分配的空间是连续的吗

不一定。标准库中的 std::deque（双端队列）分配的空间不一定是连续的。std::deque 是一个双端队列，它以块的形式存储元素，因此它的内存分配是分块的，每个块内部是连续的，但是块与块之间不一定是连续的。

这种分块的内存分配使得 std::deque 能够在两端高效地进行插入和删除操作，而不像 std::vector 那样需要重新分配整个内存空间。但是，由于内存的非连续性，std::deque 的随机访问比 std::vector 要慢一些。

总的来说，std::deque 的内存分配是由多个块组成的，每个块内部是连续的，但是块与块之间不一定是连续的。

## stack

容器适配器是一个封装了序列容器的类模板，它在一般序列容器的基础上提供了一些不同的功能。之所以称作适配器类，是因为它可以通过适配容器现有的接口来提供不同的功能。
`stack<T>`容器适配器中的数据是以 LIFO 的方式组织的，这和自助餐馆中堆叠的盘子、箱子中的一堆书类似。理论上的 stack 容器及其一些基本操作。只能访问 stack 顶部的元素；只有在移除 stack 顶部的元素后，才能访问下方的元素。

# constexpr

## 作用

在C++中，`constexpr` 是一个关键字，用于声明一个表达式或函数可以在编译时被计算，而不是在运行时。它可以应用于变量、函数和构造函数。

下面是一些`constexpr`的主要作用：

1. **编译时计算**：使用`constexpr`声明的变量或函数可以在编译时进行计算，这意味着它们的值在程序编译阶段就已知，而不需要在运行时计算。这有助于提高程序的性能和效率。

2. **用于常量表达式**：`constexpr` 可以用于声明常量表达式。常量表达式是在编译时可以被完全求值的表达式，它们可以用于一些要求常量的场景，如数组大小、模板参数等。

3. **提供编译时类型检查**：使用`constexpr`可以在编译时对表达式进行类型检查，从而减少在运行时出现的错误。

4. **优化**：编译器可以对`constexpr`表达式进行优化，因为它们在编译时就已经确定了值，这样可以更好地优化代码。

## 典型使用

下面是一些使用`constexpr`的例子：

```cpp
// 声明一个constexpr变量
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// 声明一个constexpr函数
constexpr int square(int x) {
    return x * x;
}

int main() {
    constexpr int result1= factorial(5); // 在编译时计算出结果 120

    int x = 4;
    constexpr int result2 = square(x); // 在编译时计算出结果 16

    // 使用constexpr声明数组大小
    constexpr int size = factorial(3);
    int arr[size]; // 编译时确定数组大小为6

    return 0;
}
```

在上面的例子中，我们使用`constexpr`声明了一个计算阶乘的函数和一个计算平方的函数。在`main`函数中，我们使用`constexpr`计算了阶乘和平方，并且使用`constexpr`声明了数组的大小，这些都在编译时就已经确定了值。

总的来说，`constexpr`的作用是让一些表达式或函数在编译时就能被计算，提高程序的性能和效率，并且可以在编译时进行类型检查，减少运行时错误。

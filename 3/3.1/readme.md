# decltype

`decltype` 是 C++11 中引入的一个关键字，用于推断表达式的类型，并且可以在编译期间获取表达式的类型。

其全称是 "decltype specifier"。它的作用是根据表达式的类型推导出一个类型，但并不实际计算表达式的值。
比如：

```cpp
int x = 5;
decltype(x) y; // y的类型为int，与x的类型相同
```

`decltype` 还可以用于获取函数返回值的类型、自动推断lambda表达式的返回类型等。

示例：

```cpp
int func(int a, double b) {
    return a + b;
}

int main() {
    decltype(func(1, 2.0)) result; // result的类型为int，与func(1, 2.0)的返回类型相同
    return 0;
}
```

`decltype` 的作用是根据表达式推导出其类型，而不需要实际计算表达式的值，这使得代码更加灵活，并且可以在编译期间进行类型检查。

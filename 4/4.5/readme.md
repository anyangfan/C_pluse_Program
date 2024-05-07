# C++异常

## C++异常概念

- 异常是一种处理错误的方式，当一个函数发现自己无法处理的错误时就可以抛出异常，让函数的直接或间接的调用者处理这个错误，使用异常处理错误并不会终止程序

- 关于异常的关键字介绍如下：
`throw`: 当问题出现时，程序会抛出一个异常。这是通过使用 throw 关键字来完成的
`try`: try 块中的代码标识将被激活的特定异常,它后面通常跟着一个或多个 catch 块
`catch`: 在想要处理问题的地方，通过异常处理程序捕获异常。catch 关键字用于捕获异常，可以有多个 catch 进行捕获
如果有一个块抛出一个异常，捕获异常的方法会使用 try 和 catch 关键字。try 块中放置可能抛出异常的代码，try 块中的代码被称为保护代码。

- 使用 try/catch 语句的语法如下所示：

```cpp
try
{
// 保护的标识代码
}
catch (ExceptionName e1)
{
// catch 块
}
catch (ExceptionName e2)
{
// catch 块
}
catch (ExceptionName eN)
{
// catch 块
}
//catch...
```

## C++标准库的异常体系

C++ 提供了一系列标准的异常，定义在 std::exception 中，我们可以在程序中使用这些标准的异常。
它们是以父子类层次结构组织起来的，如下所示:

![C++标准库](/4/4.5/material_lib/1.png)
![C++标准库](/4/4.5/material_lib/2.png)

### dynamic_cast

`dynamic_cast` 是 C++ 中的一个类型转换运算符，通常用于在运行时进行安全的类型转换。当你试图将一个指向基类对象的指针或引用转换为指向派生类对象的指针或引用时，可以使用 `dynamic_cast`。如果转换是不安全的，则 `dynamic_cast` 将返回 `nullptr`（对于指针）或抛出 `std::bad_cast` 异常（对于引用）。

下面是 `dynamic_cast` 的基本语法：

```cpp
derived_type* ptr = dynamic_cast<derived_type*>(base_ptr);
```

其中 `base_ptr` 是指向基类对象的指针，`derived_type` 是派生类的类型。如果 `base_ptr` 指向的对象实际上是 `derived_type` 类型的对象或其派生类，那么转换将成功，`ptr` 将指向该对象；否则，如果转换是不安全的，则 `ptr` 将为 `nullptr`。

然而，要使用 `dynamic_cast` 进行安全转换，基类必须是多态的，即其中至少有一个虚函数。这是因为 `dynamic_cast` 依赖于运行时类型信息（RTTI），而虚函数表是实现 RTTI 的一种常见方式。如果基类没有虚函数，那么 `dynamic_cast` 将无法工作，因为它无法确定对象的实际类型。

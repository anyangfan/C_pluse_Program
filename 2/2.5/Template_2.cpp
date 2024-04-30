#include <iostream>
#include <string>
using namespace std;

template<typename T> // 模板声明，其中T为类型参数
class CompareSS
{
public:
    CompareSS(T a, T b)
    {
        x = a;
        y = b;

    }
    T maxfunc()
    {
        return (x > y ? x : y);

    }

private:
    int x, y;
};

int main()
{
    // 用类模板定义对象，此时T被int参数化替代
    CompareSS<int> obj1(30, 90);
    cout << "\n最大值为:" << obj1.maxfunc() << endl;

    CompareSS<double> obj2(30.98, 90.56);
    cout << "\n最大值为:" << obj1.maxfunc() << endl;

    return 0;
}

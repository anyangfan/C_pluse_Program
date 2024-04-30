#include <iostream>
using namespace std;

namespace Onespace {  // 第一命名空间
    void print() {
        cout << "执行Onespace名字空间的print()函数." << endl;
    }

    namespace Twospace {  // 第二命名空间
        void print() {
            cout << "执行Twospace名字空间的print()函数." << endl;
        }
    }

}

using namespace Onespace::Twospace;
int main()
{
    print();

    return 0;
}

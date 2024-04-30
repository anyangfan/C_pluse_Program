#include <iostream>
using namespace std;

namespace Onespace {  // 第一命名空间
   void print() {
       cout << "执行Onespace名字空间的print()函数." << endl;
   }
}

namespace Twospace {  // 第二命名空间
   void print() {
       cout << "执行Twospace名字空间的print()函数." << endl;
   }
}

int main()
{
   // 调用第一个命名空间中的print函数
   Onespace::print();
   Twospace::print();    

   return 0;
}

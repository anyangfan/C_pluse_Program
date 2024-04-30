#include <iostream>
#include <string>
using namespace std;
/*
* 求两个数字中，最大数？
*/
#include <iostream>
#include <string>
using namespace std;

template <typename T>
inline T const& MaxFunc(T const& a, T const& b)
{
   return a > b ? a : b;
}

int main()
{

   int i = 90, j = 100;
   cout << "MaxFunc(i,j):" << MaxFunc(i, j) << endl;

   double f1 = 23.9, f2 = 45.88;
   cout << "MaxFunc(f1,f2):" << MaxFunc(f1, f2) << endl;

   string s1 = "Helloworld", s2 = "goodbye";
   cout << "MaxFunc(s1,s2):" << MaxFunc(s1, s2) << endl;

   return 0;
}
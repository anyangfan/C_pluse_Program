#include <iostream>
using namespace std;

class InCount
{
public:
    InCount(int a = 0, int b = 0)
    {
        c1 = a;
        c2 = b;
    }
    void show(void)
    {
        cout << "c1=" << c1 << "\t" << "c2=" << c2 << endl;
    }
    
    friend istream& operator>>(istream&, InCount&);
    friend ostream& operator<<(ostream&, InCount&);

private:
    int c1, c2;
};

istream& operator>>(istream& is, InCount& cc)
{
    is >> cc.c1 >> cc.c2;
    return is;
}

ostream& operator<<(ostream& os, InCount& cc)
{
    os << "c1=" << cc.c1 << "\t" << "c2=" << cc.c2 << endl;
    return os;
}

int main()
{
    InCount obj1, obj2;
    cout << obj1 << obj2 << endl; // 调用输出函数
    
    cin >> obj1;
    cin >> obj2;

    cout << obj1 << obj2;


    return 0;
}


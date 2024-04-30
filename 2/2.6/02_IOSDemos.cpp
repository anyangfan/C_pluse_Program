#include <iostream>
using namespace std;

class CinCount
{
public:
    CinCount(int a = 0, int b = 0)
    {
        c1 = a;
        c2 = b;
    }
    void showc1c2(void)
    {
        cout << "c1=" << c1 << '\t' << "c2=" << c2 << endl;
    }

    friend istream& operator>>(istream&, CinCount&);

private:
    int c1, c2;
};

istream& operator>>(istream& is, CinCount& cc)
{
    is >> cc.c1 >> cc.c2;
    return is;
}

int main()
{
    CinCount o1, o2;
    o1.showc1c2();
    o2.showc1c2();

    cin >> o1;
    cin >> o2;
    o1.showc1c2();
    o2.showc1c2();

    return 0;
}

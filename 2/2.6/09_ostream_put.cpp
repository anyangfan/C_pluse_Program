// 009.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch;

    ofstream outFile("outdemo.txt", ios::out | ios::binary | ios::trunc);

    if (!outFile)
    {
        cout << "\noutdemo.txt文件打开失败." << endl;
        return 0;
    }
    else
        cout << "\noutdemo.txt文件打开成功." << endl;

    // while (cin >> ch)
    // {
    //     outFile.put(ch);
    // }
    //从键盘接收字符
    while (cin.get(ch))
    {
        //检测到终止符
        if (ch == '.')
            break;
        outFile.put(ch);
    }

    outFile.close();

    return 0;
}


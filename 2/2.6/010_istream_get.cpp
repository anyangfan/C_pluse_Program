// 009.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch;

    ifstream inFile("outdemo.txt", ios::out | ios::binary);

    if (!inFile)
    {
        cout << "\noutdemo.txt文件打开失败." << endl;
        return 0;
    }
    else
        cout << "\noutdemo.txt文件打开成功." << endl;

    // 读取文件内容
    while (inFile.get(ch))
        cout << ch;

    inFile.close();

    return 0;
}



#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //ifstream inFile;
    //inFile.open(".\\demo.txt", ios::in);
    //if (inFile) // 条件成立，则说明文件打开成功
    //{
    //    cout << "\ndemo.txt文件打开成功." << endl;
    //    inFile.close();
    //}
    //else
    //{
    //    cout << "\ndemo.txt文件打开失败." << endl;
    //    return 1;
    //}

    //ofstream outFile;
    //outFile.open(".\\outdemo.txt", ios::out);
    //if (outFile) // 条件成立，则说明文件打开成功
    //{
    //    cout << "\noutdemo.txt文件打开成功." << endl;
    //    outFile.close();
    //}
    //else
    //{
    //    cout << "\noutdemo.txt文件打开失败." << endl;
    //}

    fstream ioFile;
    ioFile.open("./iodemo.txt", ios::in | ios::out | ios::trunc);

    if (ioFile)
    {
        cout << "\niodemo.txt文件打开成功." << endl;
        ioFile.close();
    }
    else
    {
        cout << "\niodemo.txt文件打开失败." << endl;
    }

    return 0;
}


#include <iostream>
#include <fstream>
using namespace std;

class student
{
public:
    int no;
    char name[10];
    int age;
};

int main()
{
    student stu;
    ofstream outFile("student.dat", ios::out | ios::in | ios::binary | ios::trunc);

    if (!outFile)
    {
        cout << "\n打开文件student.txt失败." << endl;
        outFile.close();
    }
    else
    {
        cout << "\n打开文件student.txt成功." << endl;
    }

    while (cin >> stu.no >> stu.name >> stu.age)
        outFile.write((char*)&stu, sizeof(stu));

    outFile.close();

    // 读取并打印数据
    ifstream inFile("student.dat", ios::in | ios::binary);
    if (!inFile)
    {
        cout << "打开文件student.dat失败." << endl;
    }
    else
    {
        cout << "打开文件student.dat成功." << endl;
        
        while (inFile.read((char*)&stu, sizeof(stu)))
        {
            cout << "学号: " << stu.no << ", 姓名: " << stu.name << ", 年龄: " << stu.age << endl;
        }
        
        inFile.close();  // 关闭文件
    }
    
    return 0;
}


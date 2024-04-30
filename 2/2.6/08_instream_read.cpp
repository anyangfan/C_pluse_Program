
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
    ifstream inFile("student.dat", ios::in | ios::binary); // 二进制读方式打开此文件 
    
    if (!inFile)
    {
        cout << "\n打开失败." << endl;
        return 0;
    }
    else
        cout << "\nstudent.dat文件打开成功." << endl;

    while (inFile.read((char*)&stu, sizeof(stu)))
    {
        cout << stu.no << "," << stu.name << "," << stu.age << endl;
    }
    inFile.close();

    return 0;
}


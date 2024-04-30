
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	const char* str = "hello world";

	fstream fs;

	// 将demo.txt文件和fs文件流建立关联
	fs.open("demo.txt", ios::out);
	// //打开失败则打印错误
	// if (!fs)
	// {
	// 	cout << "open file error!" << endl;
	// 	return 0;
	// }
	

	fs.write(str, strlen(str));

	fs.close();

	return 0;
}


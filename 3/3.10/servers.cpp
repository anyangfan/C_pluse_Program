#include <iostream>
#include <Windows.h>
using namespace std;

#define BUF_SIZE 1024

int main()
{
	// 定义一个字符数组，存放待写入映射内存的内容
	char szBuffer[] = "hello word";

	// 创建一个文件映射对象，用于后续的内存映射
	HANDLE hmFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, 
		PAGE_READWRITE, 0, BUF_SIZE, "LSEDU");

	// 将文件映射到进程的地址空间
	LPVOID lpBase = MapViewOfFile(hmFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);

	
	strcpy((char*)lpBase, szBuffer);
	cout << "lpBase:" << (char*)lpBase << endl << endl;

	
	Sleep(20000);

	
	UnmapViewOfFile(lpBase);

	CloseHandle(hmFile);


	return 0;
}
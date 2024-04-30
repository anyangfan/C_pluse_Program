#include <iostream>
#include <Windows.h>
using namespace std;

#define BUF_SIZE 1024

int main()
{
    HANDLE hmFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL,
                                      PAGE_READWRITE, 0, BUF_SIZE, "LSEDU");
    LPVOID lpBase = MapViewOfFile(hmFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);
    char *lpBuffer = new char[BUF_SIZE];
    if (hmFile)
    {
        strcpy(lpBuffer, (char *)lpBase);
        cout << "client:" << lpBuffer << endl
             << endl;
    }
    delete[] lpBuffer;
    UnmapViewOfFile(lpBase);
    CloseHandle(hmFile);
    return 0;
}
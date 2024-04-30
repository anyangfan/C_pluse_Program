#include <iostream>
#include <string>
#include <windows.h>
#include <memory>

// 定义BUF_SIZE，此处假设为1024
const int BUF_SIZE = 1024;

// 使用std::unique_ptr管理动态分配的内存
//std::unique_ptr<char[]> lpBufferSmart;
std::unique_ptr<char> *lpBufferSmart;

int main()
{
    // 使用nullptr代替NULL，提高代码的可读性和一致性
    HANDLE hmFile = CreateFileMapping(INVALID_HANDLE_VALUE, nullptr,
                                      PAGE_READWRITE, 0, BUF_SIZE, "LSEDU");
    LPVOID lpBase = MapViewOfFile(hmFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);

    // 检查hmFile和lpBase是否成功创建/映射
    if (hmFile == INVALID_HANDLE_VALUE || lpBase == nullptr)
    {
        std::cerr << "Error: File mapping failed." << std::endl;
        // 当hmFile为INVALID_HANDLE_VALUE时，应该关闭它
        if (hmFile != INVALID_HANDLE_VALUE)
            CloseHandle(hmFile);
        return -1;
    }

    // 使用std::string代替原始字符数组，提高安全性
    std::string bufferStr(reinterpret_cast<const char*>(lpBase), BUF_SIZE);

    // 输出到标准输出
    std::cout << "client:" << bufferStr << std::endl << std::endl;

    // UnmapViewOfFile和CloseHandle的调用被包含在了RAII对象的析构函数中，确保资源总是被释放

    return 0;
}

// 当使用std::unique_ptr时，需要提供一个删除器，以正确地释放资源
struct MapViewOfFileDeleter
{
    void operator()(void* p)
    {
        UnmapViewOfFile(p);
    }
};

// 为了使用std::unique_ptr<char[]>管理动态数组，需要提供一个相应的删除器
struct ArrayDeleter
{
    void operator()(char* p)
    {
        delete[] p;
    }
};
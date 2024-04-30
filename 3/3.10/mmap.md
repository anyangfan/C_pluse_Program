# mmap

在Linux下使用`CreateFileMapping`函数是不适用的，因为`CreateFileMapping`是Windows特定的函数，用于创建文件映射对象，而Linux中没有这个函数。

如果你需要在Linux中实现类似的功能，可以使用`mmap`函数来创建内存映射，它允许你将文件或者其他对象映射到内存中。

要使用`mmap`函数，你需要包含以下头文件：

```cpp
#include <sys/mman.h> // 包含 mmap 函数的声明
#include <fcntl.h>    // 包含 O_RDONLY 和其他标志
#include <unistd.h>   // 包含 close 函数
#include <sys/types.h>
```

然后，你可以使用`mmap`函数来创建内存映射。下面是一个简单的示例：

```cpp
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>

int main() {
    // 打开文件
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 获取文件大小
    off_t size = lseek(fd, 0, SEEK_END);
    if (size == -1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    // 将文件映射到内存
    void *addr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    // 使用映射后的内存...
    
    // 解除内存映射
    if (munmap(addr, size) == -1) {
        perror("munmap");
        close(fd);
        return 1;
    }

    // 关闭文件
    close(fd);

    return 0;
}
```

这段代码打开一个文件，获取其大小，然后使用`mmap`函数将文件映射到内存中。记得在使用完后，解除内存映射并关闭文件。

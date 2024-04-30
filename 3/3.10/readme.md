# CreateFileMapping、MapViewOfFile函数原型及参数

1. **CreateFileMapping函数**：
   `CreateFileMapping` 函数的原型及参数如下：

   ```cpp
   HANDLE CreateFileMapping(
       HANDLE hFile,                 // 文件句柄或者 INVALID_HANDLE_VALUE
       LPSECURITY_ATTRIBUTES lpAttributes,  // 安全属性，通常为 NULL
       DWORD flProtect,              // 保护属性
       DWORD dwMaximumSizeHigh,      // 文件映射对象的最大大小（高位DWORD）
       DWORD dwMaximumSizeLow,       // 文件映射对象的最大大小（低位DWORD）
       LPCTSTR lpName                // 文件映射对象的名称
   );
   ```

   参数解释：
   - `hFile`：文件句柄或者 `INVALID_HANDLE_VALUE`。如果为 `INVALID_HANDLE_VALUE`，则表示创建一个未与任何现有文件相关联的文件映射对象。
   - `lpAttributes`：安全属性，通常为 `NULL`。
   - `flProtect`：保护属性，指定文件映射对象的保护级别，例如 `PAGE_READWRITE` 表示可读/可写。
   - `dwMaximumSizeHigh` 和 `dwMaximumSizeLow`：文件映射对象的最大大小，以 DWORD 形式给出。在这个例子中，用来指定文件映射对象的大小。
   - `lpName`：文件映射对象的名称，用于标识对象。

2. **MapViewOfFile函数**：
   `MapViewOfFile` 函数的原型及参数如下：

   ```cpp
   LPVOID MapViewOfFile(
       HANDLE hFileMappingObject,   // 文件映射对象的句柄
       DWORD dwDesiredAccess,       // 所需的访问权限
       DWORD dwFileOffsetHigh,      // 文件偏移的高位DWORD
       DWORD dwFileOffsetLow,       // 文件偏移的低位DWORD
       SIZE_T dwNumberOfBytesToMap  // 要映射的字节数
   );
   ```

   参数解释：
   - `hFileMappingObject`：文件映射对象的句柄，由 `CreateFileMapping` 返回。
   - `dwDesiredAccess`：所需的访问权限，例如 `FILE_MAP_ALL_ACCESS` 表示可读/可写。
   - `dwFileOffsetHigh` 和 `dwFileOffsetLow`：文件偏移的高位 DWORD 和低位 DWORD，用于指定视图开始的位置。
   - `dwNumberOfBytesToMap`：要映射的字节数，即要映射的文件映射的大小。

这两个函数一起使用，可以创建文件映射对象，并将其映射到当前进程的地址空间中，以实现共享内存的功能。

```c++
// 创建共享文件句柄
 HANDLE hmFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, BUF_SIZE, "LSEDU");

 // 映射
 LPVOID lpBase = MapViewOfFile(hmFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);
```

1. **CreateFileMapping函数**：
   `CreateFileMapping` 函数用于创建文件映射对象。其作用是在物理内存或虚拟内存中创建一个映射，将磁盘文件的一部分或全部映射到进程的地址空间中。具体参数解释如下：
   - `INVALID_HANDLE_VALUE`：指定创建一个未与任何现有文件相关联的文件映射对象。相反，它在系统分页文件中创建一个新的页面文件后备部分。
   - `NULL`：指定 `CreateFileMapping` 返回的句柄不能被子进程继承。
   - `PAGE_READWRITE`：将文件映射对象的保护设置为可读/可写。这意味着允许对映射文件进行读取和写入操作。
   - `0`：指定文件映射对象的最大大小的高阶 DWORD。在此代码中，设置为0。
   - `BUF_SIZE`：指定文件映射对象的最大大小的低阶 DWORD。在此代码中，它设置为1024。
   - `"LSEDU"`：这是文件映射对象的名称。它是一个字符串标识符，可用于从不同的进程访问同一个文件映射对象。

2. **MapViewOfFile函数**：
   `MapViewOfFile` 函数将文件映射的视图映射到调用进程的地址空间中。具体参数解释如下：
   - `hmFile`：前一步创建的文件映射对象的句柄。
   - `FILE_MAP_ALL_ACCESS`：指定对文件映射对象的访问权限。`FILE_MAP_ALL_ACCESS` 允许对映射文件进行读取和写入访问。
   - `0`：文件偏移的高阶 DWORD，指定视图开始的位置。在本例中，设置为0，表示视图从文件的开头开始。
   - `0`：文件偏移的低阶 DWORD，也设置为0。
   - `BUF_SIZE`：要映射到地址空间的文件映射的字节数。在此代码中，它设置为1024，与缓冲区的大小相同。

总之，这两行代码创建了一个名为 "LSEDU" 的文件映射对象，具有读/写访问权限，大小为1024字节，然后将该文件映射的视图映射到当前进程的地址空间中，允许对共享内存区域进行读写操作。

# 第014课 C++IO流类库

1. 02_IOSDemos 输入输出流
2. 03_Overloading_operator 重载运算符
3. 04_fstream，05_fstream，06_fstream fstream基本操作

## Overloading_operators重载运算符

1. fs.write(str, strlen(str))
    写入时请确定str字符串长度，若使用`fs.write(str, 100)`则会将乱码写入文件中

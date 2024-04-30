// vector assign
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;

    first.assign(7, 100); // 7 ints with a value of 100

    // 打印容器内容
    for (auto i = first.begin(); i < first.end(); i++)
    {
        std::cout << " " << *i << " ";
    }
    std::cout << "\n";

    std::vector<int>::iterator it;
    it = first.begin() + 1;

    second.assign(it, first.end() - 1); // the 5 central values of first

    int myints[] = {1776, 7, 4};
    third.assign(myints, myints + 3); // assigning from array.

    // 打印容器内容
    for (auto i = third.begin(); i < third.end(); i++)
    {
        std::cout << " " << *i << " ";
    }
    std::cout << "\n";

    std::cout << "Size of first: " << int(first.size()) << '\n';
    std::cout << "Size of second: " << int(second.size()) << '\n';
    std::cout << "Size of third: " << int(third.size()) << '\n';
    return 0;
}
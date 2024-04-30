#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 创建存储的double数据类型的一个vector容器-->v1
	vector<double> v1;

	// 创建容器v2且同时给它进行初始化元素的个数
	vector<int> v2{ 34,65,78,90,28,56,98,77,81,19 };
    cout << "v2: " ;
    for (int i = 0; i < v2.size(); i++)
    {
		cout << v2[i] << " ";        
    }
    cout << endl;

	// 创建vector容器，指定元素个数为50
	vector<int> v3(50,1);
    cout << "v3: " ;
    for (int i = 0; i < v3.size(); i++)
    {
		cout << v3[i] << " ";        
    }
    cout << endl;

	// 创建vector容器，它拥有10个字符为'A'
	vector<char> v4(10, 'A');
    cout << "v4: " ;
    for (int i = 0; i < v4.size(); i++)
    {
		cout << v4[i] << " ";        
    }
    cout << endl;

	// 将v4赋给v5
	vector<char> v5(v4);
    cout << "v5: " ;
    for (int i = 0; i < v5.size(); i++)
    {
		cout << v5[i] << " ";        
    }
    cout << endl;

	int a[] = { 10,20,30 };
	vector<int> v6(a, a + 2); // v4将会保存10，20
    cout << "v6: " ;
    for (int i = 0; i < v6.size(); i++)
    {
		cout << v6[i] << " ";        
    }
    cout << endl;

	vector<int> v7{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v8(begin(v7), begin(v7) + 3); // v8将会保存为：1,2,3
    cout << "v8: " ;
    for (int i = 0; i < v8.size(); i++)
    {
		cout << v8[i] << " ";        
    }
    cout << endl;

	return 0;
}

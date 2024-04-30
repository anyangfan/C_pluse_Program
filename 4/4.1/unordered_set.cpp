#include <iostream>
#include <string>
#include <set>
#include <unordered_set>

int main()
{
	std::unordered_set<int> un_set;

	un_set.insert(23);
	un_set.insert(33);
	un_set.insert(12);
	un_set.insert(78);
	un_set.insert(99);

	std::cout << "\nunordered_set:" << std::endl;
	for (auto it : un_set)
	{
		std::cout << it << std::endl;
	}
	std::cout << std::endl;

	std::set<int> st;
	st.insert(23);
	st.insert(33);
	st.insert(12);
	st.insert(78);
	st.insert(99);

	std::cout << "\nset:" << std::endl;
	for (auto it : st)
	{
		std::cout << it << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
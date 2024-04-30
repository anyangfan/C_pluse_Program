#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::regex string_reg("[1-9](\\d{5,11})");
	std::string strtest1("1032");
	std::string strtest2("1032423523");
	std::smatch matchresults;

	// 正则匹配
	if (std::regex_match(strtest1, matchresults, string_reg))
	{
		std::cout << "Match:" << std::endl;
		// 输出表达式结果
		for (size_t i = 0; i < matchresults.size(); i++)
		{
			std::cout << matchresults[i] << std::endl;
		}
	}
	else
	{
		std::cout << "Not Match:" << std::endl;
	}

	std::cout<<"/n"<<std::endl;

	if (std::regex_match(strtest2, matchresults, string_reg))
	{
		std::cout << "Match:" << std::endl;
		// 输出表达式结果
		for (size_t i = 0; i < matchresults.size(); i++)
		{
			std::cout << matchresults[i] << std::endl;
		}
	}
	else
	{
		std::cout << "Not Match" << std::endl;
	}

	return 0;
}


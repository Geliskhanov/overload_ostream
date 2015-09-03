#include <iostream>
#include <vector>

class Test
{
public:
	Test();
	Test(const std::vector<double> &num);

	std::vector<double>::const_iterator getBegin()const { return numbers.begin(); }
	std::vector<double>::const_iterator getEnd()const { return numbers.end(); }

private:
	std::vector<double> numbers;
};

Test::Test()
{

}

Test::Test(const std::vector<double> &num)
	: numbers(num)
{

}

std::ostream & operator<< (std::ostream & os, const std::vector<Test> &test)
{
/*
	for (auto i = test.begin(); i != test.end(); ++i)
	{
		for (auto j = (*i).numbers.begin(); j != (*i).numbers.end(); ++j)
			os << (*j) << " ";
		os << std::endl;
	}
	return os;
*/

	for (std::vector<Test>::const_iterator i = test.begin(); i != test.end(); ++i)
	{
		for (std::vector<double>::const_iterator j = (*i).getBegin(); j != (*i).getEnd(); ++j)
			os << (*j) << " ";
		os << std::endl;
	}
	return os;
}

int main()
{
	std::vector<Test> test;

	std::vector<double> vec;
	for (int i = 0; i < 5; ++i) vec.push_back(i);
	for (int i = 0; i < 5; ++i) test.push_back(Test(vec));
	std::cout << test;


	system("pause");
	return 0;
}
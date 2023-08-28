#include <iostream>
#include "Array.hpp"
#include <string>
#include "Fixed.hpp" // remove
#define MAX_VAL 750

void lks(void)
{
	system("leaks -q ex02");
}

int main(int, char**)
{
	atexit(lks);
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;

	std::cout << std::endl;
	std::cout << "-------------My Tests--------------" << std::endl;

	Array<char> charArr(10);
	for (int i = 0; i < 10; i++)
		charArr[i] = 'a' + i;

	for (int i = 0; i < 10; i++)
		std::cout << charArr[i] << " ";
	std::cout<<std::endl;

	try
	{
		char c = charArr[-1];
		std::cout << "char is: " << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		char c = charArr[100];
		std::cout << "char is: " << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "char is: " << charArr[5] << std::endl;
	std::cout << std::endl;

	Array<std::string> strArr(4);
	strArr[0] = "Hello";
	strArr[1] = "This";
	strArr[2] = "Is";
	strArr[3] = "A Test";

	for (int i = 0; i < 4; i++)
		std::cout << strArr[i] << " ";
	std::cout << std::endl;

	try
	{
		char c = charArr[100];
		std::cout << "char is: " << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "str is: " << strArr[1] << std::endl;
	std::cout << std::endl;

	Array<Fixed> fixedArr(3);
	fixedArr[0] = Fixed(1.1f);
	fixedArr[1] = Fixed(2.2f);
	fixedArr[2] = Fixed(3.3f);

	for (int i = 0; i < 3; i++)
		std::cout << fixedArr[i] << " ";
	std::cout << std::endl;

	std::cout << "fixed is: " << fixedArr[1] << std::endl;
	std::cout << fixedArr[0] + fixedArr[1] << std::endl;
	return 0;
}

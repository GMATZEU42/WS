#include <iostream>
#include <cmath>

int main()
{
	try
	{
		char tmp;
		int charRange = std::pow(2, 8 * sizeof(char));
		for (size_t i = 0u; i < charRange; ++i)
		{
			tmp = i;
			std::cout << "i: " << i << "\t" << tmp << "\n";
		}

		int x = 0;
		int maxInt = 0;
		int minInt = 0;
		while (++x != 0)
		{
			if (maxInt != 0 && minInt != 0 && x < 0)
			{
				minInt = x;
				maxInt = minInt -1;
			}
		}
		std::cout << "Max int: " << maxInt << "\n";
		std::cout << "Min int: " << minInt << "\n";
		return 0;
	}
	catch (...)
	{
		std::cout << "Ooops!\n";
		return 1;
	}
}
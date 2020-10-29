#include "prototypes.h"

int main()
{
	while (true)
	{
		if (!main_menu())
			return 0;
	}
}

bool main_menu()
{
	std::printf("Choose an option:\n"
				"1: Seminar 1\n"
				"2: Seminar 2\n"
				"3: Seminar 3\n"
				"4: Exit\n");
	try
	{
		auto action = read_int();
		switch (action)
		{
		case 1:
			task1::menu();
			return true;
		case 2:
			task2::menu();
			return true;
		case 3:
			printf("Option 3\n");
			return true;
		case 4:
			return false;
		default:
			throw std::invalid_argument("");
		}
	}
	catch (const std::invalid_argument& exception)
	{
		printf("You entered incorrect value! Please try again.\n\n\n");
		return true;
	}
}

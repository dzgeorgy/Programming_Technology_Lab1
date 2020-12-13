#include "../headers/prototypes.h"

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
	clear_screen();
	print_header("Main");
	std::printf("Choose an option:\n"
				"1: Seminar 3\n"
				"2: Seminar 4\n"
				"3: Seminar 5\n"
				"4: Exit\n");
	try
	{
		switch (read_int())
		{
		case 1:
			seminar3::entry();
			return true;
		case 2:
			seminar4::menu();
			return true;
		case 3:
			seminar5::menu();
			return true;
		case 4:
			return false;
		default:
			throw std::invalid_argument("");
		}
	}
	catch (const std::invalid_argument& exception)
	{
		printf("You entered incorrect value! Please try again.\n");
		await_input();
		return true;
	}
}

#include "prototypes.h"

void seminar5::menu()
{
	clear_screen();
	print_header("Main >> Seminar 5");
	printf("Please enter path to file:\n");
	std::string path;
	std::cin.ignore();
	std::getline(std::cin, path);
	while (true)
	{
		clear_screen();
		print_header("Main >> Seminar 5");
		print_path(path);
		printf("Choose an option:\n"
			   "1: Find words which start with vowel\n"
			   "2: Back\n");
		try
		{
			switch (read_int())
			{
			case 1:
			{
				clear_screen();
				print_header("Main >> Seminar 5");
				print_path(path);
				printf("%s", read_string(path).c_str());
				await_input();
				break;
			}
			case 2:
				return;
			default:
				throw std::invalid_argument("");
			}
		}
		catch (const std::invalid_argument& exception)
		{
			printf("You entered incorrect value! Please try again.\n\n\n");
		}
	}
}

void seminar5::print_path(const std::string& path)
{
	printf("Path is: %s\n===================================================================\n", path.c_str());
}

std::string seminar5::read_string(const std::string& path)
{
	std::ifstream file(path);
	if (!file.good()) return "";
	char word[15];
	int words_vowel_count = 0;
	while (file >> word)
	{
		if (isVowel(word[0]))
		{
			printf("%s ", word);
			++words_vowel_count;
		}
	}
	if (!words_vowel_count)
		printf("File doesn't contain words which begin with vowel\n");
	else printf("\n");
	return "";
}

bool seminar5::isVowel(char c)
{
	return c == 'A' || c == 'a' || c == 'E' || c == 'e' ||
		   c == 'Y' || c == 'y' || c == 'U' || c == 'u' ||
		   c == 'I' || c == 'i' || c == 'O' || c == 'o';
}
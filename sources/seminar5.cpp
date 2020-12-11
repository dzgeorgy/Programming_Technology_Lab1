#include "../headers/prototypes.h"

void seminar5::menu()
{
	clear_screen();
	print_header("Main >> Seminar 5");
	printf("Options available in this seminar:\n"
		   "1: Find words which start with vowel\n"
		   "===================================================================\n");
	printf("Please enter path to file:\n");
	std::string path;
	std::cin.ignore();
	std::getline(std::cin, path);
	std::fstream file(path);
	if (file.good())
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
					try
					{
						printf("%s\n", read_string(file).c_str());
					}
					catch (const std::logic_error& exception)
					{
						printf("Unable to read file! Reason: %s", exception.what());
					}
					await_input();
					break;
				}
				case 2:
					file.close();
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
	else
	{
		printf("Can't open file!\n");
		file.close();
		await_input();
		return;
	}
}

void seminar5::print_path(const std::string& path)
{
	printf("Path is: %s\n===================================================================\n", path.c_str());
}

std::string seminar5::read_string(std::basic_fstream<char>& file)
{
	std::string result;
	char word[15];
	int words_vowel_count = 0;
	if (file.eof()) throw std::logic_error("File is empty!\n");
	while (file >> word)
	{
		if (is_vowel(word[0]))
		{
			result.append(word).append(" ");
			++words_vowel_count;
		}
	}
	if (!words_vowel_count)
		throw std::logic_error("File doesn't contain words which begin with vowel\n");
	else
		return result;
}

bool seminar5::is_vowel(char c)
{
	return c == 'A' || c == 'a' || c == 'E' || c == 'e' ||
		   c == 'Y' || c == 'y' || c == 'U' || c == 'u' ||
		   c == 'I' || c == 'i' || c == 'O' || c == 'o';
}
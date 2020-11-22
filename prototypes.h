#pragma once

#include "libraries.h"

/**
 * Prints out main menu and handles user's choice of menu items.
 * @return True if application should continue work and false otherwise.
 */
bool main_menu();

/**
 * Tries to read integer value from console, throws an exception if not succeed.
 * @return Integer value.
 * @throws std::invalid_argument.
 */
static int read_int()
{
	char buffer[10];
	std::scanf("%s", buffer);
	return std::stoi(buffer, nullptr, 10);
}

/**
 * Tries to read double value from console, throws an exception if not succeed.
 * @return Double value.
 * @throws std::invalid_argument.
 */
static double read_double()
{
	char buffer[10];
	std::scanf("%s", buffer);
	return std::stod(buffer, nullptr);
}

/**
 * Clears screen by using os-dependent terminal commands
 */
static void clear_screen()
{
#if defined(_WIN32)
	system("cls");
#elif defined(__APPLE__) || defined(__linux__)
	system("clear");
#endif
}

/**
 * Prints out header
 * @param title - string which should be used as title
 */
static void print_header(const std::string& title)
{
	clear_screen();
	printf("===================================================================\n"
		   "%s\n"
		   "===================================================================\n", title.c_str());
}

/**
 * Awaits user's interaction with terminal by using os-dependent terminal commands
 */
static void await_input()
{
#if defined(_WIN32)
	system("pause");
#elif defined(__APPLE__) || defined(__linux__)
	system("read -n1 -r -p \"Press any key to continue...\n\"");
#endif
}

/**
 * Namespace for functions related to seminar 3.
 */
namespace seminar3
{

	struct Result
	{
		double sum;
		int quantity;
		int* indices;
	};

	/**
	 * Prints out menu for first task and handles user's choice.
	 */
	void menu();

	/**
	 * Creates an array with given size
	 * @param array_size - size of an array
	 * @return pointer to a created array
	 */
	double* create_array(int array_size);

	/**
	 * Prints out an array.
	 * @param array - an array to print.
	 * @param array_size - size of given array.
	 */
	void print_array(const double* array, int array_size);

	/**
	 * Finds a sum of odd elements of given array.
	 * @param array - an array which sum should be found.
	 * @param array_size - size of given array.
	 * @return an sum of elements.
	 */
	Result sum_of_odd_elements(const double* array, int array_size);

	/**
	 * Finds a sum of elements between first and last negative elements.
	 * @param array - an array which sum should be found.
	 * @param array_size - size of given array.
	 * @return an sum of elements.
	 */
	Result sum_of_elements_between_first_and_last_negatives(const double* array, int array_size);
}

/**
 * Namespace for functions related to seminar 4.
 */
namespace seminar4
{

	/**
 	* Prints out menu for second task and handles user's choice.
 	*/
	void menu();

	/**
	 * Lets user to fill an matrix.
	 * @param matrix - an array to fill.
	 * @param matrix_size - size of given array.
	 */
	void fill_matrix(int** matrix, int matrix_size);

	/**
	 * Prints out a matrix.
	 * @param matrix - a matrix to print.
	 * @param matrix_size - size of given matrix.
	 */
	void print_matrix(int** matrix, int matrix_size);

	/**
	 * Finds quantity of elements in rows which does not contain negative
	 * @param matrix - a matrix of elements
	 * @param matrix_size - size of given matrix
	 * @return quantity of elements
	 */
	int* quantity_of_elements_in_rows_without_negative(int** matrix, int matrix_size);

	/**
	 * Finds max sum of elements between diagonals parallel to main
	 * @param matrix - a matrix of elements
	 * @param matrix_size - size of given matrix
	 * @return max sum between diagonals parallel to main
	 */
	int find_max_sum_in_diagonals(int** matrix, int matrix_size);
}

/**
 * Namespace for functions related to seminar 5.
 */
namespace seminar5
{

	/**
 	* Prints out menu for second task and handles user's choice.
 	*/
	void menu();

	/**
	 * Reads file from specified path and returns string with words starts with vowels
	 * @param path - string which represents path to file which should be opened
	 * @return string read from
	 */
	std::string read_string(const std::string& path);

	/**
	 * Checks if given char is vowel
	 * @param c - char that should be checked
	 * @return true if it's vowel and false otherwise
	 */
	bool isVowel(char c);

	/**
	 * Prints current path to opened file
	 * @param path - string which represents path to file
	 */
	void print_path(const std::string& path);

}

#pragma once

#include "libraries.h"

/**
 * Prints out main menu and handles user's choice of entry items.
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

	/**
	 * Structure used in this seminar to receive sums with indices of elements
	 * @field sum - Sum of elements
	 * @field quantity - Quantity of elements
	 * @field indices - Pointer to array of indices of elements
	 */
	template<typename T>
	struct Result
	{
		T sum;
		int quantity;
		int* indices;
	};

	/**
	 * Entry point for Seminar 3, prints out start UI and handles initialization.
	 */
	void entry();

	/**
	 * Function that prints out seminar options and handles user's input.
	 * @tparam T - Type of data which be used for arrays (int or double).
	 */
	template<typename T>
	void menu();

	/**
	 * Creates an array with given size
	 * @param array_size - size of an array
	 * @return pointer to a created array
	 * @tparam T - Type of data which be used for arrays (int or double).
	 */
	template<typename T>
	T* create_array(int array_size);

	/**
	 * Prints out an array.
	 * @param array - an array to print.
	 * @param array_size - size of given array.
	 * @tparam T - Type of data which be used for arrays (int or double).
	 */
	template<typename T>
	void print_array(const T* array, int array_size);

	/**
	 * Finds a sum of odd elements of given array.
	 * @param array - an array which sum should be found.
	 * @param array_size - size of given array.
	 * @return an sum of elements.
	 * @tparam T - Type of data which be used for arrays (int or double).
	 */
	template<typename T>
	Result<T> sum_of_odd_elements(const T* array, int array_size);

	/**
	 * Finds a sum of elements between first and last negative elements.
	 * @param array - an array which sum should be found.
	 * @param array_size - size of given array.
	 * @return an sum of elements.
	 * @tparam T - Type of data which be used for arrays (int or double).
	 */
	template<typename T>
	Result<T> sum_of_elements_between_first_and_last_negatives(const T* array, int array_size);

	/**
	 * Shrinks an array by removing
	 * @param array
	 * @param array_size
	 * @return pointer to shrunk array
	 * @tparam T - Type of data which be used for arrays (int or double).
	 */
	template<typename T>
	T* shrink_array(const T* array, int array_size);
}

/**
 * Namespace for functions related to seminar 4.
 */
namespace seminar4
{

	/**
 	* Structure used in this seminar to receive quantity of elements in matrix with indices of rows
 	* @field quantity_of_elements - Quantity of elements
 	* @field quantity_of_rows - Quantity of rows
 	* @field indices - Pointer to array of indices of rows
 	*/
	struct Result
	{
		int* quantity_of_elements;
		int quantity_of_rows;
		int* indices;
	};

	/**
	 * Entry point for Seminar 4, prints out start UI and handles initialization.
	 */
	void entry();

	/**
	 * Function that prints out seminar options and handles user's input.
	 * @tparam T - Type of data which be used for arrays (int or double).
	 */
	template<typename T>
	void menu();

	/**
	 * Creates a matrix with given size
	 * @param matrix - an array to fill.
	 * @param matrix_size - size of given array.
	 */
	template<typename T>
	T** create_matrix(int matrix_size);

	/**
	 * Prints out a matrix.
	 * @param matrix - a matrix to print.
	 * @param matrix_size - size of given matrix.
	 */
	template<typename T>
	void print_matrix(T** matrix, int matrix_size);

	/**
	 * Finds quantity of elements in rows which does not contain negative
	 * @param matrix - a matrix of elements
	 * @param matrix_size - size of given matrix
	 * @return quantity of elements
	 */
	template<typename T>
	Result quantity_of_elements_in_rows_without_negative(T** matrix, int matrix_size);

	/**
	 * Finds max sum of elements between diagonals parallel to main
	 * @param matrix - a matrix of elements
	 * @param matrix_size - size of given matrix
	 * @return max sum between diagonals parallel to main
	 */
	template<typename T>
	int find_max_sum_in_diagonals(T** matrix, int matrix_size);
}

/**
 * Namespace for functions related to seminar 5.
 */
namespace seminar5
{

	/**
 	* Prints out entry for second task and handles user's choice.
 	*/
	void menu();

	/**
	 * Reads file from specified path and returns string with words starts with vowels
	 * @param file - stream of file
	 * @return string read from file
	 */
	std::string read_string(std::basic_fstream<char>& file);

	/**
	 * Checks if given char is vowel
	 * @param c - char that should be checked
	 * @return true if it's vowel and false otherwise
	 */
	bool is_vowel(char c);

	/**
	 * Prints current path to opened file
	 * @param path - string which represents path to file
	 */
	void print_path(const std::string& path);

}

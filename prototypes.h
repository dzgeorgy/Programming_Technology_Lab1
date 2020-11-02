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
 * Namespace for functions related to task 1.
 */
namespace task1
{

	/**
	 * Prints out menu for first task and handles user's choice.
	 */
	void menu();

	/**
	 * Lets user to fill an array.
	 * @param array - an array to fill.
	 * @param array_size - size of given array.
	 */
	void fill_array(int* array, int array_size);

	/**
	 * Prints out an array.
	 * @param array - an array to print.
	 * @param array_size - size of given array.
	 */
	void print_array(const int* array, int array_size);

	/**
	 * Finds a sum of odd elements of given array.
	 * @param array - an array which sum should be found.
	 * @param array_size - size of given array.
	 * @return an sum of elements.
	 */
	int sum_of_odd_elements(const int* array, int array_size);

	/**
	 * Finds a sum of elements between first and last negative elements.
	 * @param array - an array which sum should be found.
	 * @param array_size - size of given array.
	 * @return an sum of elements.
	 */
	int sum_of_elements_between_first_and_last_negatives(const int* array, int array_size);
}

/**
 * Namespace for functions related to task 2.
 */
namespace task2
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
	 *
	 * @param matrix - a matrix of elements
	 * @param matrix_size - size of given matrix
	 * @return max sum between diagonals parallel to main
	 */
	int find_max_sum_in_diagonals(int** matrix, int matrix_size);
}

/**
 * Namespace for functions related to task 3.
 */
namespace task3
{

	/**
 	* Prints out menu for second task and handles user's choice.
 	*/
	void menu();

	std::string read_string(const std::string& path);

	bool isVowel(char c);

}

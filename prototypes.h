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
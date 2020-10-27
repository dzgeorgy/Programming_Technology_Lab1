#pragma once

#include "libraries.h"

/**
 * Prints out main menu and handles user's choice of menu items
 * @return True if application should continue work and false otherwise.
 */
bool main_menu();

/**
 * Tries to read integer value from console, throws an exception if not succeed
 * @return Integer value
 * @throws std::invalid_argument
 */
int read_int()
{
	char buffer[10];
	std::scanf("%s", buffer);
	return std::stoi(buffer, nullptr, 10);
}
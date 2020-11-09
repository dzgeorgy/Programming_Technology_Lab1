#include "prototypes.h"

void seminar3::menu()
{
	clear_screen();
	print_header("Main >> Seminar 3");
	printf("Please enter an array size:\n");
	auto array_size = read_int();
	auto* array = new int[array_size];
	fill_array(array, array_size);
	while (true)
	{
		clear_screen();
		print_header("Main >> Seminar 3");
		print_array(array, array_size);
		printf("Choose an option:\n"
			   "1: Find a sum of odd elements\n"
			   "2: Find a sum of elements between first and last negative ones\n"
			   "3: Back\n");
		try
		{
			switch (read_int())
			{
			case 1:
			{
				clear_screen();
				print_header("Main >> Seminar 3");
				print_array(array, array_size);
				try
				{
					int sum = sum_of_odd_elements(array, array_size);
					printf("Sum of odd elements is %d\n", sum);
				}
				catch (const std::range_error& exception)
				{
					printf("Sum can't be found! Reason: %s", exception.what());
				}
				await_input();
				break;
			}
			case 2:
			{
				clear_screen();
				print_header("Main >> Seminar 3");
				print_array(array, array_size);
				try
				{
					int sum_x = sum_of_elements_between_first_and_last_negatives(array, array_size);
					printf("Sum of elements between first and last negatives is %d\n", sum_x);
				}
				catch (const std::range_error& exception)
				{
					printf("Sum can't be found! Reason: %s", exception.what());
				}
				await_input();
				break;
			}
			case 3:
				return;
			default:
				throw std::invalid_argument("");
			}
		}
		catch (const std::invalid_argument& exception)
		{
			printf("You entered incorrect value! Please try again.\n");
			await_input();
		}
	}
}

void seminar3::fill_array(int* array, int array_size)
{
	printf("Please fill an array:\n");
	for (int i = 0; i < array_size; i++)
		array[i] = read_int();
}

void seminar3::print_array(const int* array, int array_size)
{
	printf("Current array is: [ ");
	for (int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	printf("]\n===================================================================\n");
}

int seminar3::sum_of_odd_elements(const int* array, int array_size)
{
	auto sum = 0;
	for (int i = 0; i < array_size; i += 2)
		sum += array[i];
	if (array_size < 4)
		throw std::range_error("Not enough elements in array!\n");
	return sum;
}

int seminar3::sum_of_elements_between_first_and_last_negatives(const int* array, int array_size)
{
	auto first_negative_index = -1;
	auto last_negative_index = -1;
	auto sum = 0;
	for (int i = 0; i < ceil(array_size / 2.0); i++)
	{
		if (first_negative_index == -1 && array[i] < 0) first_negative_index = i;
		if (last_negative_index == -1 && array[array_size - 1 - i] < 0) last_negative_index = array_size - 1 - i;
	}
	if (array_size == 1)
		throw std::range_error("There's only one element in array!\n");
	else if (first_negative_index == -1 && last_negative_index == -1)
		throw std::range_error("There's no negative elements!\n");
	else if (first_negative_index == -1 || last_negative_index == -1)
		throw std::range_error("There's only one negative element!\n");
	else if (std::abs(first_negative_index - last_negative_index) == 1)
		throw std::range_error("There's no elements between first and last negatives!\n");
	else if (first_negative_index < last_negative_index)
	{
		for (int i = first_negative_index + 1; i < last_negative_index; i++)
			sum += array[i];
	}
	return sum;
}
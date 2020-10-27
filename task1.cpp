#include "prototypes.h"

void task1::menu()
{
	while (true)
	{
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
				printf("Please enter array size: ");
				auto array_size = read_int();
				auto* array = new int[array_size];
				fill_array(array, array_size);
				int sum = sum_of_odd_elements(array, array_size);
				printf("Sum of odd elements is %d\n", sum);
				break;
			}
			case 2:
			{
				printf("Please enter array size: ");
				auto array_size = read_int();
				auto* array = new int[array_size];
				fill_array(array, array_size);
				int sum_x = sum_of_elements_between_first_and_last_negatives(array, array_size);
				printf("Second sum is %d\n", sum_x);
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
			printf("You entered incorrect value! Please try again.\n\n\n");
		}
	}
}

void task1::fill_array(int* array, int array_size)
{
	printf("Please fill an array: ");
	for (int i = 0; i < array_size; i++)
		array[i] = read_int();
}

void task1::print_array(const int* array, int array_size)
{
	for (int i = 0; i < array_size; i++)
		printf("%d\t", array[i]);
}

int task1::sum_of_odd_elements(const int* array, int array_size)
{
	auto sum = 0;
	for (int i = 0; i < array_size; i += 2)
		sum += array[i];
	return sum;
}

int task1::sum_of_elements_between_first_and_last_negatives(const int* array, int array_size)
{
	auto first_negative_index = -1;
	auto last_negative_index = -1;
	auto sum = 0;
	for (int i = 0; i < ceil(array_size / 2.0); i++)
	{
		if (first_negative_index == -1 && array[i] < 0) first_negative_index = i;
		if (last_negative_index == -1 && array[array_size - 1 - i] < 0) last_negative_index = array_size - 1 - i;
	}
	if (first_negative_index < last_negative_index && first_negative_index != -1)
	{
		for (int i = first_negative_index + 1; i < last_negative_index; i++)
			sum += array[i];
	}
	printf("First: %d; Last: %d\n", first_negative_index, last_negative_index);
	return sum;
}
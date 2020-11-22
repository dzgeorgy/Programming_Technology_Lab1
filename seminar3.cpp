#include "prototypes.h"

void seminar3::menu()
{
	print_header("Main >> Seminar 3");
	printf("Please enter an array size:\n");
	auto array_size = read_int();
	double* array = create_array(array_size);
	while (true)
	{
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
				print_header("Main >> Seminar 3");
				print_array(array, array_size);
				try
				{
					auto result = sum_of_odd_elements(array, array_size);
					printf("Sum of odd elements is %f\n"
						   "Their indices are [ ", result.sum);
					for (auto i = 0; i < result.quantity; i++)
						printf("%d ", result.indices[i]);
					printf("]\n");
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
				print_header("Main >> Seminar 3");
				print_array(array, array_size);
				try
				{
					auto result = sum_of_elements_between_first_and_last_negatives(array, array_size);
					printf("Sum of elements between first and last negatives is %f\n"
						   "Their indices are [ ", result.sum);
					for (int i = 0; i < result.quantity; i++)
						printf("%d ", result.indices[i]);
					printf("]\n");
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

double* seminar3::create_array(int array_size)
{
	auto* array = new double[array_size];
	printf("Please fill an array:\n");
	for (int i = 0; i < array_size; i++)
		array[i] = read_double();
	return array;
}

void seminar3::print_array(const double* array, int array_size)
{
	printf("Current array is: [ ");
	for (int i = 0; i < array_size; i++)
		printf("%f ", array[i]);
	printf("]\n===================================================================\n");
}

seminar3::Result seminar3::sum_of_odd_elements(const double* array, int array_size)
{
	if (array_size < 4)
		throw std::range_error("Not enough elements in array!\n");
	auto sum{ 0.0 };
	auto quantity{ array_size / 2 };
	auto* indices = new int[quantity];
	for (int i = 1; i < array_size; i += 2)
	{
		sum += array[i];
		indices[i / 2] = i;
	}
	return { sum, quantity, indices };
}

seminar3::Result seminar3::sum_of_elements_between_first_and_last_negatives(const double* array, int array_size)
{
	if (array_size == 1)
		throw std::range_error("There's only one element in array!\n");
	auto first_negative_index{ -1 };
	auto last_negative_index{ -1 };
	auto sum{ 0.0 };
	auto quantity{ 0 };
	auto* indices = new int[quantity];
	for (int i = 0; i < ceil(array_size / 2.0); i++)
	{
		if (first_negative_index == -1 && array[i] < 0) first_negative_index = i;
		if (last_negative_index == -1 && array[array_size - 1 - i] < 0) last_negative_index = array_size - 1 - i;
	}
	if (first_negative_index == -1 && last_negative_index == -1)
		throw std::range_error("There's no negative elements!\n");
	else if (first_negative_index == -1 || last_negative_index == -1)
		throw std::range_error("There's only one negative element!\n");
	else if (std::abs(first_negative_index - last_negative_index) == 1)
		throw std::range_error("There's no elements between first and last negatives!\n");
	else if (first_negative_index < last_negative_index)
	{
		quantity = last_negative_index - first_negative_index - 1;
		for (int i = first_negative_index + 1; i < last_negative_index; i++)
		{
			sum += array[i];
			indices[i - first_negative_index - 1] = i;
		}
	}
	else
		throw std::range_error("Unknown exception!");
	return { sum, quantity, indices };
}
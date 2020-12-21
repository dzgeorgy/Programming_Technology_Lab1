#include "../headers/prototypes.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
void seminar3::entry()
{
	print_header("Main >> Seminar 3");
	printf("Options available in this seminar:\n"
		   "- Find a sum of odd elements\n"
		   "- Find a sum of elements between first and last negative ones\n"
		   "- Shrink an array by removing all elements whose modules are less or equal 1\n"
		   "===================================================================\n");
	printf("Please choose a type of data:\n"
		   "1: Integers\n"
		   "2: Real numbers\n");
	int data_type = read_int();
	switch (data_type)
	{
	case 1:
		menu<int>();
		break;
	case 2:
		menu<double>();
		break;
	default:
		printf("You entered incorrect value!\n");
		await_input();
		return;
	}
}

template<typename T>
void seminar3::menu()
{
	printf("===================================================================\n"
		   "Please enter an array size:\n");
	int array_size;
	do
	{
		array_size = read_int();
		if (array_size < 1)
			printf("Array size must be greater or equal than one. Please enter another value...\n");
	} while (array_size < 1);
	auto array = create_array<T>(array_size);
	while (true)
	{
		print_header("Main >> Seminar 3");
		print_array(array, array_size);
		printf("Choose an option:\n"
			   "1: Find a sum of odd elements\n"
			   "2: Find a sum of elements between first and last negative ones\n"
			   "3: Shrink an array by removing all elements whose modules are less or equal 1\n"
			   "4: Exit\n");
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
					Result<T> result = sum_of_odd_elements(array, array_size);
					printf("Sum of odd elements is ");
					if (typeid(T) == typeid(int))
						printf("%d\n", result.sum);
					else if (typeid(T) == typeid(double))
						printf("%f\n", result.sum);
					printf("Their indices are [ ");
					for (auto i{ 0 }; i < result.quantity; ++i)
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
					Result<T> result = sum_of_elements_between_first_and_last_negatives(array, array_size);
					printf("Sum of elements between first and last negatives is ");
					if (typeid(T) == typeid(int))
						printf("%d\n", result.sum);
					else if (typeid(T) == typeid(double))
						printf("%f\n", result.sum);
					printf("Their indices are [ ");
					for (auto i{ 0 }; i < result.quantity; ++i)
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
			{
				print_header("Main >> Seminar 3");
				print_array(array, array_size);
				try
				{
					auto shrunk_array = shrink_array(array, array_size);
					printf("Shrunk array is:\n");
					print_array(shrunk_array, array_size);
					delete[] shrunk_array;
				}
				catch (const std::range_error& exception)
				{
					printf("Can't shrink an array! Reason: %s", exception.what());
				}
				await_input();
				break;
			}
			case 4:
			{
				delete[] array;
				return;
			}
			default:
				throw std::invalid_argument("You entered incorrect value! Please try again...\n");
			}
		}
		catch (const std::invalid_argument& exception)
		{
			printf("%s", exception.what());
			await_input();
		}
	}
}

template<typename T>
T* seminar3::create_array(int array_size)
{
	auto* array = new T[array_size];
	printf("===================================================================\n"
		   "Please fill an array:\n");
	for (int i = 0; i < array_size; ++i)
		if (typeid(T) == typeid(int))
			array[i] = read_int();
		else if (typeid(T) == typeid(double))
			array[i] = read_double();
		else throw std::invalid_argument("Template function received unsupported type!");
	return array;
}

template<typename T>
void seminar3::print_array(const T* array, int array_size)
{
	printf("Array is: [ ");
	for (int i = 0; i < array_size; i++)
		if (typeid(T) == typeid(int))
			printf("%d ", array[i]);
		else if (typeid(T) == typeid(double))
			printf("%f ", array[i]);
		else throw std::invalid_argument("Template function received unsupported type!");
	printf("]\n===================================================================\n");
}

template<typename T>
seminar3::Result<T> seminar3::sum_of_odd_elements(const T* array, int array_size)
{
	if (array_size < 4)
		throw std::range_error("Not enough elements in array!\n");
	T sum{ 0 };
	auto quantity{ array_size / 2 };
	auto* indices = new int[quantity];
	for (int i = 1; i < array_size; i += 2)
	{
		sum += array[i];
		indices[i / 2] = i;
	}
	return { sum, quantity, indices };
}

template<typename T>
seminar3::Result<T> seminar3::sum_of_elements_between_first_and_last_negatives(const T* array, int array_size)
{
	if (array_size == 1)
		throw std::range_error("There's only one element in array!\n");
	auto first_negative_index{ -1 };
	auto last_negative_index{ -1 };
	T sum{ 0 };
	auto quantity{ 0 };
	auto* indices = new int[quantity];
	for (int i = 0; i < std::ceil(array_size / 2.0); i++)
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
	else if (std::abs(first_negative_index - last_negative_index) == 2)
		throw std::range_error("There's only one element between first and last negatives!\n");
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

template<typename T>
T* seminar3::shrink_array(const T* array, int array_size)
{
	auto* shrunk_array = new T[array_size]{ 0 };
	auto counter{ 0 };
	for (int i = 0; i < array_size; i++)
	{
		if (abs(array[i]) <= 1)
		{
			shrunk_array[counter] = array[i];
			counter++;
		}
	}
	return shrunk_array;
}
#pragma clang diagnostic pop
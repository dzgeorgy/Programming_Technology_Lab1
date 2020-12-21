#include "../headers/prototypes.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
void seminar4::entry()
{
	print_header("Main >> Seminar 4");
	printf("Options available in this seminar:\n"
		   "- Find quantity of elements in rows without negative elements\n"
		   "- Find max sum of elements of diagonals which are parallel to main\n"
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
void seminar4::menu()
{
	printf("===================================================================\n"
		   "Please enter a matrix size:\n");
	int matrix_size;
	do
	{
		matrix_size = read_int();
		if (matrix_size < 2)
			printf("Matrix size must be greater or equal than two. Please enter another value...\n");
	} while (matrix_size < 2);
	auto matrix = create_matrix<T>(matrix_size);
	while (true)
	{
		print_header("Main >> Seminar 4");
		print_matrix(matrix, matrix_size);
		printf("Choose an option:\n"
			   "1: Find quantity of elements in rows without negative elements\n"
			   "2: Find max sum of elements of diagonals which are parallel to main\n"
			   "3: Back\n");
		try
		{
			switch (read_int())
			{
			case 1:
			{
				print_header("Main >> Seminar 4");
				print_matrix(matrix, matrix_size);
				auto result = quantity_of_elements_in_rows_without_negative(matrix, matrix_size);
				printf("Quantity of elements are:\n");
				for (int i = 0; i < result.quantity_of_rows; i++)
				{
					printf("Row: %d, Quantity: %d\n", result.indices[i], result.quantity_of_elements[i]);
				}
				await_input();
				break;
			}
			case 2:
			{
				auto sum = find_max_sum_in_diagonals(matrix, matrix_size);
				clear_screen();
				print_header("Main >> Seminar 4");
				print_matrix(matrix, matrix_size);
				printf("Max sum of elements is %d\n", sum);
				await_input();
				break;
			}
			case 3:
				for (int i = 0; i < matrix_size; i++)
					delete matrix[i];
				delete[] matrix;
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

template<typename T>
T** seminar4::create_matrix(int matrix_size)
{
	auto** matrix = new T* [matrix_size];
	for (int i = 0; i < matrix_size; i++)
		matrix[i] = new T[matrix_size];
	printf("Please fill the matrix with size %d: ", matrix_size);
	for (int i = 0; i < matrix_size; i++)
		for (int j = 0; j < matrix_size; j++)
			if (typeid(T) == typeid(int))
				matrix[i][j] = read_int();
			else if (typeid(T) == typeid(double))
				matrix[i][j] = read_double();
			else throw std::invalid_argument("Template function received unsupported type!");

	return matrix;
}

template<typename T>
void seminar4::print_matrix(T** matrix, int matrix_size)
{
	printf("Current matrix is:\n");
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
			if (typeid(T) == typeid(int))
				printf("%4d ", matrix[i][j]);
			else if (typeid(T) == typeid(double))
				printf("%4f ", matrix[i][j]);
			else throw std::invalid_argument("Template function received unsupported type!");
		printf("\n");
	}
	printf("\n===================================================================\n");
}

template<typename T>
seminar4::Result seminar4::quantity_of_elements_in_rows_without_negative(T** matrix, int matrix_size)
{
	auto* quantity_of_elements = new int[matrix_size]{ 0 };
	auto quantity_of_rows{ 0 };
	auto* rows_indices = new int[matrix_size]{ 0 };
	for (int i = 0; i < matrix_size; i++)
	{
		bool contain_negative = false;
		for (int j = 0; j < matrix_size; j++)
			if (matrix[i][j] < 0)
			{
				contain_negative = true;
				break;
			}
		if (contain_negative) continue;
		rows_indices[quantity_of_rows] = i;
		quantity_of_elements[quantity_of_rows] = matrix_size;
		quantity_of_rows++;
	}
	return { quantity_of_elements, quantity_of_rows, rows_indices };
}

template<typename T>
int seminar4::find_max_sum_in_diagonals(T** matrix, int matrix_size)
{
	int max = matrix[0][matrix_size - 1];
	for (int k = -matrix_size + 1; k < matrix_size; ++k)
	{
		int sum = 0;
		for (int i = std::max(0, k), j = std::max(-k, 0); j < std::min(matrix_size, matrix_size - k); i++, j++)
			sum += matrix[i][j];
		if (max < sum) max = sum;
	}
	return max;
}
#pragma clang diagnostic pop
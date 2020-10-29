#include "prototypes.h"

void task2::menu()
{
	while (true)
	{
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
				printf("Please enter square matrix size: ");
				auto matrix_size = read_int();
				auto** matrix = new int* [matrix_size];
				for (int i = 0; i < matrix_size; i++)
					matrix[i] = new int[matrix_size];
				fill_matrix(matrix, matrix_size);
				print_matrix(matrix, matrix_size);
				quantity_of_elements_in_rows_without_negative(matrix, matrix_size);
				break;
			}
			case 2:
				break;
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

void task2::fill_matrix(int** matrix, int matrix_size)
{
	printf("Please fill the matrix with size %d: ", matrix_size);
	for (int i = 0; i < matrix_size; i++)
		for (int j = 0; j < matrix_size; j++)
			matrix[i][j] = read_int();
}

void task2::print_matrix(int** matrix, int matrix_size)
{
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
			printf("%d", matrix[i][j]);
		printf("\n");
	}
}

int* task2::quantity_of_elements_in_rows_without_negative(int** matrix, int matrix_size)
{
	auto* result = new int[matrix_size]{ 0 };
	for (int i = 0; i < matrix_size; i++)
		for (int j = 0; j < matrix_size; j++)
			if (matrix[i][j] < 0) result[i] = -100;
			else result[i]++;

	for (int i = 0; i < matrix_size; ++i)
	{
		printf("%d\t", result[i]);
	}
	return result;
}

int task2::find_max_sum_in_diagonals(int** matrix, int matrix_size)
{

}
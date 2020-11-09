#include "prototypes.h"

void seminar4::menu()
{
	clear_screen();
	print_header("Main >> Seminar 4");
	printf("Please enter square matrix size:\n");
	auto matrix_size = read_int();
	auto** matrix = new int* [matrix_size];
	for (int i = 0; i < matrix_size; i++)
		matrix[i] = new int[matrix_size];
	fill_matrix(matrix, matrix_size);
	while (true)
	{
		clear_screen();
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
				auto quantity = quantity_of_elements_in_rows_without_negative(matrix, matrix_size);
				clear_screen();
				print_header("Main >> Seminar 4");
				print_matrix(matrix, matrix_size);
				printf("Quantity of elements is %d\n", quantity);
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

void seminar4::fill_matrix(int** matrix, int matrix_size)
{
	printf("Please fill the matrix with size %d: ", matrix_size);
	for (int i = 0; i < matrix_size; i++)
		for (int j = 0; j < matrix_size; j++)
			matrix[i][j] = read_int();
}

void seminar4::print_matrix(int** matrix, int matrix_size)
{
	printf("Current matrix is:\n");
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	printf("\n===================================================================\n");
}

int* seminar4::quantity_of_elements_in_rows_without_negative(int** matrix, int matrix_size)
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

int seminar4::find_max_sum_in_diagonals(int** matrix, int matrix_size)
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
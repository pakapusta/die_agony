#include "aux.h"

int grid[NR_GRID_ROWS][NR_GRID_COLUMNS] = {
    {57,33,132,268,492,732},
    {81,123,240,443,353,508},
    {186,42,195,704,452,228},
    {-7,2,357,452,317,395},
    {5,23,-4,592,445,620},
    {0,77,32,403,337,452}};

int ones[NR_GRID_ROWS][NR_GRID_COLUMNS] = {
	{1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1}};

int array_to_pointer[NR_GRID_ROWS][NR_GRID_COLUMNS] = {
	{0, 1, 2, 3, 4, 5},
	{6, 7, 8, 9, 10, 11},
	{12, 13, 14, 15, 16, 17},
	{18, 19, 20, 21, 22, 23},
	{24, 25, 26, 27, 28, 29},
	{30, 31, 32, 33, 34, 35}};

void print_grid(int array[NR_GRID_ROWS][NR_GRID_COLUMNS])
{
	printf("[");
	for(int i = 0; i < NR_GRID_ROWS; i++)
	{
		printf("[");
		for (int j = 0; j < NR_GRID_COLUMNS; j++)
		{
			if (j < NR_GRID_COLUMNS - 1) 
			{
				printf("%d, ", array[i][j]);
			}
			else
			{
				printf("%d", array[i][j]);
			}

		}
		if (i < NR_GRID_ROWS - 1)
		{
			printf("],\n ");
		}
		else
		{
			printf("]");
		}
	}
	printf("]\n");
}

void print_used(int *array)
{
	printf("[");
	for(int i = 0; i < NR_GRID_ROWS; i++)
	{
		printf("[");
		for (int j = 0; j < NR_GRID_COLUMNS; j++)
		{
			if (j < NR_GRID_COLUMNS - 1) 
			{
				printf("%d, ", array[array_to_pointer[i][j]]);
			}
			else
			{
				printf("%d", array[array_to_pointer[i][j]]);
			}

		}
		if (i < NR_GRID_ROWS - 1)
		{
			printf("], \n");
		}
		else
		{
			printf("]");
		}
	}
	printf("]\n");
}

int *copy_ones(int ones[NR_GRID_ROWS][NR_GRID_COLUMNS])
{
	int *temp = malloc(sizeof(int) * NR_GRID_ROWS * NR_GRID_COLUMNS);
	if (!temp)
	{
		printf("Copying of ones array failed. Aborting.\n");
		exit(1);
	}
	memcpy(temp, ones, sizeof(int) * NR_GRID_ROWS * NR_GRID_COLUMNS);
	return temp;
}

int *copy_used(int *used)
{
	int *temp = malloc(sizeof(int) * NR_GRID_ROWS * NR_GRID_COLUMNS);
	if (!temp)
	{
		printf("Copying of used array failed. Aborting.\n");
		exit(1);
	}
	memcpy(temp, used, sizeof(int) * NR_GRID_ROWS * NR_GRID_COLUMNS);
	return temp;
}

int sum_grid_used(int array[NR_GRID_ROWS][NR_GRID_COLUMNS], int *used)
{
	int sum = 0;
	for(int i = 0; i < NR_GRID_ROWS; i++)
	{
		for (int j = 0; j < NR_GRID_COLUMNS; j++)
		{
			sum += (array[i][j] * used[array_to_pointer[i][j]]);
		}
	}
	return sum;
}

void print_solution(Solution *solution)
{
	printf("Solution is %d.\n", sum_grid_used(grid, solution->used));
	printf("Dice is ");
	print_die(solution->dice);
	printf("Path is ");
	print_path(solution->path);
}


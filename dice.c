#include "dice.h"

// bottom, front, left, right, back, top
static const int u[6] = {5, 1, 3, 4, 6, 2};
static const int d[6] = {2, 6, 3, 4, 1, 5};
static const int l[6] = {3, 2, 6, 1, 5, 4};
static const int r[6] = {4, 2, 1, 6, 5, 3};


void print_die(Die *die)
{
	
	printf("[");
	for (int i = 0; i < 6; i++)
	{
		if (i < 5 ) {
			printf("%f, ", (*die)[i]);
		}
		else {
			printf("%f", (*die)[i]);
		}
	}
	printf("]");
	printf("\n");
		
}


Die *roll(Die *die, int i, int j)
{

	Die *temp = malloc(sizeof(Die));

	if (i == -1 && j == 0) 
	{
		for (int i = 0; i < 6; i++)
		{
			(*temp)[i] = (*die)[u[i] - 1];
		}
	}
	if (i == 1 && j == 0) 
	{
		for (int i = 0; i < 6; i++)
		{
			(*temp)[i] = (*die)[d[i] - 1];
		}
	}
	if (i == 0 && j == 1) 
	{
		for (int i = 0; i < 6; i++)
		{
			(*temp)[i] = (*die)[l[i] - 1];
		}
	}
	if (i == 0 && j == -1) 
	{
		for (int i = 0; i < 6; i++)
		{
			(*temp)[i] = (*die)[r[i] - 1];
		}
	}

	return temp;
}


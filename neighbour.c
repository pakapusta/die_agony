#include "neighbour.h"


static Cell directions[4] = {
	{-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

Cell *add_cells(Cell *a, Cell *b, Cell *result)
{
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	return result;
}

bool init_neighbours(Neighbours *n, size_t init_size)
{
	n->cell_list = malloc(init_size * sizeof(Cell));
	if (!n->cell_list) return false;
	n->used = 0;
	n->size = init_size;
	return true;
}

bool insert_to_neighbours(Neighbours *n, Cell cell)
{
	if (n->used == n->size)
	{
		n->size = n->size * 2;
		n->cell_list = realloc(n->cell_list, n->size * sizeof(Cell));
		if (!n->cell_list) return false;
	}
	n->cell_list[n->used++] = cell;
	return true;
}

void free_neighbours(Neighbours *n)
{
	free(n->cell_list);
	n->cell_list = NULL;
	n->used = n->size = 0;
}

Neighbours *find_neighbours(Neighbours *n, Cell *cell, int N)
{
	Cell *temp = malloc(sizeof(Cell));
	if (!temp)
	{
		printf("Allocation of temp variable in find_neighbours failed\n");
		exit(1);
	}
	for (int i = 0; i < 4; i++)
	{
		add_cells(cell, &directions[i], temp);
		if (temp->x >= 0 && temp->x < N && temp->y >= 0 && temp->y < N)
		{
		        int state = insert_to_neighbours(n, *temp);	
			if (!state)
			{
				printf("Adding to neighbours failed\n");
				exit(1);
			}
		}

	}

	free(temp);
	return n;
}

void print_neighbours(Neighbours *n)
{
	
	printf("[");
	for (int i = 0; i < n->used; i++)
	{
		if (i < n->used -1 ) {
			printf("{%d, %d}, ", n->cell_list[i].x, n->cell_list[i].y);
		} 
		else {
			printf("{%d, %d}", n->cell_list[i].x, n->cell_list[i].y);
		}

	}
	printf("]");
	printf("\n");
		
}

#include "path.h"

bool init_path(Path *p, size_t init_size)
{
	p->cells = malloc(init_size * sizeof(int));
	if (!p->cells) false;
	p->used = 0;
	p->size = init_size;
	return true;
}

bool insert_to_path(Path *p, int cell)
{
	if (p->used == p->size)
	{
		p->size = p->size * 2;
		p->cells = realloc(p->cells, p->size * sizeof(int));
		if (!p->cells) return false;
	}
	p->cells[p->used++] = cell;
	return true;
}


void free_path(Path *p)
{
	free(p->cells);
	p->cells = NULL;
	p->used = p->size = 0;
}

void print_path(Path *p)
{
	
	printf("[");
	for (int i = 0; i < p->used; i++)
	{
		if (i < p->used -1 ) {
			printf("%d, ", p->cells[i]);
		} 
		else {
			printf("%d", p->cells[i]);
		}

	}
	printf("]");
	printf("\n");
		
}

Path *copy_path(Path *p)
{
	Path *new_path = malloc(sizeof(Path));
	if (!new_path) {
		printf("Allocation of path failed\n");
		exit(1);
	}
	int state = init_path(new_path, p->size);
	if (!state) {
		printf("Initialization of path failed\n");
		exit(1);
	}

	for (int i = 0; i < p->used; i++)
	{
		new_path->cells[i] = p->cells[i];
	}
	
	new_path->used = p->used;
	new_path->size = p->size;

	return new_path;
}

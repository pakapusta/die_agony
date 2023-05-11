#ifndef NEIGHBOURS_H
#define NEIGHBOURS_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int x;
	int y;
} Cell;


typedef struct {
	Cell *cell_list;
	size_t used;
	size_t size;
} Neighbours;

Cell *add_cells(Cell *, Cell *, Cell *);
bool init_neighbours(Neighbours *, size_t);
bool insert_to_neighbours(Neighbours *, Cell);
void free_neighbours(Neighbours *);
Neighbours *find_neighbours(Neighbours *, Cell *, int);
void print_neighbours(Neighbours *);

#endif

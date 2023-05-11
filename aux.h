#ifndef AUX_H
#define AUX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dice.h"
#include "path.h"

#define NR_GRID_ROWS 6
#define NR_GRID_COLUMNS 6

typedef struct {
	int *used;
	Die *dice;
	Path *path;
} Solution;

extern int grid[NR_GRID_ROWS][NR_GRID_COLUMNS]; 
extern int ones[NR_GRID_ROWS][NR_GRID_COLUMNS]; 
extern int array_to_pointer[NR_GRID_ROWS][NR_GRID_COLUMNS];

void print_grid(int array[NR_GRID_ROWS][NR_GRID_COLUMNS]);
void print_used(int *);
int *copy_ones(int ones[NR_GRID_ROWS][NR_GRID_COLUMNS]);
int *copy_used(int *);
int sum_grid_used(int array[NR_GRID_ROWS][NR_GRID_COLUMNS], int *);
void print_solution(Solution *);

#endif

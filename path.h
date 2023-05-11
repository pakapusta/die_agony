#ifndef PATHS_H
#define PATHS_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	int *cells;
	size_t used;
	size_t size;
} Path;


bool init_path(Path *, size_t);
bool insert_to_path(Path *, int);
void free_path(Path *);
void print_path(Path *);
Path *copy_path(Path *);

#endif

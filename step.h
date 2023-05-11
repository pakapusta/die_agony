#include <stdlib.h>
#include <stdbool.h>
#include "dice.h"
#include "path.h"

typedef struct {
	Die *dice;
	int *used;
	Path *path;
	int x;
	int y;
	int counter;
} Step;

struct steps {
	Step *step;
	struct steps *next;
};

struct steps *new_step(Step *s);
void free_steps(struct steps *);
bool steps_push(struct steps **, Step*);
Step *steps_pop(struct steps **);
void print_step(Step *s);


#include <assert.h>
#include "dice.h"
#include "path.h"
#include "aux.h"
#include "step.h"

struct steps *new_step(Step *s)
{
	struct steps *new_step = malloc(sizeof(struct steps));
	if (!new_step) return 0;
	new_step->step = malloc(sizeof(Step));
	new_step->step->dice = s->dice;
	new_step->step->used = s->used;
	new_step->step->path = s->path;
	new_step->step->x = s->x;
	new_step->step->y = s->y;
	new_step->step->counter = s->counter;
	new_step->next = NULL;
	return new_step;
}

void free_steps(struct steps *stack)
{
	while(stack) {
		struct steps *next = stack->next;
		free(stack);
		stack = next;
	}
}


bool steps_push(struct steps **stack, Step *s)
{
	struct steps *step = new_step(s);
	if (!step) return false;
	step->next = *stack;
	*stack = step;
	return true;
}

Step *steps_pop(struct steps **stack)
{
	assert(*stack != NULL);
	struct steps *top = *stack;
	*stack = (*stack)->next;
	Step *top_step = top->step;
	free(top);
	return top_step;
}

void print_step(Step *s)
{
	printf("---------------------------------------------------------------------\n");
	printf("Die: ");
	print_die(s->dice);
	printf("Used: \n");
	print_used(s->used);
	printf("Path: ");
	print_path(s->path);
	printf("x: %d, y: %d, counter: %d\n", s->x, s->y, s->counter);
	printf("---------------------------------------------------------------------\n");
}


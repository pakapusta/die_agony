#include <time.h>

#include "neighbour.h"
#include "step.h"
#include "aux.h"

int main(int argc, char **argv)
{
	clock_t start_time, end_time;
	start_time = clock();

	struct steps *stack = NULL;

	Die *die = malloc(sizeof(Die));
	for (int i = 0; i < 6; i++) (*die)[i] = 0;

	Path *p = malloc(sizeof(Path));
	if (!p) {
		printf("Allocation of path failed\n");
		exit(1);
	}
	int state = init_path(p, 1);
	if (!state) {
		printf("Initialization of path failed\n");
		exit(1);
	}

	state = insert_to_path(p, 0);
	if (!state) {
		printf("Inserting to path failed\n");
		exit(1);
	}
	

	Neighbours *n = malloc(sizeof(Neighbours));
	if (!n) {
		printf("Allocation of neighbours failed\n");
		exit(1);
	}

	 Step first = { die, copy_ones(ones), p, 5, 0, 0};
	 steps_push(&stack, &first);

	 Die *dice, *new_dice;
	 int *used, *new_used;
	 float test;
	 Path *path, *new_path;
	 int x, y, a, b, counter;
	 Step *step;
	 Solution *solution = malloc(sizeof(Solution));

	 while (stack)
	 {
		step = steps_pop(&stack);

		dice = step->dice;
		used = step->used;
		path = step->path;
		x = step->x;
		y = step->y;
		counter = step->counter;

		if (x == 0 && y == 5)
		{
			solution->used = used;
			solution->dice = dice;
			solution->path = path;
			
			print_solution(solution);

			free(solution->used);
			free(solution->dice);
			free_path(solution->path);
			free(solution->path);
			free(step);
		}
		else
	       	{
			state = init_neighbours(n, 1);
			if (!state) {
				printf("Initialization of neighbours failed\n");
				exit(1);
			}
			Cell cell = {x, y};
			find_neighbours(n, &cell, 6);

			for (int i = 0; i < n->used; i++)
			{
				a = n->cell_list[i].x;
				b = n->cell_list[i].y;
				new_dice = roll(dice, a - x, b - y);
				new_used = copy_used(used);
				if ((*new_dice)[5] == 0.0f)
				{
					test = (float)((grid[a][b] - (path->cells)[path->used -1])) / (float)(counter + 1);
					if (test != 0.0f)
					{
						(*new_dice)[5] = test;
						new_used[array_to_pointer[a][b]] = 0;


						new_path = copy_path(path);

						state = insert_to_path(new_path, grid[a][b]);
						if (!state) {
							printf("Inserting to path failed\n");
							exit(1);
						}
	 					Step next = { new_dice, new_used, new_path, a, b, counter + 1};

						steps_push(&stack, &next);
					}
				}
				else if ((*new_dice)[5] == (float)((grid[a][b] - (path->cells)[path->used -1])) / (float)(counter + 1))
				{
					new_used[array_to_pointer[a][b]] = 0;

					new_path = copy_path(path);

					state = insert_to_path(new_path, grid[a][b]);
					if (!state) {
						printf("Inserting to path failed\n");
						exit(1);
					}

	 				Step next = { new_dice, new_used, new_path, a, b, counter + 1};

					steps_push(&stack, &next);
				}
				else 
				{
					free(new_dice);
					free(new_used);
				}
			}

			free(n->cell_list);
			free_path(path);
			free(path);
			free(used);
			free(dice);
			free(step);
		}
	 }

 	 free(solution);
	 free(n);
	 free(stack);

	 end_time = clock();
         double time_taken = ((double)(end_time - start_time))/CLOCKS_PER_SEC;
         printf("The solution took %f miliseconds to execute.\n", time_taken*1000);

	 return 0;
}


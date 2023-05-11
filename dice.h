#ifndef DICE_H
#define DICE_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef	float Die[6];

void print_die(Die *);
Die *roll(Die *, int, int);

#endif

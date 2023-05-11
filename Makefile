CC = cc
CFLAGS = -Wall

all: solution

debug: CFLAGS += -g
debug: solution

files := solution.c dice.c path.c neighbour.c dice.h path.h neighbour.h step.c step.h aux.h
solution: $(files)
	$(CC) $(CFLAGS) -o solution solution.c dice.c neighbour.c path.c step.c aux.c


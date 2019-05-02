#include "prio_q.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct prio_q *queue;
	char *s;
	int i;

	queue = prio_q_create();

	prio_q_push(queue, "amet...", 2);
	prio_q_push(queue, "ipsum", 7);
	prio_q_push(queue, "dolor", 4);
	prio_q_push(queue, "Lorem", 22);
	prio_q_push(queue, "sit", 3);

	prio_q_push(queue, "Hello World", 1);
	prio_q_push(queue, "Bye World", 0);

	for (i = 0; i < 5; i++) {
		s = prio_q_pop(queue);
		printf("%s\n", s);
	}

	s = prio_q_front(queue);
	printf("%s\n", s);

	/* should print:
	   Lorem
	   Ipsum
	   dolor
	   sit
	   amet...
	*/

	prio_q_destroy(queue);
	// use: valgrind ./stack
	// to check if your free function works correctly

	return 0;
}

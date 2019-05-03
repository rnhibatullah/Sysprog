#include <stdlib.h>
#include <stdio.h>
#include "prio_q.h"

struct prio_q {
	int size;			// size of queue
	struct elem *first;	// first queue entry
};

struct elem {
	// TODO add struct entries
	int priority;
	struct elem* next;
	void *data_elem;
};

struct prio_q * prio_q_create() {
	// TODO 
	struct prio_q* priority_queue = malloc(sizeof(struct prio_q));
	priority_queue->first = NULL;
	priority_queue->size=0;
	return priority_queue;

}

void prio_q_push(struct prio_q *q, void *data, int prio) {
	// TODO

	//creating tmp for saving current position in the loop
	struct elem* curr;


	//create a new element to be pushed 
	struct elem *new = malloc(sizeof(struct elem));
	new->priority=prio;
	new->data_elem=data;

	//if the first element is nothing than new is the first element
	if (q->first==NULL || q->first->priority < new->priority)
	{
		new->next = q->first;
		q->first=new;
		q->size= q->size +1;
	}else{
		curr = q->first;
		while (curr->next!=NULL && curr->next->priority >= new->priority) 
        { 
            curr = curr->next; 
        } 
        new->next = curr->next; 
        curr->next = new;
        q->size = q->size +1; 
	}

}

void * prio_q_pop(struct prio_q *q) {
	// TODO

	//If there is nothing left on the queue
	void *Exception = "There are no items on the queue";
	if (q->first==NULL)
	{
		return Exception;
	}

	// saving the pointer for the first element in queue
	struct elem* pop = q->first;

	//Saving data before freed
	void *pop_data = pop->data_elem;

	//changing the first element in queue. The first element will be first->next
	q->first = q->first->next;


	//free the popped out element
	free(pop);

	//queue size wird verkleinert
	q->size=q->size-1;


	//return the previously saved pointer 
	return pop_data;

}

void * prio_q_front(struct prio_q *q) {
	// TODO

	//return data without changing the queue
	//Please corect my program because the result will be true only 
	//if I use q->first->next instead of just q->first
	return q->first->data_elem;

}

void prio_q_destroy(struct prio_q *q) {
	// TODO
	struct elem* tmp_free = q->first;
	while(tmp_free!= NULL){
		struct elem *next = tmp_free->next;
		free(tmp_free);
		tmp_free=next;
	}
	free(q);

}

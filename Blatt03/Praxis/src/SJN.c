#include "SJN.h"
#include "../include/task.h"
#include "../include/Queue.h"
#include <stdlib.h>
#include <stdio.h>

int init_SJN()
{
    // TODO
    /*def_task* task = malloc(sizeof(task));
    def_task.id = 0;
    def_task.length = 0;

    q_elem* queue = (q_elem*) malloc(sizeof(q_elem));
    q_elem->task = task;
    q_elem->next = NULL;

    if(def_task.id = 0 && def_task.length = 0)*/

	//Initialisiere Queue
    //queue_new(*a, *b);


    //Queue* queue_new(int (*comparator)(const void *a, const void *b))
	//{
	/*int (*comparator)(const void *a, const void *b);
	Queue *queue = (Queue*) malloc(sizeof(Queue));
	if (!queue)
	{
		printf("Could not allocate memory for priority queue.\n");
		exit(1);
	}
	if (comparator == NULL)
	{
		printf("queue_new: No comparator given...\n");
		exit(1);
	}
	else
	{
		queue->comparator = comparator;
	}*/
	static Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue->size = 0;
	queue->head = NULL;

	if(!queue){
		return 1;
	}
	//succes
	else{
		return 0;
	}
		//return queue;
	//}	
	//initialisiere task
	//ich glaube ich brauche das nicht, weil task statisch in den Funktionsköpfen alloziert wird
	/*def_task* task = (def_task*) malloc(sizeof(task));
    def_task->id = 0;
    def_task->length = 0;*/


	
}

void free_SJN()
{
    // TODO
    //queue_free(*queue);

    //void queue_free(Queue *queue)
	//{
	q_elem *current = queue->head;
	q_elem *toDelete;
	while (current != NULL)
	{
		toDelete = current;
		current = current->next;
		free(toDelete->task);
		free(toDelete);
	}
	free(queue);
	//}
}

void arrive_SJN(int id, int length)
{
    // TODO
	//queue_offer(queue, task);

		//Neues Element wird ans Ende der Queue eingefügt
		q_elem* newElem = (q_elem*) malloc(sizeof(q_elem));
		if (!newElem)
		{
			printf("Could not allocate memory for queue element.");
			exit(1);
		}

		def_task* task;
		newElem->task = task;
		task->length = length;
		task->id = id;

		q_elem *current;
		q_elem *last = NULL;
		for (current = queue->head; current != NULL; current = current->next)
		{
			last = current;
		}
		newElem->next = current;
		if (last != NULL) {
		    last->next = newElem;
		} else {
		    queue->head = newElem;
		}
		queue->size++;

		//sortiere Queue nach Priorität(task->length)
		q_elem* shortest_job;
		shortest_job = queue->head;
		for (current = queue->head; current != NULL; current = current->next){

			if(current->task->length <= shortest_job->task->length){

				if(current->task->length < current->next->task->length){
					shortest_job = current;
				}
				else{
					shortest_job = current->next;
				}
			}
		}
		static def_task* shortest_task = shortest_job->task;
		return shortest_task;

		//if(queue->comparator(current->task, newElem->task) = 0){

		//return task;
	

}

def_task *tick_SJN()
{
    // TODO
	
	static int remaining_runtime = shortest_task->length;

	if (queue->size == 0){

		return NULL;
	}
	else{

		def_task* running_task = shortest_task;
		return running_task;
	}
	

	

		
	/*for(int remaining_runtime = queue->head->task->length; remaining_runtime > 1; remaining_runtime--){

			finish_task_SJN(*queue, remaining_runtime);
		}*/
	//if()

	/*for(remaining_runtime = queue->head->task->length; remaining_runtime > 1; remaining_runtime--){

		return queue->head->task;
	}

	if(remaining_runtime = 1){

	q_elem *newHead = queue->head->next;
	def_task* task = queue->head->task;
	free(queue->head);
	queue->head = newHead;
	queue->size--;
	return task;
	}

    //return NULL;
}

void finish_task_SJN(Queue *queue, int remaining_runtime)
{
    // TODO optional
    return queue->head->task;
}

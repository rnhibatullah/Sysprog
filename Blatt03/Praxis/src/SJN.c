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
		int (*comparator)(const void *a, const void *b);
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
		}
		queue->size = 0;
		queue->head = NULL;

		//return queue;
	//}	
	//initialisiere task
	//ich glaube ich brauche das nicht, weil task statisch in den Funktionsköpfen alloziert wird
	/*def_task* task = (def_task*) malloc(sizeof(task));
    def_task->id = 0;
    def_task->length = 0;*/


	if(!queue){
		return 1;
	}
	//succes
	else{
		return 0;
	}
}

void free_SJN()
{
    // TODO
    //queue_free(*queue);

    /*void queue_free(Queue *queue)
	{
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
	}*/
}

void arrive_SJN(int id, int length)
{
    // TODO
	//queue_offer(*queue, *task);

		void* queue_offer(Queue *queue, def_task *task)
	{
		//Neues Element wird in Queue eingefügt
		q_elem* newElem = (q_elem*) malloc(sizeof(q_elem));
		if (!newElem)
		{
			printf("Could not allocate memory for queue element.");
			exit(1);
		}

		newElem->task = task;

		q_elem *current;
		q_elem *last = NULL;
		for (current = queue->head; current != NULL; current = current->next)
		{
			if (queue->comparator(current->task, newElem->task) > 0)
			{
				break;
			}
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
		q_elem *shortest_job;
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
		task = shortest_job->task;
		//if(queue->comparator(current->task, newElem->task) = 0){

		return task;
	}

}

def_task *tick_SJN()
{
    // TODO

    return NULL;
}

void finish_task_SJN()
{
    // TODO optional
}

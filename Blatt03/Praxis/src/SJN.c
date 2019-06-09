#include "SJN.h"
#include "../include/task.h"
#include "../include/Queue.h"
#include <stdlib.h>
#include <stdio.h>

	//definieren der Globalen Variablen

typedef struct own_Queue
{
    int size;
    q_elem *head;
}own_Queue;

	
static int remaining_runtime;

static def_task* shortest_task;
	
static own_Queue* queue;
	

int init_SJN()
{
    // TODO
	shortest_task->length = 0;
	shortest_task->id = 0;

	queue = (own_Queue*) malloc(sizeof(own_Queue));
	queue->size = 0;
	queue->head = NULL;

	remaining_runtime = 0;

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
		newElem->next = NULL;

		//Wenn Queue leer ist und kein anderer Task ausgeführt wird, wird der neue Task ausgeführt
		if(queue->size == 0 && remaining_runtime == 0){

				running_task = newElem->task;
				shortest_task = newElem->task;
				remaining_runtime = newElem->task->length;
				return;
			}
		
		//Wenn Queue leer ist aber anderer Task ausgeführt wird, wird der neue Task in die Queue zum Warten geschickt
		else if(queue->size == 0 && remaining_runtime != 0){

			queue->head = newElem;
			newElem->next = NULL;
			queue->size++;
			return;
		}
		
		//Falls Queue nicht leer ist
		else if(queue->size != 0){
			//Neues Element wird ans Ende der Queue eingefügt
			q_elem* current;
			q_elem* last = NULL;
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
			shortest_task = shortest_job->task;
		}	
		

		//if(queue->comparator(current->task, newElem->task) = 0){

		//return task;
	

}

def_task *tick_SJN()
{
    // TODO
	
	remaining_runtime = shortest_task->length;

	if (queue->size == 0 && remaining_runtime == 0){

		running_task = NULL;
		return NULL;
	}

	if (queue->size != 0 && remaining_runtime == 0){

		running_task = shortest_task;
		remaining_runtime = shortest_task->length;
		return running_task;
	}

	else if(remaining_runtime > 0){

		/*def_task* running_task = shortest_task;
		return running_task;*/
		remaining_runtime--;
		return running_task;
	}
}

void finish_task_SJN(Queue *queue, int remaining_runtime)
{
    // TODO optional
    //return queue->head->task;
}

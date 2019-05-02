struct prio_q;

/**
 * Allocates and initializes priority queue.
 * Returns pointer to priority queue.
 */
struct prio_q * prio_q_create();

/**
 * Pushes data to queue with given priority
 * 	q: Pointer to initialized priority queue.
 * 	data: Pointer added to queue.
 * 	prio: Priority of the data being pushed. Higher value equals higher priority.
 * Returns nothing.
 */
void prio_q_push(struct prio_q *q, void *data, int prio);

/**
 * Returns and extracts the element with highest priotrity.
 * 	q: Pointer to initialized priority queue.
 * Returns the data pointer with the highest priority.
 */
void * prio_q_pop(struct prio_q *q);

/**
 * Returns the element with the highest priority. Does not change the queue.
 * 	q: Pointer to initialized priority queue.
 * Returns the data pointer with the highest priority.
 */
void * prio_q_front(struct prio_q *q);

/**
 * Destroys the queue and all the allocated data.
 *  q: Pointer to inititalized priority queue.
 * Returns nothing
 */
void prio_q_destroy(struct prio_q *q);

#include "queue.h"

int main(void) {

	// 2 7 3 NULL
	Queue* queue1 = createQueue("Damn the Queue");
	insertItem(queue1, 2);
	insertItem(queue1, 7);
	insertItem(queue1, 3);

	displayQueue(queue1);
	Queue* queue2 = copyQueue(queue1);
	editQueueName(queue2, "Shake that queue");
	displayQueue(queue2);
	printf("oE\n");
	Queue* mergedQueue = mergeQueues(queue1,queue2,"Merged Queue");
	displayQueue(mergedQueue);
	clearQueue(mergedQueue);
	displayQueue(mergedQueue);

	return 1;
}
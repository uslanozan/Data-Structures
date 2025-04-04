#include "queue.h"
//-----------------------------------------------------------------------------
Queue* createQueue(char name[]) {
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	if (newQueue == NULL) {
		printf("Memory allocation failure while creating Queue\n");
		return NULL;
	}

	if (strlen(name) >= sizeof(newQueue->queueName)) {
		printf("Queue name cannot be longer than %lu\n", sizeof(newQueue->queueName) - 1);
		free(newQueue);
		return NULL;
	}


	newQueue->length = 0;
	newQueue->head = NULL;
	newQueue->tail = NULL;

	strncpy(newQueue->queueName, name, sizeof(newQueue->queueName) - 1);
	newQueue->queueName[sizeof(newQueue->queueName) - 1] = '\0';


	return newQueue;
}

//-----------------------------------------------------------------------------
QueueNode* createQueueNode(int value) {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) {
		printf("Memory allocation failure while creating Node\n");
		return NULL;
	}

	newNode->value = value;
	return newNode;
}

/*
	[10] ->[20] ->[30]->NULL
	head             tail
*/
//tail.next her zaman NULL olacak ve FIFO
void insertItem(Queue* queue, int item) {
	if (isQueueNULL(queue))
	{
		printf("Queue is NULL!");
		return;
	}

	QueueNode* newNode = createQueueNode(item);

	if (isQueueEmpty(queue)) {
		queue->head = newNode;
		queue->tail = newNode;
	}
	else
	{
		queue->tail->next = newNode;
		queue->tail = newNode;
	}
	queue->length++;
}

//-----------------------------------------------------------------------------
bool isQueueNULL(Queue* queue) {
	if (queue == NULL)
	{
		return true;
	}
	return false;
}
//-----------------------------------------------------------------------------
bool isQueueEmpty(Queue* queue) {
	if (queue->length == 0)
	{
		return true;
	}
	return false;
}
//-----------------------------------------------------------------------------
void deleteFirstItem(Queue* queue) {

	if (isQueueNULL(queue))
	{
		printf("Queue is NULL!");
		return;
	}

	if (isQueueEmpty(queue))
	{
		printf("Queue is empty!");
		return;
	}

	QueueNode* oldHead = queue->head;

	if (queue->length == 1) {
		queue->head = NULL;
		queue->tail = NULL;
	}
	else {
		queue->head = queue->head->next;
	}

	free(oldHead);
	queue->length--;
}
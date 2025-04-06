#include "queue.h"
//-----------------------------------------------------------------------------
Queue* createQueue(char name[]) {
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	if (newQueue == NULL) {
		printf("Memory allocation failure while creating Queue\n");
		return NULL;
	}

	if (strlen(name) >= sizeof(newQueue->queueName)) {
		printf("Queue name cannot be longer than %lu\n",(int) (sizeof(newQueue->queueName) - 1));
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
	newNode->next = NULL;
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
	oldHead = NULL;
	queue->length--;
}
//-----------------------------------------------------------------------------
void displayQueue(Queue* queue) {

	if (isQueueEmpty(queue))
	{
		printf("Queue is empty!\n");
	}

	if (isQueueNULL(queue))
	{
		printf("Queue is NULL!\n");
	}

	QueueNode* iterator = queue->head;
	int index = 1;
	
	while (iterator != NULL) {
		printf("%d. item is %d in %s\n", index, iterator->value, queue->queueName);
		iterator = iterator->next;
		index++;
	}
}
//-----------------------------------------------------------------------------
int peekFront(Queue* queue) {
	return queue->head->value;
}
//-----------------------------------------------------------------------------
int peekRear(Queue* queue) {
	return queue->tail->value;
}
//-----------------------------------------------------------------------------
bool checkItem(Queue* queue, int item) {
	if (isQueueNULL(queue))
	{
		printf("Queue is NULL\n");
		return false;
	}

	if (isQueueEmpty(queue))
	{
		printf("Queue is empty\n");
		return false;
	}

	QueueNode* iterator = queue->head;

	while (iterator != NULL) {
		if (iterator->value == item)
		{
			return true;
		}
		iterator = iterator->next;
	}
	return false;
}
//-----------------------------------------------------------------------------
int getQueueLength(Queue* queue) {
	if (isQueueNULL(queue))
	{
		printf("Queue is NULL\n");
		return -1;
	}
	return queue->length;
}
//-----------------------------------------------------------------------------
Queue* copyQueue(Queue* original) {
	if (isQueueNULL(original))
	{
		printf("Original queue is NULL\n");
		return NULL;
	}
	Queue* newQueue = createQueue(original->queueName);

	if (isQueueEmpty(original))
	{
		return newQueue;
	}

	QueueNode* iterator = original->head;

	while (iterator != NULL) {
		insertItem(newQueue, iterator->value);
		iterator = iterator->next;
	}

	return newQueue;
}

//-----------------------------------------------------------------------------
void editQueueName(Queue* queue, char newName[]) {
	if (strlen(newName) >= sizeof(queue->queueName))
	{
		printf("New queue name cannot be longer than %lu\n", (int)(sizeof(queue->queueName) - 1));
		return;
	}
	else
	{
		strncpy(queue->queueName, newName, sizeof(queue->queueName) - 1);
		printf("Queue name is updated\n");
	}
}
//-----------------------------------------------------------------------------
Queue* mergeQueues(Queue* q1, Queue* q2, char name[]) {
	if (isQueueNULL(q1) || isQueueNULL(q2))
	{
		printf("One of the queue is NULL\n");
		return NULL;
	}

	Queue* mergedQueue = createQueue(name);

	if (isQueueEmpty(q1) && isQueueEmpty(q2))
	{
		printf("Both queue is empty \n");
		return mergedQueue;
	}

	QueueNode* iterator = q1->head;
	
	while (iterator != NULL) {
		insertItem(mergedQueue, iterator->value);
		iterator = iterator->next;
	}

	iterator = q2->head;

	while (iterator != NULL) {
		insertItem(mergedQueue, iterator->value);
		iterator = iterator->next;
	}

	return mergedQueue;
}
//-----------------------------------------------------------------------------
//TODO: SOR BURAYI
void clearQueue(Queue** queue) {
	if (isQueueNULL(*queue)) {
		printf("Queue is already NULL\n");
		return;
	}

	QueueNode* iterator = (*queue)->head;
	QueueNode* temp;

	while (iterator != NULL) {
		temp = iterator;
		iterator = iterator->next;
		free(temp);
	}

	free(*queue);
	*queue = NULL;
}
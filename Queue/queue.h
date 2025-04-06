#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define QUEUE_NAME 51

typedef struct QueueNode QueueNode;
typedef struct Queue Queue;

struct QueueNode {
	int value;
	QueueNode* next;
};

struct Queue {
	char queueName[QUEUE_NAME];
	int length;
	QueueNode* tail;
	QueueNode* head;
};

//todo BURAYI SOR
/*
typedef struct {
	char queueName[QUEUE_NAME];
	int length;
	QueueNode* tail;
	QueueNode* head;
}Queue;

typedef struct {
	int value;
	QueueNode* next;
}QueueNode;
*/

void displayQueue(Queue* queue);
Queue* createQueue(char name[]);
QueueNode* createQueueNode(int value);
void insertItem(Queue* queue, int item);
bool isQueueNULL(Queue* queue);
bool isQueueEmpty(Queue* queue);
void deleteFirstItem(Queue* queue);
int peekFront(Queue* queue);
int peekRear(Queue* queue);
void clearQueue(Queue** queue);
bool checkItem(Queue* queue, int item);
int getQueueLength(Queue* queue);
Queue* copyQueue(Queue* original);
void editQueueName(Queue* queue, char newName[]);
Queue* mergeQueues(Queue* q1, Queue* q2, char name[]);



#endif
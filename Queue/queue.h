#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define QUEUE_NAME 51

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

Queue* createQueue(char name[]);
QueueNode* createQueueNode(int value);
void insertItem(Queue* queue, int item);
bool isQueueNULL(Queue* queue);
bool isQueueEmpty(Queue* queue);
void deleteFirstItem(Queue* queue);

#endif
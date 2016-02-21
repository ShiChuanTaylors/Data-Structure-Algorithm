#include <stdio.h>

typedef struct Element
{
	int key;
	/*possible other fields*/
}Element;

typedef struct QueueNode
{
	Element elem;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* first;
	QueueNode* last;
	int size;
}Queue;

Queue* createEmptyQueue(); 			//create empty queue
void addToQueue(Queue* q, Element e);	//adds e to the end of the queue
Element removeFromQueue(Queue* q);		//removes element at beginning and returns it
int isQueueEmpty(Queue* q);			//tells whether the queue q is empty or not
int queueSize (Queue* q);		//returns how many elements are inside the queue
void printQueue(Queue* q);

void main()
{
	Queue* myQueue = createEmptyQueue();
	int i;
	Element e;
	for(i = 0; i < 100; i+=10)
	{
		e.key = i;
		addToQueue(myQueue, e);	
	}
	
	
	/*
	e.key = 88;
	addToQueue(myQueue, e);
	
	e.key = 110;
	addToQueue(myQueue, e);
	
	e.key = 210;
	addToQueue(myQueue, e);
	
	e.key = 4110;
	addToQueue(myQueue, e);
	*/
	printQueue(myQueue);
	
	while(!isQueueEmpty(myQueue))
	{
		printf("Key of element at queue front is %d\n", removeFromQueue(myQueue).key);
		//printQueue(myQueue);
	}
		
		
		
	free(myQueue);
	
}

Queue* createEmptyQueue()
{
	Queue* myQueue = (Queue*)malloc(sizeof(Queue));
	myQueue->first = NULL;
	myQueue->last = NULL;
	myQueue->size = 0;
	
	return myQueue;
}

void addToQueue(Queue* q, Element e)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->elem = e;
	newNode->next = NULL;
	
	if(isQueueEmpty(q))
	{
		q->first = newNode;
		q->last = newNode;
	}
	else
	{
		q->last->next = newNode;
		q->last = q->last->next;
	}
	
	(q->size)++;
}

Element removeFromQueue(Queue* q)
{
	Element e = q->first->elem;
	
	QueueNode* deleteNode = q->first;
	if(q->first->next != NULL)
		q->first = q->first->next;
	
	free(deleteNode);
	
	(q->size)--;
	return e;
}

int isQueueEmpty(Queue* q)
{
	if(queueSize(q) == 0)
		return 1;
	else
		return 0;
}

int queueSize (Queue* q)
{
	return (q->size);
}

void printQueue(Queue* q)
{
	printf("\n==Current Queue==\n");
	int i;
	QueueNode* cur = q->first;
	printf("  Start\n");
	printf("    |    \n");
	printf("    v    \n");
	for(i = 0; i < q->size; i++)
	{
		printf("________\n");
		printf("|    \t|\n");
		printf("|  %d\t|\n",cur->elem);
		printf("|\t|\n");
		printf("_________\n");
		printf("|\t|\n");
		printf("____|____\n");
		printf("    |    \n");
		printf("    v    \n");
		if(cur->next != NULL)
			cur = cur->next;
	}
	
	printf("    __\n");
	printf("    |x|\n");
	printf("    __\n");
	
}

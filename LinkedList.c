/* Data Structure and Algorithm - Linked List
 * Created by Ting Shi Chuan, Software Engineering Student
 * Taylor's University
 */

#include <stdio.h>

typedef struct ListNode
{
	float data;
	struct ListNode *next;
}ListNode;

typedef struct LinkedList 
{
	ListNode *first;
	int size;
}LinkedList;

LinkedList* createEmptyLinkedList();
void insertAtBeginning (LinkedList* list, float x);
void insertAt (LinkedList* list, int position, float x);
float getElementAt (LinkedList* list, int position);
void printAll (LinkedList* list);
void deleteElementAt (LinkedList* list, int position);
void clearAndFree (LinkedList* list);

int main()
{
	LinkedList* list = createEmptyLinkedList();
	insertAtBeginning (list, 3.3);
	
	insertAtBeginning (list, 9.2);
	
	insertAtBeginning (list, 4.0);
	
	insertAt (list, 1, 15.6);
	
	printAll (list);
	
	deleteElementAt (list, 2);
	
	printAll (list);
	
	clearAndFree (list);
}

LinkedList* createEmptyLinkedList()
{
	LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));
	head->first = NULL;
	head->size = 0;
	
	return head;
}

void insertAtBeginning (LinkedList* list, float x)
{
	ListNode* first = (ListNode*)malloc(sizeof(ListNode));
	first->data = x;
	first->next = NULL;
	if(list->first != NULL)
	{
		first->next = list->first;
	}
	
	list->first = first;
	(list->size)++;
}

void insertAt (LinkedList* list, int position, float x)
{
	printf("\n\Insert elements\n");
	//printf("%d   %d     \n\n", list->size, position);
	
	if(position == 0)
	{
		insertAtBeginning(list, x);
		return;
	}
	
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	
	ListNode* cur = list->first;
	
	if(position > list->size)
	{
		printf("Position does not exist! \n");
		return;
	}
	
	
	int i;
	for(i = 1; i < position; i++)
	{
		cur = cur->next;
	}
	
	node->next = cur->next;
	cur->next = node;
	
	(list->size)++;
	
	
}

float getElementAt (LinkedList* list, int position)
{
	
	ListNode* cur = list->first;
	int i;
	if(position > list->size)
	{
		printf("Position does not exist! \n");
		exit(101);
	}
	
	for(i = 1; i < position; i++)
	{
		cur = cur->next;
	}
	
	return (cur->data);
}

void printAll (LinkedList* list)
{
	
	ListNode* cur = list->first;
	int i;
	int totalsize = list->size;
	
	for(i = 1; i <= totalsize; i++)
	{
		printf("%d element: %.2f\n", i, cur->data);
		if(cur->next != NULL)
			cur = cur->next;
	}
	
	
	
}

void deleteElementAt (LinkedList* list, int position)
{
	printf("\n\nDelete elements\n");
	ListNode* cur = list->first;
	ListNode* elementToDelete;
	if(position > list->size)
	{
		printf("Position does not exist! \n");
		exit(101);
	}
	
	if(position == 0)
	{
		elementToDelete = cur;
		list->first = cur->next;
		free(elementToDelete);
		(list->size)--;	
	}
	else
	{
		int i;
		for(i = 1; i < position; i++)
		{
			cur = cur->next;
		}
		
		elementToDelete = cur->next;
		cur->next = elementToDelete->next;
		
		free(elementToDelete);
		(list->size)--;	
	}
	
}

void clearAndFree (LinkedList* list)
{
	ListNode* cur = list->first;
	ListNode* elementToDelete;
	
	int i;
	for(i = 0; i < (list->size); i++)
	{
		elementToDelete = cur;
		cur = cur->next;
		free(elementToDelete);
	}
	
	free(list);
	
}

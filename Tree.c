#include <stdio.h>
#include<math.h>

#define MAX_SIZE 20
int count = 5;
int array[] = {4,5,7,8,9};

void addNode(int tree[], int p, int x);
void printTree(int tree[], int size);
int calcTotalElement(int tree[], int size);

int main()
{
	int tree[MAX_SIZE];
	int i = 0;
	
	for(i = 0; i < MAX_SIZE; i++)
	{
		tree[i] = 0;	
	}	
	
	addNode(tree, 1, 1);
	printTree(tree, MAX_SIZE);
}

void addNode(int tree[], int p, int x)
{
	if(p > MAX_SIZE)
		return;
	else
	{
		//Check if element matched with data
		int result = 0, i;
		for(i = 0; i < count; i++)
		{
			if(array[i] == x)
				result = 1;
		}
		if(result != 1)
			tree[p] = x;	//add to the array if not match
		else
			tree[p] = 0;
		
		//go to the left side	
		addNode(tree, 2*p, x*2);
		
		//go to the right side
		addNode(tree, 2*p+1, x*2+1);	
	}
}

void printTree(int tree[], int size)
{
	int total = calcTotalElement(tree, size);
	int i, j, space;
	int curNumberOfNode;
	int height = (int)log2((double)(total+1));
	printf("Total height: %d\n", height);
	
	int curElement = 1;
	for(i = 1; i <= height; i++)
	{	
	
		//Number of node at current height
		curNumberOfNode = (pow(2.0, i)-1) - (pow(2.0, i-1)-1);
		
		/*for(space = 0; space < (pow(2.0, height)/2 - (curNumberOfNode/2)); space++)
		{
			printf(" ");
		}*/
		for(j = 0; j < curNumberOfNode; j++)
		{	
			if(tree[curElement] != 0)
			{
				printf("%d ", tree[curElement]);	
			}
			else
			{
				printf("  ");
			}
			curElement++;
			/*
			for(space = 0; space < (pow(2.0, height) -  / (curNumberOfNode + curNumberOfNode-1)); space++)
			{
				printf(" ");
			}*/
		}
		printf("\n");	
	}
		
		
}

int calcTotalElement(int tree[], int size)
{
	//TOTAL Elements
	int i = 0, total = 0;
	for(i = 0; i < size; i++)
	{
		if(tree[i] != 0)
		{
			total++;
		}
	}
	return total;
}

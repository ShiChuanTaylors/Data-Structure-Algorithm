#include <stdio.h>
#define MAX_SIZE 10

void printArray(int data[], int size);
void quickSort(int arr[], int n);
void quickSortHelp(int a[], int s, int e);
int partition2(int arr[], int s, int e);

int main()
{
	int arr1[MAX_SIZE], arr2[MAX_SIZE];
	
	//Initialize Arrays
	int i;
	for(i = 0; i < MAX_SIZE; i++)
	{
		arr1[i] = arr2[i] = rand() % 1000; //fill values between 0 and 999	
	}
	
	printf("Arr1 before sorting:\n");
  	printArray(arr1, MAX_SIZE);
  	//timeBefore = time(NULL);
   	quickSort(arr1, MAX_SIZE);
   	//timeAfter = time(NULL);
   	//timeNeededInSeconds = timeAfter - timeBefore;
   	printf("Arr1 after sorting with quick sort:\n"); printArray(arr1, MAX_SIZE);
	
}


void printArray(int data[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("  %d  ", data[i]);
	}
}

void quickSort(int arr[], int n)
{
	quickSortHelp(arr, 0, n-1);	
}

void quickSortHelp(int a[], int s, int e)
{
	if(e > s)
	{
		int p = partition2(a, s, e);
		quickSortHelp(a, s, p-1);
		quickSortHelp(a, p+1, e);	
	}
}


/* In place partitioning */
int partition2(int arr[], int s, int e)
{
	int p = arr[s];
	int l = s+1, r = e;
	int temp;
	while(l < r)
	{
		while(arr[l] <= p)
		{
			l++;
		}
		while(arr[r] > p)
		{
			r--;
		}
		temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
		r--;
		l++;
	}
	arr[s] = arr[r];
	arr[r] = p;
	
	return r;
}

/*
/*Partition using temporary array //not recommended
int partition(int arr[], int n)
{
	int p = arr[0];
	int l = 0, r = n-1;
	
	//temporary array
	int* temp = (int*)malloc(n*sizeof(int));
	
	int i;
	for(i = 0; i<n; i++)
	{
		if(p>arr[i])
			b[l++] = arr[i];
		else
			b[r--] = arr[i];
	}
	b[r] = p;
	
	return r;
}*/

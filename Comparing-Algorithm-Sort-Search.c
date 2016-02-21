/* Data Structure and Algorithm - Sorting and Searching Algorithm
 * Created by Ting Shi Chuan, Software Engineering Student
 * Taylor's University
 */

#include <stdio.h>
#include <time.h>

void bubbleSort(int data[], int size);
void selectionSort(int data[], int size);
void printArray(int data[], int size);
int binarySearch(int data[], int size, int n);
int sequentialSearch(int data[], int size, int n);
	
#define MAX_SIZE 200000
void main () 
{
	int arr1[MAX_SIZE], arr2[MAX_SIZE];
	time_t timeBefore, timeAfter, timeNeededInSeconds;
	time_t t;
	
	srand((unsigned) time(&t));
	
	/* Sorting Algorithm Comparison */
	//Initialize Arrays
	int i;
	for(i = 0; i < MAX_SIZE; i++)
	{
		arr1[i] = arr2[i] = rand() % 1000; //fill values between 0 and 999	
	}
  	printf("Arr1 before sorting:\n");
  	//printArray(arr1, MAX_SIZE);
  	timeBefore = time(NULL);
   	bubbleSort(arr1, MAX_SIZE);
   	timeAfter = time(NULL);
   	timeNeededInSeconds = timeAfter - timeBefore;
   	//printf("Arr1 after sorting with bubble sort:\n"); printArray(arr1, MAX_SIZE);
   	printf("Time to sort using bubble sort was: %d seconds.\n\n", timeNeededInSeconds);
  	
  	printf("Arr2 before sorting:\n");
  	//printArray(arr2, MAX_SIZE);
  	timeBefore = time(NULL);
   	selectionSort(arr2, MAX_SIZE);
   	timeAfter = time(NULL);
   	timeNeededInSeconds = timeAfter - timeBefore;
   	//printf("Arr1 after sorting with selection sort:\n"); printArray(arr2, MAX_SIZE);
	printf("Time to sort using bubble sort was: %d seconds.\n\n", timeNeededInSeconds);
  	
	int n;
	printf("Enter a digit: ");
	scanf("%d", &n);
	
	/* Search Algorithm */
	/*Binary Search */
	int j;
	timeBefore = clock();
	int location;
	for(j = 0; j < 10000; j++)
	{
		location = binarySearch(arr1, MAX_SIZE, n);	
	}
	timeAfter = clock();
	if(location != -1)
	{
		printf("\n\nIt appeal! It's at the index of %d in the array..\n", location);
	}
	else
	{
		printf("\n\nNumber does not exist in the array\n");
	}
	timeNeededInSeconds = (timeAfter - timeBefore) / (CLOCKS_PER_SEC/1000);
	printf("Time to search using binary search: %d milliseconds.\n\n", timeNeededInSeconds);
	
	
	/* Normal Search */
	timeBefore = clock();
	int location2;
	for(j = 0; j < 10000; j++)
	{
		 location2= sequentialSearch(arr1, MAX_SIZE, n);	
	}
	timeAfter = clock();
	if(location2 != -1)
	{
		printf("\n\nIt appeal! It's at the index of %d in the array..\n", location);
	}
	else
	{
		printf("\n\nNumber does not exist in the array\n");
	}
	timeNeededInSeconds = (timeAfter - timeBefore) / (CLOCKS_PER_SEC/1000);
	printf("Time to search using normal search: %d milliseconds.\n\n", timeNeededInSeconds);
	
   	
  	system("pause");
  	
}


// Sort array of integers in ascending order using bubble sort algorithm
void bubbleSort(int data[], int size){
    int i, j;
	for(i = size; i > 0; i--)
	{
		for(j = 0; j < i - 1; j++)
		{
			if(data[j] > data[j + 1])
			{
				int temp = data[j+1];
				data[j+1] = data[j];
				data[j] = temp;
			}
		}
	}
}
// Sort array of integers in ascending order using selection sort algorithm
void selectionSort(int data[], int size){
    int i, j, curMin, temp;
	for(i = 0; i < size; i++)
	{
		curMin = i;
		for(j = i; j < size; j++)
		{
			if(data[j] < data[curMin])
			{
				curMin = j;
			}
		}
		temp = data[i];
		data[i] = data[curMin];
		data[curMin] = temp;
	}
}

void printArray(int data[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("  %d  ", data[i]);
	}
}

int binarySearch(int data[], int size, int n)
{
	int low = 0, high = size-1, mid;
	while(low >= high)
	{
		mid = (high + low)/2;
		
		if(n == data[mid])
		{
			return mid;
		}
		else if(n > data[mid])
		{
			low = mid + 1;
		}
		else if(n < data[mid])
		{
			high = mid - 1;
		}
		
		
	}
	return -1;
}

int sequentialSearch(int data[], int size, int n)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(n == data[i])
		{
			return i;
		}
	}
	
	return -1;
}

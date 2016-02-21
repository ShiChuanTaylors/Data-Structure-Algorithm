/*
FUNCTION MoveTower(disk, source, dest, spare):
IF disk == 0, THEN:
    move disk from source to dest
ELSE:
    MoveTower(disk - 1, source, spare, dest)   // Step 1 above
    move disk from source to dest              // Step 2 above
    MoveTower(disk - 1, spare, dest, source)   // Step 3 above
END IF
*/

#include <stdio.h>

int main()
{
	int n;
	printf("Enter the number of disks : ");
	scanf("%d",&n);
	printf("The Tower of Hanoi involves the moves :\n\n");
	MoveTower(n,'A','C','B');
	return 0;
}

void MoveTower(int disk, char source, char dest, char spare)
{
	
	if(disk == 0)
	{
		printf("Move disk %d from %c to %c\n", disk, source, dest);
		return;
	}
	
	MoveTower(disk-1, source, spare, dest);
	printf("Move disk %d from %c to %c\n", disk, source, dest);
	MoveTower(disk-1, spare, dest, source);
}

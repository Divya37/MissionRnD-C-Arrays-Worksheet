/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/


#include <stdio.h>
#include <malloc.h>

int* sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i, index = 0, x = 0, y;
	
	if (Arr == NULL || len < 0)
		return NULL;
	else
	{
		for (i = 0; i < len; i++)
		{
			if (Arr[i]>num)				
				break;
			else
				x++;
		}
		//Arr = (int *)realloc(Arr, len + 1);
		x = Arr[i];
		Arr[i] = num;
		for (i = i + 1; i < len + 1; i++)
		{
			y = Arr[i];
			Arr[i] = x;
			x = y;
		}
		return Arr;
	}	
}

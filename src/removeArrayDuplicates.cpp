#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	int i, j,k;
	if (Arr == NULL || len < 0)
		return NULL;
	else if (len == 1)
		return Arr;
	else
	{
		for (i = 0; i < len; i++)
		{
			for (j = i+1 ; j < len; j++)
			{
				if (Arr[i] == Arr[j])
				{
					for (k = j; k < len - 1; k++)
						Arr[k] = Arr[k + 1];
					len--;
					
				}
			}
		}		
	}
	return NULL;
}

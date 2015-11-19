#include <stdio.h>
#include<stdlib.h>

struct student {
	char name[10];
	int score;
};
int partition(struct student *students, int start, int end)
{
	int i, pivot = students[end].score, temp, pindex = start;

	for (i = start; i < end; i++)
	{
		if (students[i].score >= pivot)
		{
			temp = students[i].score;
			students[i].score = students[pindex].score;
			students[pindex].score = temp;
			pindex++;
		}
	}
	temp = students[pindex].score;
	students[pindex].score = students[end].score;
	students[end].score = temp;

	return pindex;
}
void sort(struct student *students, int start, int end)
{
	int pindex;
	if (start < end)
	{
		pindex = partition(students, start, end - 1);
		sort(students, start, pindex - 1);
		sort(students, pindex + 1, end);
	}
}
void * scoresDescendingSort(struct student *students, int len)
{
	int i;

	if (students == NULL || len < 0)
		 return NULL;
	if (len == 1)
		return students;
	else
	{
		sort(students, 0, len);
		return students;
	}
}
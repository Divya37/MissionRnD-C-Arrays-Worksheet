#include <malloc.h>
#include<stdio.h>

struct student
{
	char *name;
	int score;
};
struct student ** topKStudents(struct student *students, int len, int K) 
{
	int i, j, score_temp;
	char *name_temp;
	struct student **std;	
	name_temp = (char *)malloc(sizeof(char) * 5);	
	if (K > len)
		K = len;
	std = (struct student **)malloc(sizeof(struct student*)*K);

	if (students == NULL || len<0)
			return NULL;
	else
	{
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				if (students[i].score <= students[j].score)
				{
					score_temp = students[i].score;
					students[i].score = students[j].score;
					students[j].score = score_temp;

					name_temp = students[i].name;
					students[i].name = students[j].name;
					students[j].name = name_temp;

				}
			}
		}
		for (i = 0; i < K; i++)
			std[i]= &students[i];			
		return std;
	}

}

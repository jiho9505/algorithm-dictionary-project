#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char data[50];
	struct node*next;
}node;

void add(node**n, char*data);
int compare(node**n, char*data);
void del(node**n, char*data);
int main()
{
	node*dict = NULL;
	int i, j, k, cnt = 0;
	int isFind = 0;
	char str[256];
	char str2[256] = "";
	char buf[256];
	char buf2[256];

	printf("Enter dictionary words.\n");
	printf("%d %d",dict,&dict);
	while (cnt <= 100)
	{
		char d[50];
		scanf("%s", d);
		if (!strcmp(d, "eeennnddd"))
			break;
		add(&dict, d);
		cnt++;
	}
	while (1)
	{
		node*d = NULL;
		node*tmp = dict;
		add(&d, tmp->data);
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			add(&d, tmp->data);
		}
		strcpy(str2, "");
		printf("Input : ");
		scanf("%s", str);

		if (!strcmp(str, "eeennnddd"))
			break;

		for (i = 0; i < strlen(str); i++)
		{
			for (j = 0; j < 255; j++)
				buf2[j] = '0';
			buf2[j] = '\0';
			isFind = 0;
			for (k = i, j = 0; k < strlen(str); k++)
			{
				buf[j++] = str[k];
				buf[j] = '\0';

				if (compare(&d, buf))
				{
					if (strlen(buf) == strlen(str))
					{
						isFind = 1;
						strcpy(buf2, buf);
						break;
					}
					if (strlen(buf) < strlen(buf2))
						strcpy(buf2, buf);
					isFind = 1;
				}
			}
			if (isFind)
			{
				strcat(str2, buf2);
				strcat(str2, " ");
				i += strlen(buf2) - 1;
				del(&d, buf2);
			}
		}
		printf("Output: %s\n", str2);
	}
	return 0;
}
void del(node**n, char*data)
{
	node*tmp = *n;
	node*prev = *n;

	if (!strcmp(tmp->data, data))
	{
		*n = tmp->next;
		free(tmp);
		return 1;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (!strcmp(tmp->data, data))
		{
			prev->next = tmp->next;
			free(tmp);
			return;
		}
		prev = prev->next;
	}
}
int compare(node**n, char*data)
{
	node*tmp = *n;

	if (!strcmp(tmp->data, data))
		return 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (!strcmp(tmp->data, data))
			return 1;
	}
	return 0;
}
void add(node**n, char*data)
{
	node*N = (node*)malloc(sizeof(node));
	strcpy(N->data, data);
	N->next = NULL;

	if ((*n) == NULL)
		*n = N;
	else
	{
		node*tmp = *n;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = N;
	}
}

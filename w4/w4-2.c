#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

struct Node
{
	int data;
	struct Node *pre, *next;
};

void bubbleSort(struct Node **head)
{
    struct Node *temp_i = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp_j = (struct Node *)malloc(sizeof(struct Node));
    for(temp_i = (*head); temp_i != NULL; temp_i = temp_i -> next) {
        for(temp_j = temp_i -> next; temp_j != NULL; temp_j = temp_j -> next) {
            if(temp_i -> data > temp_j -> data) {
                int temp = temp_i -> data;
                temp_i -> data = temp_j -> data;
                temp_j -> data = temp;
            }
        }
    }
}

void selectionSort(struct Node **head)
{
    struct Node *temp_i = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp_j = (struct Node *)malloc(sizeof(struct Node));
    for(temp_i = (*head); temp_i != NULL; temp_i = temp_i -> next) {
        struct Node *curr = temp_i;
        for(temp_j = temp_i -> next; temp_j != NULL; temp_j = temp_j -> next) {
            if(temp_j -> data < curr -> data) {
                curr = temp_j;
            }
        }
        if(temp_i != curr) {
            int temp = temp_i -> data;
            temp_i -> data = curr -> data;
            curr -> data = temp;
        }
    }
}

int main()
{
	int j;
	struct Node *head, *buf, *cur;

	srand(time(NULL));

	head = NULL;
	for(j = 0;j < SIZE;j ++)
	{
		buf = (struct Node *)malloc(sizeof(struct Node));
		buf->data = rand();
		buf->next = head;
		buf->pre = NULL;
		if(head != NULL)
			head->pre = buf;
		head = buf;
	}

	cur = head;
	while(cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

	bubbleSort(&head);

	cur = head;
	while(cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

	head = NULL;
	for(j = 0;j < SIZE;j ++)
	{
		buf = (struct Node *)malloc(sizeof(struct Node));
		buf->data = rand();
		buf->next = head;
		buf->pre = NULL;
		if(head != NULL)
			head->pre = buf;
		head = buf;
	}

	cur = head;
	while(cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

	selectionSort(&head);

	cur = head;
	while(cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	return 0;
}

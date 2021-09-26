#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Queue
{
    // top means the head of the queue, bot means tail
	struct Node *top, *bot;
};

int enqueue(struct Queue *queue, int _data)
{
    struct Node *add_this_node = (struct Node *)malloc(sizeof(struct Node));
    add_this_node -> data = _data;
    add_this_node -> next = NULL;
    if(queue -> top == NULL && queue -> bot == NULL) {
        queue -> top = add_this_node;
        queue -> bot = add_this_node;
        return 1;
    }
    else {
        queue -> bot -> next = add_this_node;
        queue -> bot = add_this_node;
        return 1;
    }
    return 0;
}

int *dequeue(struct Queue *queue)
{
    if(queue -> top == NULL && queue -> bot == NULL) {
        return NULL;
    }
    if(queue -> top == queue -> bot) {
        int target = queue -> top -> data, *p;
        p = &target;
        queue -> top = NULL;
        queue -> bot = NULL;
        return p;
    }
    else {
        int target = queue -> top -> data, *p;
        p = &target;
        queue -> top = queue -> top -> next;
        return p;
    }
    return NULL;
}

int main()
{
	int data, *temp;
	char command[50];
	Queue queue;
	queue.top = NULL;
	queue.bot = NULL;
	while(1)
	{
		scanf("%s", command);
		if(strcmp(command, "exit") == 0)
		{
			break;
		}
		else if(strcmp(command, "enqueue") == 0)
		{
			printf("Please input a integer data:");
			scanf("%d", &data);
			if(enqueue(&queue, data) == 1)
			{
				printf("Successfully enqueue data %d into queue.\n");
			}
			else
			{
				printf("Failed to enqueue data into queue.\n");
			}
		}
		else if(strcmp(command, "dequeue") == 0)
		{
			temp = dequeue(&queue);
			if(temp == NULL)
			{
				printf("Failed to dequeue a data from queue.\n");
			}
			else
			{
				printf("Dequeue data %d from queue.\n", *temp);
			}
		}
	}
	return 0;
}



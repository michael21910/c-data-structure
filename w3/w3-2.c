#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Stack
{
	struct Node *head, *top;
};

int push(struct Stack *stack, int _data)
{
    struct Node *add_this_node = (struct Node *)malloc(sizeof(struct Node));
    add_this_node -> data = _data;
    add_this_node -> next = NULL;
    if(stack -> head == NULL && stack -> top == NULL) {
        stack -> head = add_this_node;
        stack -> top = add_this_node;
        return 1;
    }
    else {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        for(temp = stack -> head; temp != NULL; temp = temp -> next) {
            if(temp -> next == NULL) {
                temp -> next = add_this_node;
                break;
            }
        }
        stack -> top = add_this_node;
        return 1;
    }
    return 0;
}

int *pop(struct Stack *stack)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if(stack -> top == NULL && stack -> head == NULL) {
        return NULL;
    }
    if(stack -> head == stack -> top) {
        int target = stack -> head -> data, *p;
        p = &target;
        stack -> top = NULL;
        stack -> head = NULL;
        return p;
    }
    for(temp = stack -> head; temp != NULL; temp = temp -> next) {
        if(temp -> next == stack -> top) {
            stack -> top = temp;
            int target = stack -> top -> next -> data, *p;
            p = &target;
            return p;
        }
    }
    return NULL;
}

int main()
{
    int data, *temp;
	char command[50];
	struct Stack stack;
	stack.head = NULL;
	stack.top = NULL;
	while(1)
	{
		scanf("%s", command);
		if(strcmp(command, "exit") == 0)
		{
			break;
		}
		else if(strcmp(command, "push") == 0)
		{
			printf("Please input a integer data:");
			scanf("%d", &data);
			if(push(&stack, data) == 1)
			{
				printf("Successfully push data %d into stack.\n", data);
			}
			else
			{
				printf("Failed to push data into stack.\n");
			}
		}
		else if(strcmp(command, "pop") == 0)
		{
			temp = pop(&stack);
			if(temp == NULL)
			{
				printf("Failed to pop a data from stack.\n");
			}
			else
			{
				printf("Pop data %d from stack.\n", *temp);
			}
		}
	}
}

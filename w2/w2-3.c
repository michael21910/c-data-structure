#include<stdio.h>
#include<string.h>

#define SIZE 100

struct Queue
{
    int data[SIZE];
    int top, bot;
};

int enqueue(struct Queue *queue, int data)
{
    int curr_top = queue -> top;
    if(curr_top >= SIZE) {
        return 0;
    }
    queue -> data[curr_top] = data;
    queue -> top = curr_top + 1;
    return 1;
}

int *dequeue(struct Queue *queue)
{
    int curr_top = queue -> top;
    int curr_bot = queue -> bot;
    if(curr_bot == curr_top) {
        return NULL;
    }
    queue -> bot = curr_bot + 1;
    return (&(queue -> data[curr_bot]));
}

int main()
{
    int data, *temp;
    char command[50];
    struct Queue queue;
    queue.top = 0;
    queue.bot = 0;
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
                printf("Successfully enqueue data %d into queue.\n", data);
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
}

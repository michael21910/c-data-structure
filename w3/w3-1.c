#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Set
{
	struct Node *element;
}Set;

int addElement(struct Set *set, int e)
{
    struct Node *add_this_node = (struct Node *)malloc(sizeof(struct Node));
    add_this_node -> data = e;
    // if the set is empty
    if(set -> element == NULL) {
        add_this_node -> next = NULL;
        set -> element = add_this_node;
        return 1;
    }
    // if the set is not empty
    else {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp = set -> element;
        // do not add the element in when there is already one
        while(temp != NULL) {
            if(temp -> data == e) {
                return 0;
            }
            temp = temp -> next;
        }
        add_this_node -> next = set -> element;
        set -> element = add_this_node;
        return 1;
    }
    return 0;
}

Set *unions(Set *a, Set *b)
{
    // just add the two sets together, using function addElement
    struct Set *union_set = (struct Set *)malloc(sizeof(struct Set));
    union_set -> element = NULL;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    for(temp = a -> element; temp != NULL; temp = temp -> next) {
        addElement(union_set, temp -> data);
    }
    for(temp = b -> element; temp != NULL; temp = temp -> next) {
        addElement(union_set, temp -> data);
    }
    return union_set;
}

Set *intersetcions(Set *a, Set *b)
{
    // O(n^2) to check is the element is in both set a and set b
    struct Set *intersection_set = (struct Set *)malloc(sizeof(struct Set));
    intersection_set -> element = NULL;
    struct Node *temp_i = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp_j = (struct Node *)malloc(sizeof(struct Node));
    for(temp_i = a -> element; temp_i != NULL; temp_i = temp_i -> next) {
        for(temp_j = b -> element; temp_j != NULL; temp_j = temp_j -> next) {
            if(temp_i -> data == temp_j -> data) {
                addElement(intersection_set, temp_i -> data);
                break;
            }
            else {
                continue;
            }
        }
    }
    return intersection_set;
}

int equivalent(Set *a, Set *b)
{
    // if the two sets are equivalent, union and intersection must be the same
    // thus, if you can add a element into a set from another set, it is not equivalent
    struct Set *union_set = unions(a, b);
    struct Set *intersection_set = intersetcions(a, b);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    for(temp = union_set -> element; temp != NULL; temp = temp -> next) {
        if(addElement(intersection_set, temp -> data) == 1){
            return 0;
        }
    }
    return 1;
}

int main()
{
	struct Set *a = (struct Set *)malloc(sizeof(struct Set));
	struct Set *b = (struct Set *)malloc(sizeof(struct Set));
	struct Set *c;
	struct Node *cur;
    a -> element = NULL;
    b -> element = NULL;

	addElement(a, 1);
	addElement(a, 2);
	addElement(a, 3);
	addElement(b, 3);
	addElement(b, 4);
	addElement(b, 5);
	addElement(b, 5);

	c = unions(a, b);
	cur = c->element;
	while(cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
    printf("\n");

	c = intersetcions(a, b);
	cur = c->element;
	while(cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
    printf("\n");

	if(equivalent(a, b) == 0)
		printf("Not equivalent.\n");
	else
		printf("Equivalent!\n");
}

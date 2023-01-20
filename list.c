#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

int main(void)
{
    struct node *head = malloc(sizeof(struct node));
    struct node *tracker = head;

    /*Let's create a simple double linked list*/
    tracker->prev = NULL;
    tracker->data = 1;
    tracker->next = malloc(sizeof(struct node));

    tracker = tracker->next;

    tracker->data = 2;
    tracker->next = NULL;
    tracker->prev = head;

    /**
     * I left these in here for easy understanding of the code
     * by anyone who goes through it or by me in the future.
     * 
     * 
     * printf("This is the location of the first node %p\n", head);
     * printf("This is also the location of first node %p\n", tracker->prev);
     * printf("This is the data stored in head %d\n", tracker->prev->data);
     * printf("The address of the second node: %p\n", head->next);
    */


    /*Here we are going to traverse the list*/
    if (head == NULL)
    {
        printf("This is an empty list\n");
    }
    else
    {
        printf("The data stored in the nodes of our first list: [");
        tracker = head;
        while (tracker != NULL)
        {
            if (tracker->next != NULL)
            {
                printf("%d, ", tracker->data);
            }
            else
            {
                printf("%d", tracker->data);
            }
            tracker = tracker->next;
        }
        printf("]\n");
    }   



    /**let's add two more nodes to the list
     * and traverse it backwards
    */ 
    head->next->next = malloc(sizeof(struct node));
    tracker = head->next->next;

    tracker->data = 3;
    tracker->prev = head->next;

    /**
     *  I left these in here for easy understanding of the code
     *  by anyone who goes through it or by me in the future
     * 
     * printf("The address in the tracker: %p\n", tracker);
     * printf("The address of the third node: %p\n", head->next->next);
     * printf("The value in the second node: %d\n", head->next->data);
     * printf("The next address of the second node: %p\n", tracker->prev);
    */

    tracker->next = malloc(sizeof(struct node));

    tracker = tracker->next;
    tracker->data = 4;
    tracker->next = NULL;
    tracker->prev = head->next->next;

    /**
     * I left these in here for easy understanding of the code
     * by anyone who goes through it or by me in the future
     * 
     * printf("The address in the tracker: %p\n", tracker);
     * printf("The next address of the third node: %p\n", tracker->prev);
     * printf("The value in the third node: %d\n", head->next->next->data);
    */


    /*Now let's move backwards*/
    printf("The data stored in the nodes of our new list written backwards: [");
    while (tracker != NULL)
    {
        if (tracker->prev != NULL)
        {
            printf("%d, ", tracker->data);
        }
        else
        {
            printf("%d", tracker->data);
        }
        tracker = tracker->prev;   
    }
    printf("]\n");
    
    printf("-----\n");

    /*Finally let's make a proper written representation of the list*/
    tracker = head;
    char *positions[5] = {"first", "second", "third", "fourth"};

    int i = 0;
    while (tracker != NULL)
    {
        printf("The address of the node behind the %s node is %p\n", positions[i], tracker->prev);
        printf("The content of the %s node is %d\n", positions[i], tracker->data);
        printf("The address of the node after the %s node is %p\n", positions[i], tracker->next);
        printf("The address of the %s node is %p\n", positions[i], tracker);
        printf("-----\n");
        i++;
        tracker = tracker->next;
    } 
    return 0;
}
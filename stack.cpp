#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


node *top = NULL;

void push(int item)
{
    node *nptr = (node*)malloc(sizeof(node));
    nptr->data = item;
    nptr->next = top;
    top = nptr;
}

void display()
{
    struct node *temp;
    temp = top;
    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("\n\nStack is empty ");
    }
    else
    {
        node *temp;
        temp = top;
        top = top->next;
        printf("\n\n%d deleted", temp->data);
        free(temp);
    }
}
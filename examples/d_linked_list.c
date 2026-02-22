/*
 * doubly linked list traversal
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

void insert(Node **head, int data)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return;

    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}

void print_list_fwd(Node *head)
{
    Node *list = head;

    while(list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    putchar('\n');
}

void print_list_rev(Node *head)
{
    Node *list = head;
    Node *tail = NULL;

    while(list)
    {
        tail = list;
        list = list->next;
    }
    while(tail)
    {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    putchar('\n');
}

void free_list(Node *head)
{
    Node *list = head;

    while (list)
    {
        Node *next = list->next;
        free(list);
        list = next;
    }
}

int main(void)
{
    Node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    printf("List (forward): ");
    print_list_fwd(head);
    printf("List (reverse): ");
    print_list_rev(head);

    free_list(head);
    head = NULL;

    return 0;
}

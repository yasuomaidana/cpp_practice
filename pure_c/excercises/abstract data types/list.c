#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct list
{
    int data;
    struct list *next;
} list;

int is_empty(const list *l)
{
    return (l == NULL);
}

void print_list(list *h, char *title)
{
    printf("%s\n", title);
    while (h != NULL)
    {
        printf("%d :", h->data);
        h = h->next;
    }
}

int main(void)
{
    list list_of_int;
    list *head = NULL;

    head = malloc(sizeof(list));

    printf("sizeof(list) = %lu\n",sizeof(list));

    head->data = 5;
    head->next = NULL;

    print_list(head, "single element list");
    free(head);
}
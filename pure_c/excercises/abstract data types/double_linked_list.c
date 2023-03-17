#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct double_linked_node
{
    int value;
    struct double_linked_node *prev;
    struct double_linked_node *next;
} dln;

typedef dln *DLN;

DLN create_node(int value)
{
    DLN node = (malloc(sizeof(DLN)));
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

DLN add_element(DLN node, int next_value)
{
    DLN next_node = create_node(next_value);
    next_node->prev = node;
    node->next = next_node;
    return next_node;
}

void swap_nodes(DLN a, DLN b){
    a->next = b->next;
    b->prev = a->prev;

    a->prev = b;
    b->next = a;
}

void print_forward(DLN node){
    if(node != NULL){
        printf("%d ",node->value);
        print_forward(node->next);
    }
}

void print_backward(DLN node){
    if(node != NULL){
        printf("%d ",node->value);
        print_backward(node->prev);
    }
}
void main()
{
    DLN tail = create_node(0);
    DLN head = add_element(tail,1);
    head = add_element(head,2);
    head = add_element(head,3);
    print_backward(head);
    printf("\n");
    print_forward(tail);

}
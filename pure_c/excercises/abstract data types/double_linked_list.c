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

DLN create_node(int value, DLN prev)
{
    DLN node = (DLN)(malloc(sizeof(DLN)));
    node->value = value;
    node->prev = prev;
    return node;
}

DLN create_from_list(int current_index, int array_size, DLN previous_node, int array[]){
    DLN node;
    if(current_index < array_size){
        node = create_node(array[current_index], previous_node);
        node->next = create_from_list(current_index+1,array_size,node,array);
    }
    else { 
        return NULL; 
        }
    return node;
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
    return;
}

void main(void)
{
    int array[4] = {1,2,3,4};
    DLN head = create_from_list(0,4,NULL,array);
    print_forward(head);
    free(head);
}
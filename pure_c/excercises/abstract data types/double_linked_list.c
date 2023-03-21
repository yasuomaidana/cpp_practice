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

DLN create_from_list(int current_index, int array_size, DLN previous_node, int array[]){
    if(current_index < array_size){
        DLN node = create_node(array[current_index++]);
        node->prev = previous_node;
        node->next = create_from_list(current_index,array_size,node,array);
        return node;
    }
    else return NULL;
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
    int array[3] = {1,2,4};
    DLN head = create_from_list(0,3,NULL,array);
    print_forward(head);

}
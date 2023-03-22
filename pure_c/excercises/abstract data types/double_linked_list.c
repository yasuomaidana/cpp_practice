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

DLN create_list(int current_index, int array_size, DLN previous_node){
    DLN node;
    if(current_index < array_size){
        node = create_node(rand(), previous_node);
        node->next = create_list(current_index+1,array_size,node);
    }
    else { 
        return NULL; 
        }
    return node;
}

DLN swap_nodes(DLN a, DLN b){
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
    return a;
}

void print_forward(DLN node){
    while(node != NULL){
        printf("%d ",node->value);
        node = node->next;
    }
}

void print_backward(DLN node){
    while(node != NULL){
        printf("%d ",node->value);
        node = node->prev;
    }
}

DLN rise_bubble(DLN head, int level){
    if(level-1>0){
        if(head->value>head->next->value){
            head = swap_nodes(head,head->next);
        }
        head->next = rise_bubble(head->next,level-1);
    }
    return head;
}
DLN bubble_sort(DLN head, int i, int size){

    if(i<size){
        head = bubble_sort(rise_bubble(head,size-i),i+1,size);
    }
    return head;
}

DLN get_tail(DLN head){
    while(head->next!=NULL){
        head = head->next;
    }
    return head;
}
void main(){
    int items = 100;
    DLN head = create_list(0,items,NULL);
    head = bubble_sort(head,0,items);
    printf("\n-------Forward---------\n");
    print_forward(head);
    printf("\n--------Backward--------\n");
    print_backward(get_tail(head));
}
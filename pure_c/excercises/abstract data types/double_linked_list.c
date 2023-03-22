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

DLN swap_nodes(DLN a, DLN b){
    a->next = b->next;
    b->prev = a->prev;

    a->prev = b;
    b->next = a;

    return b;
}

void print_forward(DLN node){
    if(node != NULL){
        printf("%d ",node->value);
        print_forward(node->next);
    }
    return;
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
void main(){
    int array[100] = {0};
    for(int i = 0; i<100; i++){
        array[i] = rand();
    }
    DLN head = create_from_list(0,100,NULL,array);
    head = bubble_sort(head,0,100);
    print_forward(head);
    system("pause");
}
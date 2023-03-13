#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN-1)

typedef struct stack{
    char s[MAX_LEN];
    int top;
    } stack;

void reset(stack *stk){
    stk ->top = EMPTY;
}

int is_empty(stack *stk){
    return stk->top == EMPTY;
}

int is_full(stack *stk){
    return stk->top == FULL;
}

void push(char c, stack *stk){
    if(is_full(stk)){
        printf("It is full");
        return;
    }
    stk -> top++;
    stk -> s[stk -> top] = c;
}

char pop(stack *stk){
    if(is_empty(stk)){
        printf("It is empty\n");
        return '\0';
    }
    return stk -> s[stk -> top--];
}
char top(stack *stk){
    return stk -> s[stk -> top];
}

int main(){
    stack stack_of_char;
    char *str = "Hi this is an example";
    
    int i = 0;
    reset(&stack_of_char);
    while(str[i] != '\0'){
        printf("%c\n",str[i]);
        push(str[i++], &stack_of_char);
    }
    
    char str_back[i];

    i=0;
    while (!is_empty(&stack_of_char))
    {
        str_back[i++] = pop(&stack_of_char);
    }
    
    pop(&stack_of_char);

    printf("Original S: %s\n",str);
    printf("Reversed S: %s\n",str_back);
}
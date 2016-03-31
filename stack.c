//
// Created by thy21 on 3/31/2016.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _Stack {
    int data;
    struct _Stack *next;
}stack;

void push(stack* s, int i) {
    stack* st = (stack*) malloc(sizeof(stack));
    while(s->next != 0x0)
        s=s->next;
    s->next = st;
    st->next = NULL;
    st->data = i;
}

int pop(stack* s){
    if(s->next == NULL) {
        printf("NO STACK TO POP!\n");
        return 0;
    }
    int d;
    stack* target;

    while(s->next->next != 0x0) {
        s=s->next;
    }

    d = s->next->data;
    target = s->next;
    s->next = NULL;
    free(target);
    return d;
}

int main(int argc, char const *argv[]) {
    int i;
    char c;
    stack* head = (stack*) malloc(sizeof(stack));
    head->next = NULL;
    head->data = 0;

    while(1) {
        printf("Input command. S: stack, P: pop, E: exit\n");
        scanf(" %c", &c);
        if(c == 'E' || c == 'e') break;
        switch (c) {
            case 'S' :
            case 's' :
                printf("Input data to stack: ");
                scanf("%d", &i);
                push(head, i);
                break;
            case 'P' :
            case 'p' :
                i = pop(head);
                printf("POP: %d\n", i);
                break;
        }
    }
    free(head);
}
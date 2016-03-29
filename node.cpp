//
// Created by kyujin on 3/29/16.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int num;
	struct _Node* next;
} node;

void append(node* n, int i) {
	if(n == 0x0) {
		n = (node*) malloc(sizeof(node));
		n->num = i;
	} else {
		while(n->next != 0x0) {
			n=n->next;
		}
		n->next = (node*) malloc(sizeof(node));
		n->num = i;
	}
}

void insert(node* n, int i, int p) {
	int ic=0;
	node* tmp=NULL, *tmp2=NULL, *target = NULL;

	while(ic != p) {
		printf("%p\n", n);
		n=n->next;
		ic++;
	}

	target = n;
	tmp = n->next;
	n->next = n;

	while(n->next != 0x0) {
		printf("%p %p\n", tmp, n->next);
		tmp2 = tmp;
		tmp = n->next;
		n->next = tmp2;
		printf("%p %p\n", tmp, n->next);
		n = n->next;
	}

	target->num = i;

}

void remove(node* n, int p) {
	 int tmp, j;
}

void node_print(node* n, int p) {
	int i=0;

	while(i != p) {
		i++;
		n=n->next;
	}
	printf("Linked List Number: %d\n", n->num);
}

void node_print_all(node* n) {
	printf("Printing Linked List Number: \n");
	while(n->next != 0x0) {
		printf("%d %p\n", n->num, n);
		n=n->next;
	}
}

int main(int argc, char* argv[]) {
	int i;

	node *head = (node*) malloc(sizeof(node));
	printf("Main: %p\n", head);

	for(i=1; i<=10; i++)
		append(head, i);
	printf("Main: %p\n", head);
	node_print_all(head);

	node_print(head, 5);
	insert(head, 999, 5);
	node_print(head, 5);
	node_print_all(head);

	free(head);
	return 0;
}

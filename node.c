//
// Created by kyujin on 3/29/16.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
int num;
struct _Node* next;
} node;

void node_append(node* n, int i) {
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

void node_insert(node* n, int i, int p) {
	int ic=0, tmp, tmp2;
	node *target = NULL;

	while(ic != p) {
		printf("%p\n", n);
		n=n->next;
		ic++;
	}

	target = n;
	tmp = n->num;
	while(n->next != 0x0){
		n=n->next;
		tmp2 = tmp;
		tmp = n->num;
		n->num = tmp2;

	}

	n->next = (node*) malloc(sizeof(node));
	n->next->num = tmp;

	target->num = i;

}

void node_remove(node* n, int p) {
	int ic=0, j;
	node* target = NULL;

	while(ic != p) {
		printf("%p\n", n);
		n=n->next;
		ic++;
	}

	target = n;
	while(n->next->next != 0x0) {
		n->num = n->next->num;
		n=n->next;
	}

	n->num = n->next->num;
	n->next = NULL;
	free(n->next);
}

void node_print(node* n, int p) {
	int i=0;

	while(i != p) {
		i++;
		n=n->next;
	}
	printf("Linked List Number: %d, %p\n", n->num, n);
}

void node_print_all(node* n) {
	printf("Printing Linked List Number: \n");
	while(n->next != 0x0) {
		printf("%d %p\n", n->num, n);
		n=n->next;
	}
}

int main(int argc, char* argv[]) {
	int i, j;
	char c;

	node *head = (node*) malloc(sizeof(node));
	printf("Main: %p\n", head);

//	for(i=1; i<=10; i++)
//		node_append(head, i);
//	printf("Main: %p\n", head);
//	node_print_all(head);
//
//	node_print(head, 5);
//	node_insert(head, 54, 5);
//	node_print(head, 5);
//	node_print_all(head);
//	node_remove(head, 5);
//	node_print(head, 5);
//	node_print(head, 10);
//	node_print_all(head);

	printf("Input command(I: insert, A: append, D: delete, P: print, R: print all. E: exit.\n");
	scanf(" %c", &c);
	while(1) {
		if(c =='E' || c == 'e') break;
		switch(c) {
			case 'I':
			case 'i':
				printf("Input number and position (For example, 4 5 measn put number 4 in fifth node)\n");
				scanf("%d %d", &i, &j);
				node_insert(head, i, j);
				break;
			case 'A' :
			case 'a' :
				print("Input number (for example, 4 means append number 4)\n");
				scanf("%d", &i);
				node_append(head, i);
				break;
			case 'D' :
			case 'd' :
				printf("Input node position to delete (For example, 5 means delete node in postition 5)\n");
				scanf("%d", &i);
				node_remove(i);
				break;
			case 'P' :
			case 'p' :
				printf("Input node position to print (For example, 5 means print number in fifth node)\n");
				scanf("%d", &i);
				node_print(head, i);
				break;
			case 'R' :
			case 'r' :
				node_print_all(head);
				break;

		}
	}


	free(head);
	return 0;
}
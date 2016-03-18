#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int num;
	struct _Node* next;
} node;

node* add(int i, node* link) {
	link->next = (node*) malloc(sizeof(node));
	link->next->num = i;
}

void node_print(node* n) {
	node* tmp = n;

	while(tmp!=0x0) {
		printf("%d\n", tmp->num);
		tmp = tmp->next;

	}
}

int main(int argc, char* argv[]) {
	node *head, *n;
	int i;
	head = (node*) malloc(sizeof(node));
	n = head;
	head->num = 1;

	// printf("%p\n", head);

	for(i=2; i<=15; i++) {
		n = add(i,n);
	}

	node_print(head);

}
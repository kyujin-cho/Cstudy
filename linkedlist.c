#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int num;
	struct _Node* next;
	struct _Node* previous;
} node;

node* add(int i, node* link) {
	node* tmp;

	if(link==0x0) {
		link = (node*) malloc(sizeof(node));
		link->num = i;
	} else {
		tmp=link;
		link->next = (node*) malloc(sizeof(node));
		link=link->next;
		link->previous=tmp;
		link->num = i;
	}

	return link;

}

node* reverse(node* link) {
	do {
		link = link->previous;
	} while(link->previous!=0);

	return link;
}

void node_print(node* link) {
	while(link!=0x0) {
		printf("%d\n", link->num);
		link = link->next;
	}
}

int main(int argc, char* argv[]) {
	node *head = NULL;
	int i;

	for(i=1; i<=5; i++) {
		head = add(i, head);
	}

	// while(1) {
	// 	scanf("%d", &i);
	// 	if(i!=-741) head = add(i, head);
	// 	else break;
	// }
	
	head = reverse(head);
	node_print(head);
	free(head);

	return 0;
}
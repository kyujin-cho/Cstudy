//
// Created by kyujin on 3/29/16.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
int num;
struct _Node* next;
} node;

void node_append(node* n, int i) { // 노드 맨 끝에 새로 추기
	if(n == 0x0) { // 받은 노드가 NULL일때
		n = (node*) malloc(sizeof(node));
		n->num = i; // 노드에 메모리를 할당해주고 - 노드를 생성해주고 - 노드에 받은 데이터 삽입
	} else { // 받은 노드가 NULL이 아닐때
		while(n->next != 0x0) { // 노드의 next 포인터가 널이 아닐때 -> 노드의 next가 null이 될때까지 즉 노드의 맨 끝까지 이동
			n=n->next;
		}
		n->next = (node*) malloc(sizeof(node)); // 마지막 노드로 도달하면 새로운 노드를 생성 후에 마지막 노드의 next 포인터가 생성된 노드를 가리키도록 변
		n->num = i;
	}
}

void node_insert(node* n, int i, int p) {  // 노드 중간에 값 삽입
	int j;
	node *target = (node*) malloc(sizeof(node)); // 삽입할 노드 생성

	for(j=1;j<p;j++) { // 삽입할 부분까지 노드 이동
		if (n == 0x0) return; // 중간에 노드가 0x0이 되면 올바르지 않은 위치 -> 삽입작업 중단
		n=n->next;
	}

	target->num = i; // 삽입할 노드에 데이터 넣기

	target->next = n->next->next; // 그림 참조
	n->next = target; // 그림 참조
}

void node_remove(node* n, int p) { // 노드 중간에 제거
	int j;
	node* target = NULL; // 제거할 노드 포인터를 저장할 포인터

	for(j=1;j<p;j++) { // 제거할 부분까지 노드 이동
		if (n == 0x0) return; // 중간에 노드가 0x0이 되면 올바르지 않은 위치 -> 제거작업 중단
		n=n->next;
	}
	target = n->next; // 그림 참조
	n->next = n->next->next; // 그림 참조

	free(target); // 제거한 노드 메모리 회수
}

void node_print(node* n, int p) { // 특정 부분 노드 프린트
	int i=0;

	while(i != p) { // 프린트할 부분까지 노드 이동
		i++;
		n=n->next;
	}
	printf("Linked List Number: %d, %p\n", n->num, n); // 프린트할 노드의 데이터 및 주소값 프린트
}

void node_print_all(node* n) { // 노드 처음부터 끝까지 프린트
	printf("Printing Linked List Number: \n");
	while(n->next != 0x0) { // 노드의 next 포인터가 0x0일때까지 -> 노드의 끝까지 이동
		printf("%d %p\n", n->num, n); // 프린트할 노드의 데이터 및 주소값 프린트
		n=n->next; // 다음 노드로 이동
	}
}

int main(int argc, char* argv[]) {
	int i, j, k;
	char c;

	node *head = (node*) malloc(sizeof(node)); // 헤드 노드 생성
	head->next = NULL; // 잘못된 주소 할당 방지 위해 next 포인터 0x0 으로 만들어 놓기 -> head 노드가 노드의 끝이라는 것 명시
	printf("Main: %p, %p\n", head, head->next); // 헤드 노드 및 next 포인터 프린트


	while(1) {
		printf("Input command(I: insert, A: append, C: Append sequentially, D: delete, P: print, R: print all. E: exit.\n");
		scanf(" %c", &c);
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
				printf("Input number (for example, 4 means append number 4)\n");
				scanf("%d", &i);
				node_append(head, i);
				break;
			case 'C' :
			case 'c' :
				printf("Input number (for example, 4 8 means append number 4 5 6 7 8 in a row)\n");
				scanf("%d %d", &i, &j);
				for(k=i; k<=j; k++)
					node_append(head, k);
				break;
			case 'D' :
			case 'd' :
				printf("Input node position to delete (For example, 5 means delete node in postition 5)\n");
				scanf("%d", &i);
				node_remove(head, i);
				break;
			case 'P' :
			case 'p' :
				printf("Input node position to print(For example, 5 means print number in fifth node)\n");
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

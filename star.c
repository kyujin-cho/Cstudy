#include <stdio.h>

int main() {
	int i,j,k;

	printf("      *\n");
	for(i=1; i<=5; i++) {
		for(j=1;j<=6-i;j++) printf(" ");
		printf("*");
		for(k=1;k<=2*i-1;k++) printf(" ");
		printf("*\n");
	}
	
	for(i=1; i<=4; i++) {
		for(j=1;j<=i+1;j++) printf(" ");
		printf("*");
		for(k=1;k<=9-2*i;k++) printf(" ");
		printf("*\n");
	}
	
	printf("      *\n");
}

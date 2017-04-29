#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flagA = 0, flagB = 0;

int Swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void DFS(int A, int B, int C) {
	if (flagA) return ;
	if (A == 1 && B == 1) { // B能分解完之后A还能分解完
		flagA = 1;
		return;
	}
	if (B == 1) {
		flagB = 1;
	}
	while (C) {
		if (A % C == 0) DFS(A / C, B, C - 1);
		if (B % C == 0) DFS(A, B / C, C - 1);
		C--;
	}
}

int main(int argc, char * argv[]) {
	int A, B;
	while (scanf("%d %d", &A, &B) != EOF) {
		flagA = flagB = false;
		if (B > A) Swap(A, B);
		DFS(A, B, 100);
		if (!flagA && flagB) printf("%d\n", B);
		else printf("%d\n", A);
	}
	return 0;
}
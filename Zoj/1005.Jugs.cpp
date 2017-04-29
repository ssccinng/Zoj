#include <stdio.h>

int main(int argc, char * argv[]) {
	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c) != EOF) {
		int A = 0, B = 0;
		while (true) {
			if (A == 0) {
				printf("fill A\n");
				A = a;
			}
			if (A == c || B == c) break;
			printf("pour A B\n");
			if (A + B > b) {
				A = A + B - b;
				B = b;
			}
			else {
				B = A + B;
				A = 0;
			}
			if (A == c || B == c) break;
			if (B == b) {
				printf("empty B\n");
				B = 0;
			}
		}
		printf("success\n");
	}
	return 0;
}
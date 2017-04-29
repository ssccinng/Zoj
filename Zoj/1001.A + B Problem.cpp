#include <stdio.h>

typedef long long LL;

int main(int argc, char * argv[]) {
	LL A, B;
	while (scanf("%lld %lld", &A, &B) != EOF) {
		printf("%lld\n", A + B);
	}
	return 0;
}
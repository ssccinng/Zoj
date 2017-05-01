#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
	int k;
	char stand[28] = {};
	char nistand[128] = {};
	stand[0] = '_'; stand[27] = '.';
	nistand['_'] = 0; nistand['.'] = 27;
	for (int i = 1; i <= 26; ++i) {
		stand[i] = 'a' + i - 1;
		nistand['a' + i - 1] = i;
	}
	while (scanf("%d", &k), k) {
		char str[100] = {};
		char ans[100] = {};
		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0; i < len; ++i) {
			ans[k * i % len] = stand[(nistand[str[i]] + i) % 28];
		}
		ans[len] = 0;
		printf("%s\n", ans);
	}
	return 0;
}
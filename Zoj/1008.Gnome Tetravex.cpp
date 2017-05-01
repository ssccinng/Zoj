#include <stdio.h>
#include <stdlib.h>

int zhen[7][7][4];
int flag = 0;

void DFS(int n)

int main(int argc, char * argv[]) {
	int n;
	while (scanf("%d", &n), n) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%d %d %d %d", &zhen[i][j][0], &zhen[i][j][1], &zhen[i][j][2], &zhen[i][j][3]);
			}
		}
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ans = 0;
int cnt = 0;

bool isok(int ** Graph, int i, int j, int N) {
	int a = i, b = i;
	while (a--) {
		if (Graph[a][j] == 1) break;
		if (Graph[a][j] == 2) return false;
	}
	a = i;
	while (a++ < N - 1) {
		if (Graph[a][j] == 1) break;
		if (Graph[a][j] == 2) return false;
	}
	while (b--) {
		if (Graph[i][b] == 1) break;
		if (Graph[i][b] == 2) return false;
	}
	b = i;
	while (b++ < N - 1) {
		if (Graph[i][b] == 1) break;
		if (Graph[i][b] == 2) return false;
	}
	return true;
}

void DFS(int ** Graph, int N) {
	if (cnt > ans) ans = cnt;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!Graph[i][j] && isok(Graph, i, j, N)) {
				cnt++;
				Graph[i][j] = 2;
				DFS(Graph, N);
				cnt--;
				Graph[i][j] = 0;
			}
		}
	}
}

int main(int argc, char * argv[]) {
	int N;
	while (scanf("%d\n", &N), N) {
		ans = cnt = 0;
		int * sour = new int[(N) * (N)]();
		int ** Graph = new int *[N];
		for (int i = 0; i < N; ++i) {
			Graph[i] = i * N + sour;
		}
		char n;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				scanf("%c", &n);
				if (n == 'X') Graph[i][j] = 1;
			}
			getchar();
		}
		DFS(Graph, N);
		printf("%d\n", ans);
		delete[] sour, Graph;
	}
	return 0;
}
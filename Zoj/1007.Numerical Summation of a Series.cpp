#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char * argv[]) {
	double x = 0, ans;
	for (int i = 0; i <= 2000; ++i) {
		ans = 0;
		for (int j = 1; j < 10000; ++j) {
			ans += 1.0 / ((j + 1) * j * (j + x));
		}
		ans = ans * (1 - x) + (1 - x) / (2 * 10000 * 10000) + 1.0;
		printf("%5.3f %16.12f\n", x, ans);
		x += 0.001;
	}
	return 0;
}
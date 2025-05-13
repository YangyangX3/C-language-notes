#include <stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	int i, j, k;
	int cut = 0;
	i = a;
	while (i <= a + 3) {
		j = a;
		while (j <= a + 3) {
			k = a;
			while (k <= a + 3) {
				if (i != j && i != k && k != j) {
					printf("%d", i * 100 + j * 10 + k);
					cut++;
					if (cut == 6) {
						printf("\n");
						cut = 0;
					} else {
						printf(" ");
					}
				}

				k++;
			}
			j++;
		}
		i++;
	}

	return 0;
}

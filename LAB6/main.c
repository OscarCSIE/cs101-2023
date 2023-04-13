#include <stdio.h>

void multi(int i, int j) {
	printf("%d * %d = %d\t", i, j, i * j);
	if(i * j == 81) {
		return;
	}else if (j == 9) {
		i++;
		j = 0;
		printf("\n");
	}
	j++;
	multi(i, j);
}

int main() {
	multi(1,1);
	return 0;
}

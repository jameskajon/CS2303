#include <stdio.h>

int main (void) {
	int c, ln;
	for (ln = 0; (c = getchar()) != EOF; ln++)
		;
	printf("%d\n", ln);
	return 0;
}
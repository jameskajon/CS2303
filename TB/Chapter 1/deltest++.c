#include <stdio.h>
int main()
{
	int a;
	printf("%d\n", a);
	printf("%d %d %d\n", a, a++, a);
	printf("%d\n\n", a);
	printf("%d\n", a);
	printf("%d %d %d\n", a, ++a, a);
	printf("%d\n\n", a);
	return 0;
}
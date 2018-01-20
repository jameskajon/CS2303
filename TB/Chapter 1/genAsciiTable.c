#include <stdio.h>
int main() {
	FILE *fp;
	fp = fopen("asciiTable.txt", "w");
	for (int a=0; a < 256; a++) {
		//fprintf(fp, "%d\t%c\n", a, a+'0');
		fprintf(fp, "%d\t%c\n", a, a+'0');
	}
	fclose(fp);
	return 0;
}

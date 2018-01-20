#include <stdio.h>

#define	LOWER	0		/* lower limit of table */
#define UPPER	300		/* upper limit */
#define STEP	20		/* step size */



// convert fahrenheit to celsius
float fToC(int f) {
	return (5.0 / 9.0) * (f - 32);
}

/* print a fahrenheit to celsius table for */
int main() {
	for (int f=LOWER; f <= UPPER; f+=STEP) {
		printf("%3d %6.1f\n", f, fToC(f));
	}
}


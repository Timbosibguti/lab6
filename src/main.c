#include <stdio.h>
#include "app.h"

int main()
{
	double a, b, c, d, x1, x2;
	int koren;
	printf("vvedite a b c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	koren = uravn(a, b, c, &d, &x1, &x2);
	if (koren == -1)
	{
		printf("a dolzhen byt ne raven nulju\n");
		return 0;
	}
	
	printf("D: %.2lf.\n", d);
	
	if (koren == 0)
		printf("kornej net\n");
	else if (koren == 1)
		printf("x = %.2lf.\n", x1);
	else
		printf("x1: %.2lf. x2: %.2lf.\n", x1, x2);
}

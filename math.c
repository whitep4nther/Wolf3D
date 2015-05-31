#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
# define R2D(a) (a * 180.0 / 3.14159265)
# define D2R(a) (a * 0.017453292519)
int main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	double acosa;
	double asina;
	double	cosa;
	double	sina;
	double	n;

	cosa = cos(D2R(atoi(av[1])));
	sina = sin(D2R(atoi(av[1])));
	acosa = R2D(acos(-cosa));
	asina = R2D(asin(-sina));
	if (asina > 0)
		n = acosa;
	else
		n = 360 - acosa;
	printf("angle %d\n-cosa %.2lf, -sina %.2lf, acos %.2lf, asin %.2lf, new angle %.2lf\n", atoi(av[1]), -cosa, -sina, acosa,asina, n);
	return (0);
}

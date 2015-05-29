#include <stdlib.h>
#include <math.h>
#include <stdio.h>

# define PI 3.14159265

int main(int ac, char **av)
{
	double x, y, ret, val;

	x = atoi(av[1]);
	y = atoi(av[2]);
	val = 180.0 / PI;

   ret = atan2(x, y) * val;
   printf("The arc tangent of x = %lf, y = %lf ", x, y);
   printf("is %lf degrees\n", ret);
  
   return(0);
}

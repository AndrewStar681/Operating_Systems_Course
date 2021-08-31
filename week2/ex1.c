#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>

int	main(void)
{
	int	a;
	float	b;
	double	c;

	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX; 
    printf("Integer:\n\n");
	printf("size of a : %lu \na = %d", sizeof(a), a); 
    printf("\n\nFloat:\n\n");
    printf("size of : b %lu \nb = %f", sizeof(b), b);
    printf("\n\nDouble:\n\n");
    printf("size of c : %lu \nc = %e\n", sizeof(c), c);
    return EXIT_SUCCESS;
}

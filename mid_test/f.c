#include <stdio.h>
int main(void)
{
	char c=3;
	int i=6;
	printf("%d \n", sizeof c+i);
	printf("%d \n", sizeof (c+2.0));
	printf("%d \n", sizeof c+3.0);
	printf("%d \n", 1+3.0);
			
	return 0;
}

#include <stdio.h>
int main(void){
	int n=0, i;
	printf("input : ");
	scanf("%d", &n);

	for(;n<=9;n++)
	{
			for(i=1; i<=9; i++)
					printf("%d * %d = %d\n", n, i, n*i);
	}
	return 0;
}

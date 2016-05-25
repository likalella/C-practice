#include <stdio.h>
int main(void)
{
		int a=0, b=0, c=0, x=0;
		
		printf("Input a, b, and c : ");
		scanf("%d %d %d", &a, &b, &c);
		printf("Input x : ");
		scanf("%d", &x);
		printf("f(%d) = %d", x, a*x*x+b*x+c);
		return 0;
}

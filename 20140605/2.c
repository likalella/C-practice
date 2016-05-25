#include <stdio.h>
void func(int a, int b, int c[])
{
		c[0]=a/b;
		c[1]=a%b;
}
int main(void)
{
		int a=0, b=0;
		int c[2];
		printf("Input a dividend : ");
		scanf("%d", &a);
		printf("Input a divisor : ");
		scanf("%d", &b);

		func(a, b, c);
		printf("%d / %d = %d\n",a,b,c[0]);
	  printf("%d %% %d = %d\n",a,b,c[1]);
		return 0;
}

#include <stdio.h>
int my_abs(int a)
{
		if(a<0)
				a*=-1;
		return a;
}
int main(void)
{
		int num=0;
		printf("input num : ");
		scanf("%d", &num);
		printf("result : %d \n ", my_abs(num));		
}

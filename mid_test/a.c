#include <stdio.h>
int main(void)
{
		int a=1, b=3;
		if((a==1)||(b=5))
				printf("a : %d, b : %d\n",a,b);
		(a=0)&&(b=1);
		printf("a : %d, b : %d",a,b);
		return 0;
}

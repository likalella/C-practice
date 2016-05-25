#include <stdio.h>
int main(void)
{
		int a=0; int b=0;
		printf("hello world! \n");
		for(a=0; a<10; a++){
				printf("hello %d \n", a);
				for(b=0; b<5; b++){
						printf("_%d ",b);
				}
		}
		return 0;
}

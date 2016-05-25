#include<stdio.h>
int main(void)
{
		int i=0;
		printf("Su  Mo  Tu  We  Th  Fr  Sa\n");
		for(i=0; i<8; i++)
				printf(" ");
		for(i=1;i<34; i++){
			if(i%7==6)
					printf("\n");
			if(i<10)
				printf(" ");
			printf("%d  ",i);
		}
			
		return 0;
}

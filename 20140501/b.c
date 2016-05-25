#include<stdio.h>
int main(void)
{
		int i=0;
		printf("input : ");
		scanf("%d",&i);
		if(i==1 || i==2 || i==3){
			printf("statement_2\n");
			if(i==3)
				printf("statement_3\n");
			else
				printf("statement_1\n");
		}
		return 0;
}

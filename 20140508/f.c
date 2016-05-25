#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
		int a=0;
		srand(time(NULL));
		while(a<10){
			printf("%d ",rand());
			a++;
		}
		return 0;
}

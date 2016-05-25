#include <stdio.h>
int main(void)
{
		#define N 10
		int data[N];
		int i=0;
		for(i=0; i<N; i++)
		{
				printf("Input a Number in data[%d] : ", i);
				scanf("%d", &data[i]);
		}
		for(i=0; i<N; i++)
		{
				printf("data[%d] : %d\n", i, data[i]);
		}
		return 0;
}

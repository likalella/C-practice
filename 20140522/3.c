#include <stdio.h>
int main(void)
{
		#define N 10
		int data[N];
		int i=0, j=0;
		int temp=0;:
		for(i=0; i<N; i++)
		{
				printf("Input a Number in data[%d] : ", i);
				scanf("%d", &data[i]);
		}
	
		for(i=0; i<N-1; i++)
		{
				for(j=N-1; j>i; j--)
						if(data[j-1]>data[j])
						{
								temp = data[j-1];
								data[j-1] = data[j];
								data[j]=temp;
						}
		}
		printf("min number : %d\n", data[0]);
		printf("max number : %d\n", data[N-1]);
		return 0;
}

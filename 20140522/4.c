#includ <stdio.h>
int main(void)
{
		#define N 10
		int data[N];
		int i=0, total=0;
		for(i=0; i<N; i++)
		{
				printf("Input a Number in data[%d] : ", i);
				scanf("%d", &data[i]);
		}
		for(i=0; i<N; i++)
		{
				total+=data[i];
		}
		printf("Total : %d\n", total);
		return 0;
}

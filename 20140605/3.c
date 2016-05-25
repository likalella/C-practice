#include <stdio.h>
void my_reverse(int a[], int size)
{
		for(size-=1; size>=0; size--)
				printf("%d ", a[size]);
		
}
int main(void)
{
		int i=0;
		int a[10] = {0,2,4,6,8,10,12,14,16,18};
		for(i=0; i<(sizeof(a)/4); i++)
		{
				printf("%d ",a[i]);
		}
		printf("\n");
		my_reverse(a, sizeof(a)/4);
		return 0;
}

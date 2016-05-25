#include <stdio.h>
void insert_num(int a[], int b, int c)
{
		int swap;
		for(; b<10; b++)
		{
				swap=a[b];
				a[b]=c;
				c=swap;
		}
}
int main(void)
{
		int i=0;
		int a[10]={8,6,9,1,4,2,3,7,0,5};
		for(i=0; i<10; i++)
				printf("%d ", a[i]);
		printf("\n");
		
		insert_num(a ,2, 6);
		
		for(i=0; i<10; i++)
				printf("%d ", a[i]);
		
		return 0;
}	

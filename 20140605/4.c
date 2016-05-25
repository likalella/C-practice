#include <stdio.h>
void set_to_zero(int a[], int size)
{
		size--; // 배열의 인덱스는 0번부터~
		while(size>=0)
		{
				a[size]=0;
				size--;
		}
}
int main(void)
{
		int i=0;
		int a[30];
		set_to_zero(a, sizeof(a)/4);
		for(i=0; i<sizeof(a)/4; i++)
			printf("%d ",a[i]);
		return 0;
}

#include <stdio.h>
int main(void)
{
		#define N 4
		int a[N] = {0,2,2,3,4};
		int b[N-5];
		int c[3.0];
		float x =2.0;
		a[x] = a[x-1];
		return 0;
}

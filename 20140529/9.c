#include <stdio.h>
int main(void)
{
	static n=0;	
	printf("끝나지 않는 재귀 함수...\n");
	if(n<5)
		main();
}

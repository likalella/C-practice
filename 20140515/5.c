#include <stdio.h>
int main(void)
{
		int F;
		printf("화씨온도를 입력하세요 : ");
		scanf("%d", &F);
		printf("%.1f F = %.1f C\n", (float)F, (float)(F-32)*5/9);
		return 0;
}

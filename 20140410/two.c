#include <stdio.h>
int main(void)
{
		int num;
		printf("숫자를 입력하세요 : ");
		scanf("%d", &num);
		printf("%d의 거듭제곱은 %d 입니다.\n", num, num*num);
		return 0;
}


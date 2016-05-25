#include <stdio.h>
int main(void){
		float num;
		printf("수를 입력하세요 : ");
		scanf("%f", &num);
		printf("%f의 거듭제곱은 %f 입니다.", num, num*num);
		return 0;
}

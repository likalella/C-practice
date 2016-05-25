#include <stdio.h>
int main(void){
	int a1=0, a2=0, a3=0, a4=0, a5=0, cnt;
	char c;
	printf("데이터를 입력 하세요 : ");
	cnt = scanf("%d%d%d", &a1, &a2, &a3);
	printf("첫 번째 scnaf()로 입력된 데이터 개수 : %d\n", cnt);

	cnt = scanf("%c%d%d", &c, &a4, &a5);
	printf("두 번째 scanf()로 입력된 데이터 개수 : %d\n", cnt);

	printf("a1 = %d, a2 = %d, a3 = %d\n", a1 ,a2, a3);
	printf("c = %c, a4 = %d, a5 = %d\n", c ,a4, a5);
	return 0;
}

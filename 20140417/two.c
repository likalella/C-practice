#include <stdio.h>
int main(void){
	int a=2, b=-3, c=5, d=-7, e=11;
	printf("a / b / c = %d \n", a/b/c);
	printf("7 + c * -- d / e = %d \n", 7+c*--d/e);
	printf("2 * a  -b + c + 1 = %d \n", (((2*a)%-b)+c)+1);
	printf("39 / - ++ e - + 29  c = %d \n", (39/-(++e))-(+(29%c)));
	printf("a += b += c += 1 + 2 = %d \n",(a+=(b+=(c+=1)))+2);

	return 0;
}

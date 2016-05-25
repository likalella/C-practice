#include <stdio.h>
#include <float.h>
int main(void){
	printf("FLT_MIN : %g\n", FLT_MIN);
	printf("FLT_MAX : %g\n", FLT_MAX);
	printf("FLT_DIG : %d\n", FLT_DIG);
	printf("DBL_MIN : %g\n", DBL_MIN);
	printf("DBL_MAX : %g\n", DBL_MAX);
	printf("DBL_DIG : %d\n", DBL_DIG);
	printf("LDBL_MIN : %Lg\n", LDBL_MIN);
	printf("LDBL_MAX : %Lg\n", LDBL_MAX);
	printf("LDBL_DIG : %d\n", LDBL_DIG);
	return 0;
}

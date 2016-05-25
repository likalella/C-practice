#include <stdio.h>
#include <limits.h>
int main(void)
{
		printf("CHAR_MIN : %d\n", CHAR_MIN);
		printf("CHAR_MAX : %d\n", CHAR_MAX);
		printf("SCHAR_MIN : %d\n", SCHAR_MIN);
		printf("SCHAR_MAX : %d\n", SCHAR_MAX);
		printf("UCHAR_MAX : %d\n", UCHAR_MAX);
		printf("SHRT_MIN : %d\n", SHRT_MIN);
		printf("SHRT_MAX : %d\n", SHRT_MAX);
		printf("USHRT_MAX : %d\n", USHRT_MAX);
		printf("INT_MIN : %d\n", INT_MIN);
		printf("INT_MAX : %d\n", INT_MAX);
		printf("UINT_MAX : %lu\n", UINT_MAX);
		printf("LONG_MIN : %lu\n", LONG_MIN);
		printf("LONG_MAX : %lu\n", LONG_MAX);
		printf("ULONG_MAX : %llu\n", ULONG_MAX);
		printf("LLONG_MIN : %lld\n", LLONG_MIN);
		printf("LLONG_MAX : %lld\n", LLONG_MAX);
		printf("ULLONG_MAX : %llu\n", ULLONG_MAX);
		return 0;
}

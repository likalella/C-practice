#include <stdio.h>
int my_strlen(char str[])
{
		int num=0;
		while(str[num]!='\0')
				num++;
		return num;
}

int main(void)
{
		char str[]={"hello world!"};
		printf("글자수 길이 : %d\n",my_strlen(str));
		return 0;
}

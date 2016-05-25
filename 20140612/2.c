#include<stdio.h>
void my_strcpy(char str1[], char str2[])
{
		int i;
		for(i=0; i<20; i++)
		{
				str1[i]=str2[i];
				if(str2[i]=='\0')
						return;
		}
}
int main(void)
{	
		char str1[20];
		char str2[] = "C program";
		int i;

		printf("함수실행 전\n");
		printf("str2 : %s\n", str2);

		my_strcpy(str1, str2);
		
		printf("함수실행 후\n");
		printf("str2 : %s\n", str2);
		printf("str1 : %s\n", str1);
		return 0;	
}

#include <stdio.h>
#include <string.h>
int circular(char str[], int strlen)
{
		int cir=1;
		int i=0;
		for(i=0; i<strlen/2; i++)
		{
				if(str[i]!=str[strlen-i-1])
				{		
						cir=0;
						break;
				}
		}

		return cir;
}

int main(void)
{
		int len=0;
		int cir=0;
		char str[1000]={'\0'};
		printf("문장을 입력해주세요 : ");
		scanf("%s", &str);
		len=strlen(str);
		if(circular(str,len)==0)
				printf("%s는 회문이 아닙니다.\n",str);
		else
				printf("%s는 회문입니다.\n",str);
		return 0;	

}

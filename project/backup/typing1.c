#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void mode1();
void mode2();
void mode3();
void mode4();
int main(void)
{
		int mode=0;
		while(1)
		{
				system("clear");
				printf(">> 영문 타자 연습 프로그램 <<\n");
				printf("1. 자리 연습\t2. 낱말 연습\n");
				printf("3. 짧은 글 연습\t4. 긴 글 연습\n");
				printf("5. 프로그램 종료\n\n");
				printf("번호를 선택하세요: ");
				scanf("%d",&mode);

				system("clear");

				if(mode==1)	// 자리 연습
				{
						mode1();
				}
				else if(mode==2)	// 낱말 연습
				{
				}
				else if(mode==3)	// 짧은 글 연습
				{
				}
				else if(mode==4)	// 긴 글 연습
				{
				}
				else if(mode==5)	//프로그램 종료
				{
						system("clear");
						break;
				}
		}
		return 0;
}

void mode1()
{

}

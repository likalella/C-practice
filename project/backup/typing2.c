#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <termios.h>

// 함수 선언부
void mode1();
void mode2();
void mode3();
void mode4();
int getch(void)
{
		int ch;
		struct termios buf;
		struct termios save;
		tcgetattr(0, &save);
		buf=save;
		buf.c_lflag &= ~(ICANON|ECHO);
		buf.c_cc[VMIN]=1;
		buf.c_cc[VTIME]=0;
		tcsetattr(0, TCSAFLUSH, &buf);
		ch=getchar();
		tcsetattr(0, TCSAFLUSH, &save);
		return ch;
}

// 메인함수
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

				if(mode==1)	// 자리 연습
				{
						while(getchar()!='\n');//버퍼를 비워준다.
							mode1();
				}
				else if(mode==2)	// 낱말 연습
				{
						mode2();
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
						return 0;	
				}
		}
}

void mode1()
{
	srand(time(NULL));
	
	// 배열 및 변수 선언부	
	int pro=0, err=0, que=0, ans=0, acc=100;
	//pro 진행도, err 오타수, que 문제선택, ans 입력 값 저장
	char alph[52]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxuz"};
	
	// 자리연습 구현 부분
	que=rand()%52;	// 문제 만들기

	while(pro<20)
	{
			system("clear");
			printf(">> 영문 타자 연습 프로그램 : 자리연습 <<\n");
			printf("진행도 : %d%%\t 오타수 : %d\t 정확도 : %d%%", pro*5, err, acc);
			printf("\n\n");
			printf("%c\n",alph[que]);
			ans=getch();
			if(ans==27) //ESC 눌렀을 경우
			{
					break;
			}		
			else if(alph[que]==ans) // 정답을 입력했을 경우
			{
					pro++;
					que=rand()%52;
					acc=100/(pro+err)*pro;
					if(pro==20)	// 20개 다 맞은 경우
					{
						sleep(1);
						getchar();
					}
			}
			else	// 오답을 입력한 경우
			{
					err++;
					acc=100/(pro+err)*pro;
			}
	}
}

void mode2()
{
		srand(time(NULL));
		// 배열 및 변수 선언부
		//단어 100개 (왠만한 단어가 20글자 보다 작으므로...)
		char word[100][20] = 
			{{"apple"},{"adventure"},{"lovely"},{"happiness"},{"remember"},{"throb"},{"amazing"},{"eternally"},{"hug"},{"computer"},
					{"defense"},{"sweet"},{"delicious"},{"passion"},{"twilight"},{"destiny"},{"friendship"},{"fresh"},{"appointment"},{"magic"},
					{"admire"},{"applaud"},{"comfortable"},{"freedom"},{"charming"},{"effort"},{"service"},{"polite"},{"angel"},{"heaven"},
					{"central"},{"powerful"},{"frozen"},{"spring"},{"wedding"},{"couple"},{"exactly"},{"realize"},{"blossom"},{"share"},
					{"conversation"},{"interview"},{"congratulation"},{"sorrow"},{"coffee"},{"professor"},{"wizard"},{"lucky"},{"frankly"},{"active"},
					{"curious"},{"progress"},{"basic"},{"depend"},{"excitement"},{"design"},{"various"},{"youth"},{"whenever"},{"maybe"},
					{"pretty"},{"responsible"},{"company"},{"right"},{"alright"},{"letter"},{"summer"},{"autumn"},{"keep"},{"proposal"},
					{"baseball"},{"character"},{"natural"},{"try"},{"something"},{"star"},{"please"},{"because"},{"stay"},{"beautiful"},
					{"wonderful"},{"life"},{"without"},{"everything"},{"winter"},{"windy"},{"between"},{"flower"},{"famous"},{"husband"},
					{"princess"},{"dance"},{"photo"},{"diary"},{"bible"},{"always"},{"tomorrow"},{"present"},{"hacking"},{"likalella"}};
		//int ans[20];	//입력 받은 값
		int pro=0, err=0, que=0, acc=100, i=0, check=0;
		//pro 진행도, err 오타수, que 문제선택, acc 정확도
		
		//낱말연습 구현 부분
		while(pro<20)
		{
		  char ans[20];
			check=0;	
			system("clear");
			printf(">> 영문 타자 연습 프로그램 : 낱말 연습 <<");
			printf("진행도 : %d%%\t 오타수 : %d\t 정확도 : %d%%\n",pro*5, err, acc);
			printf("\n");
			que=rand()%100;
			printf("%s\n",word[que]);
			scanf("%s",ans);
			
			for(i=0; i<20; i++)
			{

					if(word[que][i] != ans[i]) // 오타가 났을 경우
					{
							printf("오타!\n");
							check++;
							break;
					}
					if(word[que][i] == 0|| ans[i] == 0)
							break;
			}

			if(check!=0)
					err++;
			pro++;
		}
				
}

void mode3()
{
}

void mode4()
{
}

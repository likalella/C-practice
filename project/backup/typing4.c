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
						mode3();
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
	int pro=0, err=0, que=0, ans=0, end=0;
	float acc=100;
	//pro 진행도, err 오타수, que 문제선택, ans 입력 값 저장, end 종료시enter확인
	char alph[52]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxuz"};
	
	// 자리연습 구현 부분
	que=rand()%52;	// 문제 만들기

	while(pro<20)
	{
			system("clear");
			printf(">> 영문 타자 연습 프로그램 : 자리연습 <<\n");
			printf("진행도 : %d%%\t 오타수 : %d\t 정확도 : %d%%", pro*5, err, (int)acc);
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
					acc=pro*100/(err+pro);
			}
			else	// 오답을 입력한 경우
			{
					err++;
					acc=pro*100/(err+pro);
			}
	}
					if(pro==20)	// 20개 다 맞은 경우
					{
						system("clear");
						printf(">> 영문 타자 연습 프로그램 : 자리연습 <<\n");
						printf("진행도 : %d%%\t 오타수 : %d\t 정확도 : %d%%", pro*5, err, (int)acc);
						printf("\n\n");
						printf("Enter를 누르면 메뉴로 복귀합니다.\n");
						while(1)
						{
							end=getchar();
							if(end==10)
									break;
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
		int pro=0, err=0, que=0, i=0, end=0;
		float acc=100;
		//pro 진행도, err 오타수, que 문제선택, acc 정확도, end 종료시enter확인
		
		//낱말연습 구현 부분
		while(pro<20)
		{
		  char ans[20]={' '}; // 답 입력받을 배열
			system("clear");
			printf(">> 영문 타자 연습 프로그램 : 낱말 연습 <<\n");
			printf("진행도 : %d%%\t 오타수 : %d\t 정확도 : %d%%\n",pro*5, err, (int)acc);
			printf("\n");
			que=rand()%100; // 문제 생성
			printf("%s\n",word[que]); //문제 출력
			scanf("%s",ans); // 답입력받기

			if(ans[0]=='#' && ans[1]=='#' && ans[2]=='#')
					break;
			
			for(i=0; i<20; i++)
			{
					if(word[que][i] != ans[i]) // 오타가 발생했을 경우
					{
							err++;
							break;
					}
					if(word[que][i] == 0 && ans[i] == 0) // 모두 공백일 경우(더이상 비교 의미 없음)
							break;
			}

			pro++; // 진행도 증가
			acc=(pro-err)*100/pro; // 정확도 변경
		}
		if(pro==20)
		{
			system("clear");
			printf(">> 영문 타자 연습 프로그램 : 낱말 연습 <<\n");
			printf("진행도 : %d%%\t 오타수 : %d\t 정확도 : %d%%\n",pro*5, err, (int)acc);
			printf("\n\n");
			printf("Enter를 누르면 메뉴로 복귀합니다.\n");
			while(getchar()!='\n');
			while(1)
			{
				end=getchar();
				if(end==10)
					break;
			}
		}
		
}

void mode3()
{ 
		srand(time(NULL));
		//배열 및 변수 선언부
		//짧은 문장 30개(왠만한 문장이 100글자를 넘기지 않으므로..)
		char sentence[30][100]=
		{
				{"Love is merely madness."},{"Hate the sin, love the sinner."},
				{"If you would be loved, love and be lovable."},{"We can only learn to love by loving."},
				{"To love is to receive a glimpse of heaven."},{"Only I can change my life. No one can do it for me."},
				{"Life is a long lesson in humility."},{"All Bibles are man-made."},
				{"Children are all foreigners."},{"Seek not every quality in one individual."},
				{"Nothing succeeds like the appearance of success."},{"Eighty percent of success is showing up."},
				{"A friend is a second self."},{"United we stand, divided we fall."},
				{"This book fills a much-needed gap."},{"Live always in the best company when you read."},
				{"Only in the agony of parting do we look into the depths of love."},{"Man's feelings are always purest and most glowing in the hour of meeting and of farewell."},
				{"Regret for wasted time is more wasted time."},{"Study the past if you would define the future."},
				{"The Bible promises no loaves to the loafer."},{"What is written without effort is in general read without pleasure."},
				{"Hope is a waking dream."},{"While there's life, there's hope."},
				{"Hope is only the love of life."},{"The journey is the reward."},
				{"Wheresoever you go, go with all your heart."},{"Paradise is where I am."},
				{"Concentration comes out of a combination of confidence and hunger."},{"If I have lost confidence in myself, I have the universe against me."}
		};
		
		int pro=0, que=0, now=0, best=0, err=0, end=0, i=0;
		float acc=100;
		time_t start=0, finish=0;
		// pro 진행도, que 문제선택, now 현재타수, best 최고타수, err 오타, end 메인복귀확인
		// acc 정확도,
		// start 시작시간, end 끝시간

		while(pro<5)
		{
				char ans[100]={' '}; // 답 입력받을 배열
				system("clear");
				printf(">> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n");
				printf("진행도 : %d%%\t 현재타수 : %d\t 최고타수 : %d\t 정확도 : %d%%", pro*20, now, best, (int)acc);
				printf("\n\n");
				que=rand()%30; // 문제생성
				printf("%s", sentence[que]);
		}
}

void mode4()
{
}

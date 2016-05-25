#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <termios.h>
#include <time.h>

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

				while(getchar()!='\n'); //버퍼를 비워준다.
				
				if(mode==1)	// 자리 연습
				{
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
						mode4();	
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
						sleep(2);
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
		  char ans[20]={'\0'}; // 답 입력받을 배열
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
			sleep(2);
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
		
		int pro=0, que=0, now=0, best=0, end=0, byte=0, right=0, i=0;
		char input=' ';
		char ans[100]={'\0'}; // 답 입력받을 배열
		float acc=100;
		time_t start=0, finish=0;
		// pro 진행도, que 문제선택, now 현재타수, best 최고타수, end 메인복귀확인, byte 입력한 글자수, right 맞은 글자수
		// acc 정확도,
		// start 시작시간, finish 끝시간

		que=rand()%30;
		
		//짧은 글 연습 구현 부분
		while(pro<5)
		{
				system("clear");
				printf(">> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n");
				printf("진행도 : %d%%\t 현재타수 : %d\t 최고타수 : %d\t 정확도 : %d%%\n\n", pro*20, now, best, (int)acc);
				printf("%s\n", sentence[que]); //문제 출력
				printf("%s", ans);
				input=getch();
				
				//입력받은 값 처리
				if(input==27)	// esc
					return;
				else if(input==10) // enter
				{
						pro++;
					 	if(pro==5)
							break;	
						que=rand()%30; 
						
						//초기화
						now=0;
						start=0;
						finish=0;
						right=0;
						byte=0;
						acc=100;

						for(i=0; i<100; i++)
							ans[i]='\0';

				}
				else if(input == 127) //backspace
				{
						if(byte>0)
						{
							byte--;
							if(sentence[que][byte]==ans[byte])//right 하나 줄여주기
									right--;
							ans[byte]='\0';
						}
				}
				else
				{
						ans[byte]=input;
						if(sentence[que][byte]==ans[byte])
								++right;
						byte++;
				}

				//타수
				if(start==0)
						start=time(NULL);
				else
						finish=time(NULL);

				if(finish-start>0)
						now=right*60/(finish-start);
				
				//최고타수
				if(best<now)
						best=now;
						
				//정확도		
				if(byte!=0) 
					acc=right*100/byte;
				else
						acc=100;
		}	
			system("clear");
			printf(">> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n");
			printf("진행도 : %d%%\t 현재타수 : %d\t 최고타수 : %d\t 정확도 : %d%%\n\n", pro*20, now, best, (int)acc);
			sleep(2);
			printf("Enter를 누르면 메뉴로 복귀합니다.\n");
			while(1)
			{
				end=getchar();
				if(end==10)
					break;
			}
}

void mode4()
{
		srand(time(NULL));
		//배열 및 변수 선언 부분
		//긴글 4개/10줄/100자미만
		char doc[4][10][100]={
				{"My Favorite Things","Raindrops on roses and whiskers on kittens","Bright copper kettles and warm woolen mittens","Brown paper packages tied up with strings","Cream colored ponies and crisp apple strudels","Doorbells and sleigh bells and schnitzel with noodles","Wild geese that fly with the moon on their wings","These are a few of my favorite things","When the dog bites, when the bee stings, when I'm feeling sad","I simply remember my favorite things and then I don't feel so bad"},
				{"A whole new world","A new fantastic point of view","No one to tell us no","Or where to go","Or say we're only dreaming","A whole new world","A dazzling place I never knew","But when I'm way up here","It's crystal clear","That now I'm in a whole new world with you"},
				{"My one and only love","You fill my eager heart with such desire.","Every kiss you give sets my soul on fire.","I give myself in sweet surrender,","My one and only love","The blush on your cheek whenever I speak","Tells me that you are my own","You fill my eager heart with such desire","Every kiss you give sets my soul on fire","I give myself in sweet surrender"},
				{"LaLaLa... Love Song","Just when I thought it was fate","More than once fate was surely dealyed","Then you came Certain as the rain","Pouring down on me love's destiny","A simple song, Plays in my memory","In the morning sun I take it with my toast and tea","Who'd a thought that I love whould suddenly","Sing to me happily La di di","With a heart that is filled with love"}};

	int par=0, now=0, que=0, end=0, byte=0, right=0, i=0, j=0, k=0;
	char input='\0';
	char ans[10][100]={'\0'};
	float acc=100;
	time_t start=0, finish=0;
	//now 현재타수, que 문제선택, byte 입력한 글자수, right 맞은 글자수
	// acc 정확도
	// 
	que=rand()%4;
	
	while(1)
	{
		system("clear");
		printf(">> 영문 타자 연습 프로그램 : 긴 글 연습 <<\n");
		printf("정확도 : %d%%\t 현재타수 : %d", (int)acc, now);
		printf("\n\n");
		
		if(par<5)
		{
			for(k=0; k<5; k++)
					printf("%s\n", doc[que][k]);
	
			printf("\n\n");
	
			for(k=0; k<par; k++)
					printf("%s\n", ans[k]);
			for(k=0; ans[par][k]!='\0'; k++)
					printf("%c", ans[par][k]);
		}
		else
		{
				for(k=5; k<10; k++)
						printf("%s\n", doc[que][k]);

				printf("\n\n");

				for(k=5; k<par; k++)
						printf("%s\n", ans[k]);
				for(k=0; ans[par][k]!='\0'; k++)
						printf("%c", ans[par][k]);
		}

		input = getch();
		
		//입력받은 값 처리
		if(input == 27) // esc
				return;
		else if(input == 10) // enter
		{
			for(;doc[que][par][i]!='\0';i++)
				byte++;	
			i=0;	
			par++;
		}
		else if(input == 127) //backspace
		{
				if(i>0)
				{
						byte--;
						i--;
						if(doc[que][par][i]==ans[par][i])
								right--;
						ans[par][i]='\0';
				}
		}
		else
		{
				ans[par][i]=input;
				byte++;
				if(doc[que][par][i]==ans[par][i])
						right ++;
				i++;
		}

		//타수
		if(start==0)
				start=time(NULL);
		else
				finish=time(NULL);

		if(finish-start>0)
				now=right*60/(finish-start);

		//정확도
		if(byte!=0)
				acc=right*100/byte;
		else
				acc=100;

		if(par==10)
				break;
	}
	if(par==10)
	{
		system("clear");
		printf(">> 영문 타자 연습 프로그램 : 긴 글 연습 <<\n");
		printf("정확도 : %d%%\t 현재타수 : %d", (int)acc, now);
		printf("\n\n");
		sleep(2);
		printf("Enter를 누르면 메뉴로 복귀합니다.\n");
		while(1)
		{
			end=getchar();
			if(end==10)
				break;
		}
			
	}
}

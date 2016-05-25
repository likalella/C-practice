#include <stdio.h>
#include <termio.h>
void cho1(int a)
{
		printf("\n\n\n\n\n  입력번호 %d번 : 사과\n", a-'0');
}

void cho2(int input_char)
{
		printf("\n\n\n\n\n  입력번호 %d번 : 파인애플\n", input_char-'0');
}

void cho3(int input_char)
{
		printf("\n\n\n\n\n  입력번호 %d번 : 오랜지\n", input_char-'0');
}

void cho4(int input_char)
{
		printf("\n\n\n\n\n  입력번호 %d번 : 바나나\n", input_char-'0');
}

void cho5(int input_char)
{
		printf("\n\n\n\n\n  입력번호 %d번 : 끝\n", input_char-'0');
}

void cho(int input_char)
{
		printf("\n\n\n\n\n  입력번호 %d번 : 입력오류\n", input_char-'0');
}

int getch(void)
{
		int ch;
		struct termios buf;
		struct termios save;

		tcgetattr(0, &save);
		buf = save;

		buf.c_lflag&=~(ICANON|ECHO);
		buf.c_cc[VMIN] = 1;
		buf.c_cc[VTIME] = 0;

		tcsetattr(0, TCSAFLUSH, &buf);

		ch = getchar();

		tcsetattr(0, TCSAFLUSH, &save);

		return ch;
}

int main(void)
{
		int input_char, check=1;
		system("clear");
		while(check)
		{
				printf("**********************************\n");
				printf("*       M    E    N     U        *\n");
				printf("*    1. Apple    2. Pineapple    *\n");
				printf("*    3. Orange   4. Banana       *\n");
				printf("*    5.End                       *\n");
				printf("*                                *\n");
				printf("**********************************\n");
				printf("Select a Menu : ");
				input_char=getch();
				putchar(input_char);
				system("clear");
				switch(input_char)
				{
						case '1':
								cho1(input_char);
								break;
						case '2':
								cho2(input_char);
								break;
						case '3':
								cho3(input_char);
								break;
						case '4':
								cho4(input_char);
								break;
						case '5':
								cho5(input_char);
								check=0;
								break;
						default:
								cho(input_char);
								break;
				}
				printf("\n아무 키나 입력하세요 : ");
				getch();
				system("clear");
		}
		return 0;
}

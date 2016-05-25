#include <stdio.h>
#include <termio.h>
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
								printf("\n\n\n\n\n  입력번호 %d번 : 사과\n", input_char-'0');
								break;
						case '2':
								printf("\n\n\n\n\n  입력번호 %d번 : 파인애플\n", input_char-'0');
								break;
						case '3':
								printf("\n\n\n\n\n  입력번호 %d번 : 오렌지\n", input_char-'0');
								break;
						case '4':
								printf("\n\n\n\n\n  입력번호 %d번 : 바나나\n", input_char-'0');
								break;
						case '5':
								printf("\n\n\n\n\n  입력번호 %d번 : 끝\n", input_char-'0');
								check=0;
								break;
						default:
								printf("\n\n\n\n\n  입력번호 %d번 : 입력오류\n", input_char-'0');
								break;
				}
				printf("\n아무 키나 입력하세요 : ");
				getch();
				system("clear");
		}
		return 0;
}

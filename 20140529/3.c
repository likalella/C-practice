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
		int input_char, i=0, num=0;

		while(i<10)
		{
				printf("Type a letter : ");
				input_char=getch();
				printf("%c\n", input_char);
				if(input_char == 'g')
						num++;
				i++;
		}
		
		printf("'g'입력 횟수 : %d번\n",num);
		printf("빈도 : %.1f", (float)num/10);

		return 0;
}

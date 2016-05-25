#include <stdio.h>
int main(void)
{
		int c, total_byte=0, line_count=0;
	  int	a_count=0, num_count=0, b_count=0;
		
		while ((c=getchar())!= EOF){
			total_byte++;
			if (c == '\n')
					++line_count;
			if ((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
					++a_count;
			if(c>='0'&&c<='9')
					++num_count;
			if(c==' ')
					++b_count;
		}
		
		printf("file size : %d byte \n", total_byte);
		printf("line size : %d lines \n", line_count);
		printf("alphabet size : %d \n", a_count);
		printf("num size : %d \n", num_count);
		printf("blank size : %d \n", b_count);
			
		return 0;
}

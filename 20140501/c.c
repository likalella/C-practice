#include <stdio.h>
int main(void)
{
		int n=0, i=0, total_e=0, total_o=0;
		printf("Input n : ");
		scanf("%d", &n);
		while(i<=n){
			if(n<0)
			break;
			if(i%2==0)	
					total_e+=i;
			else
					total_o+=i;
			i++;
		}	
		if(n<0)
				printf("Error : Input negative number! \n");
		else{
				printf("Total even : %d \n",total_e);	
				printf("Total odd : %d \n",total_o);
		}	
}

#include<stdio.h>
int yun(int year);
int main(void)
{
		int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		int year=0, mon=0, total=0;
		int i=0;
		
		printf("input year : ");
		scanf("%d",&year);
		printf("input month : ");
		scanf("%d",&mon);
		
		total=(year-1)*365; // 전년까지 날짜수
		
		//윤년체크
		for(i=1; i<year; i++)
				total+=yun(i);

		// 그해의 지난 달 날짜
		for(i=1; i<mon; i++)
			total += month[i-1];

		//그해에 윤달이 지났는지 체크
		if(mon>2)
				total+=yun(year);
		
		switch((total+1)%7)
		{
				case 0 :
					printf("%d년 %d월 1일은 일요일입니다.",year,mon);
					break;
				case 1 :
					printf("%d년 %d월 1일은 월요일입니다.",year,mon);
					break;
				case 2 :
					printf("%d년 %d월 1일은 화요일입니다.",year,mon);
					break;
				case 3 :
					printf("%d년 %d월 1일은 수요일입니다.",year,mon);
					break;
				case 4 :
					printf("%d년 %d월 1일은 목요일입니다.",year,mon);
					break;
				case 5 :
					printf("%d년 %d월 1일은 금요일입니다.",year,mon);
					break;
				case 6 :
					printf("%d년 %d월 1일은 토요일입니다.",year,mon);
					break;
					
		}
		return 0;

}
int yun(int year)
{
		int a=0;
		if(year%4)
			a=0;
		else
				if(year%100)
					a=1;
				else
						if(year%400)
								a=0;
						else
								a=1;
		return a;
}

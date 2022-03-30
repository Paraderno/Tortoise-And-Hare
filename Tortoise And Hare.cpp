#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
const int Distance=40; 
int Tortoise=1,Hare=1;
void GameBegin()
{
	printf("BANG!!!\n");
	printf("AND THEY'RE OFF\n");
} 
void print()
{
	int i;
	for(i=1;i<=Distance;i++)
	{
		if(Tortoise==i)
		{
			if(Tortoise==Hare)
				printf("OUCH!!!\n");
			else printf("T\n");
		}
		else if(Hare==i) printf("H\n");
		else printf("[]\n");
	}
	Sleep(500);
	system("cls");
}
void Move_Tortoise()
{
	int x;
	x=rand()%10+1;
	if(x<=5) Tortoise+=3;
	else if(x<=7) Tortoise-=6;
	else if(x<=10) Tortoise+=1;
	if(Tortoise<1) Tortoise=1;
	if(Tortoise>Distance) Tortoise=Distance;
}
void Move_Hare()
{
	int x;
	x=rand()%10+1;
	if(x<=2) Hare+=0;
	else if(x<=4) Hare+=9;
	else if(x<=5) Hare-=12;
	else if(x<=8) Hare+=1;
	else if(x<=10) Hare-=2;
	if(Hare<1) Hare=1;
	if(Hare>Distance) Hare=Distance;
} 
void GameOver()
{
	if(Tortoise==Distance&&Hare==Distance)
		printf("It's a tie\n");
	else if(Tortoise==Distance)
		printf("TORTOISE WINS!!! YAY!!!\n");
	else printf("Hare wins.Yuch\n");
}
int main()
{
	srand(time(0));
	GameBegin(); 
	while(1)
	{
		print(); 
		if(Tortoise>=Distance||Hare>=Distance) break;
		Move_Tortoise();
		Move_Hare();
	}
	GameOver(); 
	return 0;
}

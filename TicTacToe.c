#include<stdio.h>
#include<stdlib.h>

char a[9] = { '1','2','3','4','5','6','7','8','9' };
int k = 0, end = 1,count=0;
void edges(void)
{
	printf("\n\t\t  %c | %c | %c", a[0],a[1],a[2]);
	printf("\n\t\t ---|---|---");
	printf("\n\t\t  %c | %c | %c", a[3], a[4], a[5]);
	printf("\n\t\t ---|---|---");
	printf("\n\t\t  %c | %c | %c", a[6], a[7], a[8]);
}
void choice()
{
	char ch;
	printf("\n Enter the Position: ");
	scanf_s("%c", &ch);
	if (k == 0)
	{
		for (int i = 0; i <= 8; i++)
		{
			if (a[i] == ch)
			{
				a[i] = 'X';
				k = 1;
				count++;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i <= 8; i++)
		{
			if (a[i] == ch)
			{
				a[i] = 'O';
				k = 0;
				count++;
				break;
			}
		}
	}
}
int game_end()
{
	if (a[0] == 'X' && a[1] == 'X' && a[2] == 'X')
		return(1);
	else if (a[0] == 'X' && a[3] == 'X' && a[6] == 'X')
		return(1);
	else if (a[0] == 'X' && a[4] == 'X' && a[8] == 'X')
		return(1);
	else if (a[1] == 'X' && a[4] == 'X' && a[7] == 'X')
		return(1);
	else if (a[2] == 'X' && a[5] == 'X' && a[8] == 'X')
		return(1);
	else if (a[2] == 'X' && a[4] == 'X' && a[6] == 'X')
		return(1);
	else if (a[3] == 'X' && a[4] == 'X' && a[5] == 'X')
		return(1);
	else if (a[6] == 'X' && a[7] == 'X' && a[8] == 'X')
		return(1);

	else if (a[0] == 'O' && a[1] == 'O' && a[2] == 'O')
		return(2);
	else if (a[0] == 'O' && a[3] == 'O' && a[6] == 'O')
		return(2);
	else if (a[0] == 'O' && a[4] == 'O' && a[8] == 'O')
		return(2);
	else if (a[1] == 'O' && a[4] == 'O' && a[7] == 'O')
		return(2);
	else if (a[2] == 'O' && a[5] == 'O' && a[8] == 'O')
		return(2);
	else if (a[2] == 'O' && a[4] == 'O' && a[6] == 'O')
		return(2);
	else if (a[3] == 'O' && a[4] == 'O' && a[5] == 'O')
		return(2);
	else if (a[6] == 'O' && a[7] == 'O' && a[8] == 'O')
		return(2);
	else
		return(3);
}
void winner()
{
	int var;
	var = game_end();
	if (var == 1)
	{
		printf("\n Player 1 wins....");
		end = 0;
	}
	else if (var == 2)
	{
		printf("\n Player 2 wins....");
		end = 0;
	}
	else if (count == 9)
	{
		printf("\n ___Draw___");
		end = 0;
	}
}
void main(void)
{
	char c;
	again:
	system("cls");
	edges();
	count = 0;
	while (end)
	{
		choice();
		system("cls");
		edges();
		winner();
	} 
	printf("\n Do you want to play again?");
	printf("\n Press Y/y to start the game again, Press any key to exit.");
	fflush(stdin);
	scanf_s(" %c", &c);
	if (c == 'y' || c == 'Y')
	{
		a[0] = '1'; a[1] = '2'; a[2] = '3'; a[3] = '4';
		a[4] = '5'; a[5] = '6'; a[6] = '7'; a[7] = '8'; a[8] = '9';
		k = 0; end = 1;
		goto again;
	}
	printf("\n\n ___Thank You___");
} 

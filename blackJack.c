
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAX_VERTICES   50

#pragma warning(disable:4996)


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(int *Card);
void cardSet(int *DealerC, int *PlayerC, int *Card);
int gameStart(int *DealerC, int *PlayerC);
int cardPrt(int *Card, int *i, int *Aa);
void GameFinish(int gameSet);


void main()
{
	int Card[52];
	int DealerC[10], PlayerC[10];
	int gameSet = 0, i = 0;

	while (1)
	{
		init(Card);
		cardSet(DealerC, PlayerC, Card);
		gameSet = gameStart(DealerC, PlayerC);
		GameFinish(gameSet);

		printf("\n\nOne More 1 / Game Exit 2  :: ");
		scanf("%d", &i);

		if (i == 2)
		{
			printf("Thanks.\n");
			break;
		}
		else if (i != 1) {
			printf("reTry.\n");
			printf("\n\nOne More 1 / Game Exit 2  :: ");
			scanf("%d", &i);
		}

		system("cls");

	}

}

void init(int *Card)
{
	// ī�� ���� ����
	int w = 0, r = 0;
	int swit[52];

	for (int i = 0; i < 52; i++) {
		swit[i] = false;
	}

	srand(time(NULL));
	while (w < 52) {
		r = rand() % 52;
		if (swit[r] == false) {
			swit[r] = true;
			Card[w] = r + 1;
			w++;
		}
	}
}

void cardSet(int *DealerC, int *PlayerC, int *Card)
{
	for (int i = 0; i < 10; i++)
	{
		DealerC[i] = Card[i];
		PlayerC[i] = Card[i + 10];
	}

}

int gameStart(int *DealerC, int *PlayerC)
{
	int i = 0, d = 0;
	int Aa = 0, Ab = 0, gg = 0; // A������ A�� ������ 1 ������ 0
	int HS, Cnt = 2, Dsum = 0, Psum = 0;
	int GameSet = -1;

	//gmae start

	printf("Black Jack Start !\n");


	//player card open start

	printf("Player Card Open !!\n");
	Psum = Psum + cardPrt(PlayerC, &i, &Aa);
	Psum = Psum + cardPrt(PlayerC, &i, &Aa);

	while (1) {
		printf("\nHit(1) or Stay(2) :: ");
		scanf("%d", &HS);

		if (HS == 1)
		{
			for (int j = 0; j < Cnt; ) cardPrt(PlayerC, &j, &gg);

			Psum = Psum + cardPrt(PlayerC, &i, &Aa);
			Cnt++;



			if (Aa == 1 && Psum > 21) {
				Psum = Psum - 10; // A�� �ְ� 21�� ������ -10;
				Aa = 0;
			}

			if (Psum == 21) {
				GameSet = 1;
				printf("\n///////////////////\nPlayer Black Jack\n///////////////////\n");
				break;
			}

			if (Psum > 21)
			{
				GameSet = -1;
				break;
			}



		}
		else { break; }  // if hs == stay break;

	}


	//Dealer card open start.



	printf("\n\n\nDealer Card Open !!\n");
	Dsum = Dsum + cardPrt(DealerC, &d, &Ab);
	Dsum = Dsum + cardPrt(DealerC, &d, &Ab);

	if (Dsum < Psum && Psum <= 21) {
		Dsum = Dsum + cardPrt(DealerC, &d, &Ab);
		if (Dsum > 21) GameSet = 1;
	}

	if (Ab == 1 && Dsum > 21) {
		Dsum = Dsum - 10; // A�� �ְ� 21�� ������ -10;
		Ab = 0;
	}

	if (Dsum == 21) {
		printf("\n///////////////////\nDealer Black Jack\n///////////////////\n");
		GameSet = -1;
	}


	// win or lose or drow

	if (Psum == Dsum) GameSet = 0;
	if (Psum > Dsum && Psum <= 21) GameSet = 1;


	return GameSet;
}


int cardPrt(int *Card, int *i, int *Aa)
{
	int pattern, num, Snum;

	pattern = (Card[*i] - 1) / 13;

	switch (pattern) {
		case 0:
			printf("�� ");
			break;
		case 1:
			printf("�� ");
			break;
		case 2:
			printf("�� ");
			break;
		case 3:
			printf("�� ");
			break;
	}

	//���� �� ���ĺ� ����
	num = (Card[*i] - 1) % 13;

	switch (num) {
		case 0:
			printf("A \t");
			Snum = 11;
			*Aa = 1;
			break;
		case 10:
			printf("J \t");
			Snum = 10;
			break;
		case 11:
			printf("Q \t");
			Snum = 10;
			break;
		case 12:
			printf("K \t");
			Snum = 10;
			break;
		default:
			printf("%d \t", num + 1);
			Snum = num + 1;
	}

	*i = *i + 1;

	return Snum;

}


void GameFinish(int gameSet)
{
	if (gameSet == 1)
	{
		printf("\n\n//////////////\n");
		printf("Player Win !!!\n");
		printf("//////////////\n\n");
	}
	else if (gameSet == -1)
	{
		printf("\n\n//////////////\n");
		printf("Player Lose !!!\n");
		printf("//////////////\n\n");
	}
	else
	{
		printf("\n\n//////////////\n");
		printf("Player Drow !!!\n");
		printf("//////////////\n\n");
	}

}

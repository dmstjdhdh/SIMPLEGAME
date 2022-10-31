#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int shuff(int cards[])
{

	int t;
	int i;
	int desk[52];
	for (i = 0; i < 52; i++)
		desk[i] = (i / 13 + 3) * 100 + i % 13 + 1;

	srand(time(NULL));
	for (i = 0; i < 52; i++)
	{
		do
		{
			t = rand() % 52;
		} while (desk[t] == 0);
		cards[i] = desk[t];
		desk[t] = 0;
	}

	return 0;
}

int convert_jkq(int a)
{
	if ((a % 100 == 11) || (a % 100 == 12) || (a % 100 == 13)) return (a / 100) * 100 + 10;
	else return a;
}

void pic(int num)
{
	char fl;
	int po_num;

	fl = num / 100;
	po_num = num % 100;
	switch (po_num)
	{
	case 1:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+   A  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}
	case 2:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+   2  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}
	case 3:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+   3  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}
	case 4:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+   4  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}
	case 5:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+   5  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}
	case 6:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+   6  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}
	case 7:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+   7  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}
	case 8:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+   8  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}
	case 9:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+   9  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}
	case 10:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+  10  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}
	case 11:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+   J  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}
	case 12:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+   Q  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}
	case 13:
	{
		printf("++++++++\n");
		printf("+      +\n");
		printf("+      +\n");
		printf("+   K  +   %c\n", fl);
		printf("+      +\n");
		printf("+      +\n");
		printf("++++++++\n");
		break;
	}

	}
}

int play(void)
{
	int i;
	int psum = 0;
	int psum2 = 0;
	int bsum = 0;
	int pcards[5] = { 0 };
	int pcards2[5] = { 0 };
	int bcards[5] = { 0 };
	int cards[52];
	int cards2[52];
	char go_on;
	char d;

	printf("블랙잭게임입니다.\n"
		"엔터를 누르고 게임을 시작해주세요!!\n");
	do {
		go_on = getchar();
	} while (go_on != '\n');
	printf("\n");

	//shuff the cards
	shuff(cards);
	shuff(cards2);

	//give the cards
	pcards[0] = cards[0];
	pcards[1] = cards[1];
	pcards2[0] = cards2[0];
	pcards2[1] = cards2[1];
	bcards[0] = cards[2];
	bcards[1] = cards[3];

	//the 2 cards player get
	printf("One of computer's cards:\n");
	pic(bcards[0]);
	printf("\n");
	printf("Cards of player1:\n");
	pic(pcards[0]);
	pic(pcards[1]);
	printf("Cards of player2:\n");
	pic(pcards2[0]);
	pic(pcards2[1]);
	i = 0;
	for (i = 0; i < 2; i++)
	{
		if (pcards[i] % 100 == 1)
		{
			printf("player 1의 A카드의 값을 정해주세요 %d, y를 치면 11 n을 치면 1 입니다.:\n", i + 1);
			do {
				d = getchar();
			} while (d != 'y' && d != 'n');

			if (d == 'y')
			{
				psum = psum + 11;
			}
			else if (d == 'n')
			{
				psum = psum + 1;
			}
		}
		else if (convert_jkq(pcards[i]) % 100 == 10) psum = psum + 10;
		else psum = psum + pcards[i] % 100;

	}
	for (i = 0; i < 2; i++)
	{
		if (pcards2[i] % 100 == 1)
		{
			printf("player 2의 A카드의 값을 정해주세요 %d, y를 치면 11 n을 치면 1 입니다.:\n", i + 1);
			do {
				d = getchar();
			} while (d != 'y' && d != 'n');

			if (d == 'y')
			{
				psum2 = psum2 + 11;
			}
			else if (d == 'n')
			{
				psum2 = psum2 + 1;
			}
		}
		else if (convert_jkq(pcards2[i]) % 100 == 10) psum2 = psum2 + 10;
		else psum2 = psum2 + pcards2[i] % 100;
	}
	if (psum > 21 && psum2 < 21)
	{
		printf("플레이어 1의 카드 숫자가%d입니다!!\n\n", psum);
		printf("딜러의 승입니다!!\n");
		return 1;
	}
	else if (psum2 > 21 && psum < 21)
	{
		printf("플레이어 2의 카드 숫자가%d입니다!!\n\n", psum2);
		printf("딜러의 승입니자!!\n");
		return 1;
	}
	else if (psum == 21 && psum2 != 21)
	{
		printf("21입니다!! 플레이어 1의 승리입니다!!\n\n");
		return 0;
	}
	else if (psum2 > 21 && psum > 21)
	{
		printf("플레이어 1과 2의 카드 숫자가 %d, %d 입니다!\n\n", psum, psum2);
		printf("딜러의 승입니다!!\n");
		return 1;
	}
	else if (psum2 == 21 && psum != 21)
	{
		printf("21입니다!! 플레이어 2의 승리입니다!!\n\n");
		return 0;
	}
	else if (psum2 == 21 && psum == 21)
	{
		printf("두 플레이어 모두 21입니다!!\n\n");
		return 0;
	}
	printf("플레이어1의 카드는 %d입니다\n\n", psum);
	printf("플레이어2의 카드는 %d입니다.\n\n", psum2);

	i = 0;
	for (i = 0; i < 3; i++)
	{
		char j = 'n';

		printf("플레이어 1님, 카드를 더 받으시길 원하신다면, y, 아니면 n을 입력해주세요.\n");
		do {
			j = getchar();
		} while (j != 'y' && j != 'n');

		if (j == 'y')
		{
			pcards[i + 2] = cards[i + 4];
			printf("당신의 카드는\n");
			pic(pcards[i + 2]);

			if (pcards[i + 2] % 100 == 1)
			{
				printf("player 1의 A카드의 값을 정해주세요 %d, y를 치면 11 n을 치면 1 입니다.:\n", i + 1);
				do {
					d = getchar();
				} while (d != 'y' && d != 'n');

				if (d == 'y')
				{
					psum = psum + 11;
				}
				else if (d == 'n')
				{
					psum = psum + 1;
				}
			}
			else if (convert_jkq(pcards[i + 2]) % 100 == 10) psum = psum + 10;
			else psum = psum + pcards[i + 2] % 100;
		}
		else
		{
			printf("플레이어1의 카드 합은%d입니다.\n\n", psum);
			break;
		}
	}
	for (i = 0; i < 3; i++)
	{
		char j = 'n';

		printf("플레이어 1님, 카드를 더 받으시길 원하신다면, y, 아니면 n을 입력해주세요.\n");
		do {
			j = getchar();
		} while (j != 'y' && j != 'n');

		if (j == 'y')
		{
			pcards2[i + 2] = cards[i + 10];
			printf("당신의 카드는\n");
			pic(pcards2[i + 2]);

			if (pcards2[i + 2] % 100 == 1)
			{
				printf("player 2의 A카드의 값을 정해주세요 %d, y를 치면 11 n을 치면 1 입니다.:\n", i + 1);
				do {
					d = getchar();
				} while (d != 'y' && d != 'n');

				if (d == 'y')
				{
					psum2 = psum2 + 11;
				}
				else if (d == 'n')
				{
					psum2 = psum2 + 1;
				}
			}
			else if (convert_jkq(pcards2[i + 2]) % 100 == 10) psum2 = psum2 + 10;
			else psum2 = psum2 + pcards2[i + 2] % 100;
		}
		else
		{
			printf("플레이어2의 카드 합은%d입니다.\n\n", psum);
			break;
		}
	}
	if (psum > 21 && psum2 < 21)
	{
		printf("플레이어 1의 카드 숫자가%d입니다!!\n\n", psum);
		printf("딜러의 승입니다!!\n");
		return 1;
	}
	else if (psum2 > 21 && psum < 21)
	{
		printf("플레이어 2의 카드 숫자가%d입니다!!\n\n", psum2);
		printf("딜러의 승입니자!!\n");
		return 1;
	}
	else if (psum2 > 21 && psum > 21)
	{
		printf("플레이어 1과 2의 카드 숫자가 %d, %d 입니다!\n\n", psum, psum2);
		printf("딜러의 승입니다!!\n");
		return 1;
	}
	else if (psum == 21 && psum2 != 21)
	{
		printf("21입니다!! 플레이어 1의 승리입니다!!\n\n");
		return 0;
	}
	else if (psum2 == 21 && psum != 21)
	{
		printf("21입니다!! 플레이어 2의 승리입니다!!\n\n");
		return 0;
	}
	else if (psum2 == 21 && psum == 21)
	{
		printf("두 플레이어 모두 21입니다!!\n\n");
		return 0;
	}
	printf("플레이어1의 카드는 %d입니다\n\n", psum);
	printf("플레이어2의 카드는 %d입니다.\n\n", psum2);

	//the 2 cards of boss/computer
	//i=0;
	printf("딜러의 카드는 이러합니다.\n");
	pic(bcards[0]);
	pic(bcards[1]);

	if (bcards[0] % 100 + bcards[1] % 100 == 2)
	{
		bsum = 12;
		printf("딜러의 카드는 지금 %d입니다.\n\n", bsum);
	}
	else if ((convert_jkq(bcards[0])) % 100 + (convert_jkq(bcards[1])) % 100 == 1)
	{
		bsum = 21;
		printf("딜러의 카드가%d로, 딜러의 블랙잭 승리입니다!\n\n", bsum);
		return 1;
	}
	else if (bcards[0] % 100 == 1 || bcards[1] % 100 == 1)
	{
		bsum = (bcards[0] + bcards[1]) % 100 + (rand() % 2) * 10;
		printf("딜러의 카드는%d입니다!!\n\n", bsum);
	}
	else
	{
		bsum = (convert_jkq(bcards[0])) % 100 + (convert_jkq(bcards[1])) % 100;
		printf("딜러의 카드는 %d입니다!!%d\n\n", bsum);
	}

	for (i = 0; i < 3 && bsum < 17; i++)
	{
		bcards[i + 2] = cards[i + 7];
		printf("딜러가 카드를 더 받습니다. 딜러의 카드입니다.\n");
		pic(bcards[i + 2]);

		if (bcards[i + 2] % 100 == 1)
		{
			if (bsum + 11 <= 21)
			{
				bsum = bsum + 11;
				printf("딜러의 카드 합은%d입니다.\n\n", bsum);
			}
			else
			{
				bsum = bsum + 1;
				printf("딜러의 카드 합은%d입니다.\n\n", bsum);
			}
		}
		else
		{
			bsum = bsum + convert_jkq(bcards[i + 2]) % 100;
			printf("딜러의 카드 합은%d입니다.\n\n", bsum);
		}
	}

	//the last step

	if (bsum > 21)
	{
		if (psum > psum2)
		{
			printf("플레이어 1의 승리입니다!!\n");
		}
		else if (psum2 > psum)
		{
			printf("플레이어 2의 승리입니다!!\n");
		}
		else if (psum == psum2)
		{
			printf("플레이어 1과 2의 동점승입니다!!\n");
		}
	}
	else if (bsum < 21)
	{
		if (psum > 21)
		{
			if (bsum > psum2)
			{
				printf("딜러의 승리입니다!!\n");
			}
			else if (psum2 > bsum)
			{
				printf("플레이어 2의 승리입니다!!\n");
			}
			else if (bsum == psum2)
			{
				printf("딜러와 플레이어2의 동점승입니다!!\n");
			}
		}
		else if (psum < 21)
		{
			if (psum2 > 21)
			{
				if (bsum > psum)
				{
					printf("딜러의 승리입니다!!\n");
				}
				else if (psum > bsum)
				{
					printf("플레이어 1의 승리입니다!!\n");
				}
				else if (bsum == psum)
				{
					printf("딜러와 플레이어1의 동점승입니다!!\n");
				}
			}
			else if (psum2 < 21)
			{
				if (psum > bsum && psum > psum2)
				{
					printf("플레이어 1의 승리입니다!\n");
				}
				else if (psum2 > bsum && psum2 > psum)
				{
					printf("플레이어 2의 승리입니다!\n");
				}
				else if (bsum > psum && bsum > psum2)
				{
					printf(" 딜러의 승리입니다!!\n");
				}
				else if (psum == bsum && psum2 == bsum)
				{
					printf("모두 동점입니다!!\n");
				}
				else if (psum == bsum && psum > psum2)
				{
					printf("플에이어 1과 딜러의 동점승입니다!!\n");
				}
				else if (psum == psum2 && psum > bsum)
				{
					printf("플에이어 1과 플레이어2의 동점승입니다!!\n");
				}
				else if (bsum == psum2 && psum2 > psum)
				{
					printf("플에이어 2과 딜러의 동점승입니다!!\n");
				}
			}
		}
	}
	return 3;
}

int main(void)
{
	char again;

	play();

	printf("\n게임을 다시 시작하시겠습니까? Enter y or n\n");
	do {
		again = getchar();
	} while (again != 'y' && again != 'n');

	if (again == 'y')
	{
		printf("\nOK, let's go again!\n\n");
		main();
	}

	return 0;
}
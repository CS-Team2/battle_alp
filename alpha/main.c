#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*typedef struct {
	char name[32];
	int life, attack, magic;
}param;*/

struct param
{
	char name[8];
	int life, attack, magic;
};

void act(struct param* actor, struct param* target, int command1)
{
	int point;
		switch (command1)
		{
		case 0:
			point = actor->attack;
			target->life -= point;
			break;
		case 1:
			point = rand() % 6 + 1;
			target->life -= (actor->attack + point);
			break;
		case 2:
			point = 50;
			actor->life += point;
			break;
		}
}



int GetRandom(int min, int max);

int main(void)
{
	printf("Alphatest\n");
	int battle_loop = 0;
	float win;
	float lose;
	float judge;
	int command;
	int command1;
	printf("(0) CS武器無\n(1) MS武器無\n(2) BS武器無\n(3) CS武器1あり\n(4) MS武器1あり\n(5) BS武器1あり\n(7) CS武器2あり\n(8) MS武器2あり\n(9) BS武器2あり\n(10) CS武器3あり\n(11) MS武器3あり\n(12) BS武器3あり\n");
	printf("Command:");
	scanf("%d", &command);
	if (command == 0)
	{
		struct param you = { "CS学生", 75,20,10 };
		struct param enemy = { "教授", 50,5,0 };
		printf("%s: Life = %d, Attack = %d, magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("CS武器なしで敵との戦闘\n");
		win = 0;
		lose = 0;
		while (battle_loop < 10) {
			for (;;) {
				if (you.life > 25 || enemy.life <= you.attack)
				{
					command1 = 0;
				}
				else if (you.life <= 25 && enemy.life > you.attack) {
					command1 = 2;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					battle_loop += 1;
					win += 1;
					break;
				}
				act(&enemy, &you, 0);
				if (you.life <= 0)
				{
					battle_loop += 1;
					lose += 1;
					break;
				}
			}
		}
		judge = (win / (win + lose)) * 100;
		printf("winning_percentage%.2f%%\n", judge);
		return 0;
	}
	/*else if (command == 1)
	{
		param you = { "MS学生", 125,10,5 };
		param enemy = { "教授", 50,5,0 };
		printf("%s: Life = %d, Attack = %d, magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
	}
	else if (command == 2)
	{
		param you = { "BS学生", 100,5,40 };
		param enemy = { "教授", 50,5,0 };
		printf("%s: Life = %d, Attack = %d, magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
	}
	else if (command == 3)
	{
		param you = { "CS学生1", 75,25,15 };
		param enemy = { "教授", 50,5,0 };
		printf("%s: Life = %d, Attack = %d, magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
	}
	else if (command == 4)
	{
		param you = { "MS学生1", 125,15,10 };
		param enemy = { "教授", 50,5,0 };
		printf("%s: Life = %d, Attack = %d, magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
	}
	else if (command == 5)
	{
		param you = { "BS学生1", 100,10,45 };
		param enemy = { "教授", 50,5,0 };
		printf("%s: Life = %d, Attack = %d, magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
	}
	if (command < 0 || command > 5)
	{
		printf("0~25のコマンドを入力\n");

	}*/

}

int GetRandom(int min, int max)
{
	srand((unsigned int)time(NULL));

	return rand() % 4;
}
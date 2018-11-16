#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
		point = (actor->attack) + (rand() % 6 + 1);
		target->life -= point;
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
	printf("(0) CS武器無\n(1) MS武器無\n(2) BS武器無\n(3) CS武器1あり\n(4) MS武器1あり\n(5) BS武器1あり\n(6) CS武器2あり\n(7) MS武器2あり\n(8) BS武器2あり\n(9) CS武器3あり\n(10) MS武器3あり\n(11) BS武器3あり\n(12) CS武器1ボス\n");
	printf("(13) MS武器1ボス\n(14) BS武器1ボス\n(15) CS武器2ボス\n(16) MS武器2ボス\n(17) BS武器2ボス\n(18) CS武器3ボス\n(19) MS武器3ボス\n(20) BS武器3ボス\n(99) end\n");
	printf("Command:");
	scanf("%d", &command);
	if (command == 0)
	{
		struct param you = { "CS学生", 75,20,10 };
		struct param enemy = { "MOB", 50,5,0 };
		printf("%s: Life = %d, Attack = %d, magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("CS武器なしで戦うことのできる道中最強の敵との戦闘\n");
		win = 0;
		lose = 0;
		while (battle_loop < 10) {
			struct param you = { "CS学生", 75,20,10 };
			struct param enemy = { "MOB", 50,5,0 };
			for (;;) {
				if ((you.life <= enemy.attack + 6) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					battle_loop += 1;
					win += 1;
					break;
				}

				if (enemy.magic >= 2 && rand() % 3 == 0) {
					command = 1;
					enemy.magic -= 2;
				}
				else{
					command = 0;
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
		printf("winning percentage:%.2f%%\n", judge);
		return main();
	}

	if (command == 99) {
		return 0;
	}
	else if (command < 0 || command > 5)
	{
		printf("0~25のコマンドを入力してください\n");
		return main();
	}
}

int GetRandom(int min, int max)
{
	srand((unsigned int)time(NULL));

	return rand() % 4;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//主人公と敵ステータスの構造体
struct param
{
	char name[8];
	int life, attack, magic;
};

//乱数の取得
int GetRandom(int min, int max)
{
	return min + (int)(rand()*(max - min + 1.0) / (1.0 + RAND_MAX));
}

//主人公と敵の行動
void act(struct param* actor, struct param* target, int command1)
{
	int point;
	switch (command1)
	{
		//通常攻撃
	case 0:
		point = actor->attack;
		target->life -= point;
		break;
		
		//CS,MS,MOB,BOSS(弱魔法)の魔法攻撃
	case 1:
		point = (actor->attack) + (GetRandom(1,6));
		target->life -= point;
		break;

		//回復
	case 2:
		point = 50;
		actor->life += point;
		break;

		//BS,BOSS(強魔法)の魔法攻撃
	case 3:
		point = (actor->attack) + (GetRandom(2, 12));
		target->life -= point;
		break;
	}
}


int main(void)
{
	printf("Alpha_test\n");
	int battle_loop = 1000;
	int loop_count = 0;
	float win = 0;
	float lose = 0;
	float judge;
	char inputline[100];
	int command;
	int command1;
	srand((unsigned)time(NULL));
	printf("(0) CS武器無\n(1) MS武器無\n(2) BS武器無\n(3) CS武器1あり\n(4) MS武器1あり\n(5) BS武器1あり\n(6) CS武器2あり\n(7) MS武器2あり\n(8) BS武器2あり\n(9) CS武器3あり\n(10) MS武器3あり\n(11) BS武器3あり\n(12) CS武器1ボス\n");
	printf("(13) MS武器1ボス\n(14) BS武器1ボス\n(15) CS武器2ボス\n(16) MS武器2ボス\n(17) BS武器2ボス\n(18) CS武器3ボス\n(19) MS武器3ボス\n(20) BS武器3ボス\n(99) 終了\n");
	printf("Command:");
	if (fgets(inputline, sizeof inputline, stdin) != NULL) {
		sscanf_s(inputline, "%d", &command);
	}
	else {
		printf("0~25または99の数値を入力してください\n");
		return main();
	}

	//CS武器無し
	if (command == 0)
	{
		struct param you = { "CS学生", 75,20,10 };
		struct param enemy = { "敵2-2", 50,5,0 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("CS武器なしで戦うことのできる道中最強の敵との戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "CS学生", 75,20,10 };
			struct param enemy = { "敵2-2", 50,5,0 };
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
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					command1 = 1;
					enemy.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//MS武器無し
	else if (command == 1) {
		struct param you = { "MS学生", 125,10,5 };
		struct param enemy = { "敵2-2", 50,5,0 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("MS武器なしで戦うことのできる道中最強の敵との戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "MS学生", 125,10,5 };
			struct param enemy = { "敵2-2", 50,5,0 };
			for (;;) {
				if ((you.life <= enemy.attack + 6) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if ((enemy.life > you.attack) && (enemy.life <= you.attack + 6) && (you.magic >= 2)) {
					command1 = 1;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					command1 = 1;
					enemy.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//BS武器無し
	else if (command == 2) {
		struct param you = { "BS学生", 100,5,40 };
		struct param enemy = { "敵2-2", 50,5,0 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("BS武器なしで戦うことのできる道中最強の敵との戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "BS学生", 100,5,40 };
			struct param enemy = { "敵2-2", 50,5,0 };
			for (;;) {
				if ((you.life <= enemy.attack + 6) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if (((you.magic >= 2) && (enemy.life > you.attack * 2)) || ((you.magic >= 2) && (enemy.life <= you.attack + 12) && (enemy.life > you.attack))) {
					command1 = 3;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if (enemy.magic >= 2 && GetRandom(0, 2) == 0) {
					command1 = 1;
					enemy.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//CS武器1あり
	else if (command == 3) {
		struct param you = { "CS学生1", 75,25,15 };
		struct param enemy = { "敵4-4", 125,15,6 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("CS武器1ありで戦うことのできる道中最強の敵との戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "CS学生1", 75,25,15 };
			struct param enemy = { "敵4-4", 125,15,6 };
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
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					command1 = 1;
					enemy.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//MS武器1あり
	else if (command == 4) {
		struct param you = { "MS学生1", 125,15,10 };
		struct param enemy = { "敵4-4", 125,15,6 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("MS武器1ありで戦うことのできる道中最強の敵との戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "MS学生1", 125,15,10 };
			struct param enemy = { "敵4-4", 125,15,6 };
			for (;;) {
				if ((you.life <= enemy.attack + 6) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if ((enemy.life > you.attack) && (enemy.life <= you.attack + 6) && (you.magic >= 2)) {
					command1 = 1;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					command1 = 1;
					enemy.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//BS武器1あり
	else if (command == 5) {
		struct param you = { "BS学生1", 100,10,45 };
		struct param enemy = { "敵4-4", 125,15,6 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("BS武器1ありで戦うことのできる道中最強の敵との戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "BS学生1", 100,10,45 };
			struct param enemy = { "敵4-4", 125,15,6 };
			for (;;) {
				if ((you.life <= enemy.attack + 6) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if (((you.magic >= 2) && (enemy.life > you.attack * 2)) || ((you.magic >= 2) && (enemy.life <= you.attack + 12) && (enemy.life > you.attack))) {
					command1 = 3;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if (enemy.magic >= 2 && GetRandom(0, 2) == 0) {
					command1 = 1;
					enemy.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//CS武器2あり
	else if (command == 6) {
		struct param you = { "CS学生2", 75,30,20 };
		struct param enemy = { "敵4-4", 125,15,6 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("CS武器2ありで戦うことのできる道中最強の敵との戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "CS学生2", 75,30,20 };
			struct param enemy = { "敵4-4", 125,15,6 };
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
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					command1 = 1;
					enemy.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//MS武器2あり
	else if (command == 7) {
		struct param you = { "MS学生2", 125,20,15 };
		struct param enemy = { "敵4-4", 125,15,6 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("MS武器2ありで戦うことのできる道中最強の敵との戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "MS学生2", 125,20,15 };
			struct param enemy = { "敵4-4", 125,15,6 };
			for (;;) {
				if ((you.life <= enemy.attack + 6) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if ((enemy.life > you.attack) && (enemy.life <= you.attack + 6) && (you.magic >= 2)) {
					command1 = 1;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					command1 = 1;
					enemy.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//BS武器2あり
	else if (command == 8) {
		struct param you = { "BS学生2", 100,15,50 };
		struct param enemy = { "敵4-4", 125,15,6 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("BS武器2ありで戦うことのできる道中最強の敵との戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "BS学生2", 100,15,50 };
			struct param enemy = { "敵4-4", 125,15,6 };
			for (;;) {
				if ((you.life <= enemy.attack + 6) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if (((you.magic >= 2) && (enemy.life > you.attack * 2)) || ((you.magic >= 2) && (enemy.life <= you.attack + 12) && (enemy.life > you.attack))) {
					command1 = 3;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if (enemy.magic >= 2 && GetRandom(0, 2) == 0) {
					command1 = 1;
					enemy.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//CS武器3あり
	else if (command == 9) {
		struct param you = { "CS学生3", 75,35,25 };
		struct param enemy = { "敵4-4", 125,15,6 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("CS武器3ありで戦うことのできる道中最強の敵との戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "CS学生3", 75,35,25 };
			struct param enemy = { "敵4-4", 125,15,6 };
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
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					command1 = 1;
					enemy.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//MS武器3あり
	else if (command == 10) {
		struct param you = { "MS学生3", 125,25,20 };
		struct param enemy = { "敵4-4", 125,15,6 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("MS武器3ありで戦うことのできる道中最強の敵との戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "MS学生3", 125,25,20 };
			struct param enemy = { "敵4-4", 125,15,6 };
			for (;;) {
				if ((you.life <= enemy.attack + 6) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if ((enemy.life > you.attack) && (enemy.life <= you.attack + 6) && (you.magic >= 2)) {
					command1 = 1;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					command1 = 1;
					enemy.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//BS武器3あり
	else if (command == 11) {
		struct param you = { "BS学生3", 100,20,55 };
		struct param enemy = { "敵4-4", 125,15,6 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("BS武器3ありで戦うことのできる道中最強の敵との戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "BS学生3", 100,20,55 };
			struct param enemy = { "敵4-4", 125,15,6 };
			for (;;) {
				if ((you.life <= enemy.attack + 6) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if (((you.magic >= 2) && (enemy.life > you.attack * 2)) || ((you.magic >= 2) && (enemy.life <= you.attack + 12) && (enemy.life > you.attack))) {
					command1 = 3;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if (enemy.magic >= 2 && GetRandom(0, 2) == 0) {
					command1 = 1;
					enemy.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//CS武器1BOSS
	else if (command == 12) {
		struct param you = { "CS学生1", 75,25,15 };
		struct param enemy = { "BOSS", 150,15,8 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("CS武器1ありでBOSSとの戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "CS学生1", 75,25,15 };
			struct param enemy = { "BOSS", 150,15,8 };
			for (;;) {
				if ((you.life <= enemy.attack + 12) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (you.life > 75) {
					you.life = 75;
				}
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					if (GetRandom(0, 1) == 0) {
						command = 3;
					}
					else {
						command1 = 1;
						enemy.magic -= 2;
					}
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//MS武器1BOSS
	else if (command == 13) {
		struct param you = { "MS学生1", 125,15,10 };
		struct param enemy = { "BOSS", 150,15,8 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("MS武器1ありでBOSSとの戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "MS学生1", 125,15,10 };
			struct param enemy = { "BOSS", 150,15,8 };
			for (;;) {
				if ((you.life <= enemy.attack + 12) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if ((enemy.life > you.attack) && (enemy.life <= you.attack + 6) && (you.magic >= 2)) {
					command1 = 1;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					if (GetRandom(0, 1) == 0) {
						command = 3;
					}
					else {
						command1 = 1;
						enemy.magic -= 2;
					}
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//BS武器1BOSS
	else if (command == 14) {
		struct param you = { "BS学生1", 100,10,45 };
		struct param enemy = { "BOSS", 150,15,8 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("BS武器1ありでBOSSとの戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "BS学生1", 100,10,45 };
			struct param enemy = { "BOSS", 150,15,8 };
			for (;;) {
				if ((you.life <= enemy.attack + 12) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if (((you.magic >= 2) && (enemy.life > you.attack * 2)) || ((you.magic >= 2) && (enemy.life <= you.attack + 12) && (enemy.life > you.attack))) {
					command1 = 3;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					if (GetRandom(0, 1) == 0) {
						command = 3;
					}
					else {
						command1 = 1;
						enemy.magic -= 2;
					}
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//CS武器2BOSS
	else if (command == 15) {
		struct param you = { "CS学生2", 75,30,20 };
		struct param enemy = { "BOSS", 150,15,8 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("CS武器2ありでBOSSとの戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "CS学生2", 75,30,20 };
			struct param enemy = { "BOSS", 150,15,8 };
			for (;;) {
				if ((you.life <= enemy.attack + 12) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (you.life > 75) {
					you.life = 75;
				}
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					if (GetRandom(0, 1) == 0) {
						command = 3;
					}
					else {
						command1 = 1;
						enemy.magic -= 2;
					}
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//MS武器2BOSS
	else if (command == 16) {
		struct param you = { "MS学生2", 125,20,15 };
		struct param enemy = { "BOSS", 150,15,8 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("MS武器2ありでBOSSとの戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "MS学生2", 125,20,15 };
			struct param enemy = { "BOSS", 150,15,8 };
			for (;;) {
				if ((you.life <= enemy.attack + 12) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if ((enemy.life > you.attack) && (enemy.life <= you.attack + 6) && (you.magic >= 2)) {
					command1 = 1;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					if (GetRandom(0, 1) == 0) {
						command = 3;
					}
					else {
						command1 = 1;
						enemy.magic -= 2;
					}
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//BS武器2BOSS
	else if (command == 17) {
		struct param you = { "BS学生2", 100,15,50 };
		struct param enemy = { "BOSS", 150,15,8 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("BS武器2ありでBOSSとの戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "BS学生2", 100,15,50 };
			struct param enemy = { "BOSS", 150,15,8 };
			for (;;) {
				if ((you.life <= enemy.attack + 12) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if (((you.magic >= 2) && (enemy.life > you.attack * 2)) || ((you.magic >= 2) && (enemy.life <= you.attack + 12) && (enemy.life > you.attack))) {
					command1 = 3;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					if (GetRandom(0, 1) == 0) {
						command = 3;
					}
					else {
						command1 = 1;
						enemy.magic -= 2;
					}
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//CS武器3BOSS
	else if (command == 18) {
		struct param you = { "CS学生3", 75,35,25 };
		struct param enemy = { "BOSS", 150,15,8 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("CS武器3ありでBOSSとの戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "CS学生3", 75,35,25 };
			struct param enemy = { "BOSS", 150,15,8 };
			for (;;) {
				if ((you.life <= enemy.attack + 12) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (you.life > 75) {
					you.life = 75;
				}
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					if (GetRandom(0, 1) == 0) {
						command = 3;
					}
					else {
						command1 = 1;
						enemy.magic -= 2;
					}
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//MS武器3BOSS
	else if (command == 19) {
	struct param you = { "MS学生3", 125,25,20 };
	struct param enemy = { "BOSS", 150,15,8 };
	printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
	printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
	printf("MS武器3ありでBOSSとの戦闘\n");
	while (loop_count < battle_loop) {
		struct param you = { "MS学生3", 125,25,20 };
		struct param enemy = { "BOSS", 150,15,8 };
		for (;;) {
			if ((you.life <= enemy.attack + 6) && (enemy.life > you.attack) && (you.magic >= 3)) {
				command1 = 2;
				you.magic -= 3;
			}
			else if ((enemy.life > you.attack) && (enemy.life <= you.attack + 6) && (you.magic >= 2)) {
				command1 = 1;
				you.magic -= 2;
			}
			else {
				command1 = 0;
			}
			act(&you, &enemy, command1);
			if (enemy.life <= 0)
			{
				loop_count += 1;
				win += 1;
				break;
			}

			if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
				if (GetRandom(0, 1) == 0) {
					command = 3;
				}
				else {
					command1 = 1;
					enemy.magic -= 2;
				}
			}
			else {
				command1 = 0;
			}
			act(&enemy, &you, command1);
			if (you.life <= 0)
			{
				loop_count += 1;
				lose += 1;
				break;
			}
		}
	}
	}

	//BS武器3BOSS
	else if (command == 20) {
		struct param you = { "BS学生3", 100,20,55 };
		struct param enemy = { "BOSS", 150,15,8 };
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life = %d, Attack = %d, Magic = %d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		printf("BS武器3ありでBOSSとの戦闘\n");
		while (loop_count < battle_loop) {
			struct param you = { "BS学生3", 100,20,55 };
			struct param enemy = { "BOSS", 150,15,8 };
			for (;;) {
				if ((you.life <= enemy.attack + 6) && (enemy.life > you.attack) && (you.magic >= 3)) {
					command1 = 2;
					you.magic -= 3;
				}
				else if (((you.magic >= 2) && (enemy.life > you.attack * 2)) || ((you.magic >= 2) && (enemy.life <= you.attack + 12) && (enemy.life > you.attack))) {
					command1 = 3;
					you.magic -= 2;
				}
				else {
					command1 = 0;
				}
				act(&you, &enemy, command1);
				if (enemy.life <= 0)
				{
					loop_count += 1;
					win += 1;
					break;
				}

				if ((enemy.magic >= 2) && (GetRandom(0, 2) == 0)) {
					if (GetRandom(0, 1) == 0) {
						command = 3;
					}
					else {
						command1 = 1;
						enemy.magic -= 2;
					}
				}
				else {
					command1 = 0;
				}
				act(&enemy, &you, command1);
				if (you.life <= 0)
				{
					loop_count += 1;
					lose += 1;
					break;
				}
			}
		}
	}

	//終了
	else if (command == 99) {
		return 0;
	}

	else if (command < 0 || command > 20)
	{
		printf("0~25または99の数値を入力してください\n");
		return main();
	}

	//勝率を出力
	judge = (win / (win + lose)) * 100;
	printf("勝率:%.2f%%\n", judge);
	return main();
}

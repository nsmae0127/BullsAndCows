#include <stdio.h>
#include <stdlib.h>

void StartingScreen();
void MenuOption();
void GameStart();
int* CreateAiNumber();
void ProcessModule(char *name, int* aiNum);

int main(void)
{
	StartingScreen();

	return 0;
}

void StartingScreen()
{
	printf("====================================\n");
	printf("====================================\n");
	printf("          숫자야구 게임 v1.0\n\n");
	printf("                       ⓒ Alvin Lee.\n");
	printf("====================================\n");
	printf("           1. 게임시작\n\n");
	printf("           2. 게임종료\n");
	printf("====================================\n");
	printf("====================================\n");

	MenuOption();
}

void MenuOption()
{
	int menu;

	printf("메뉴를 선택하세요. ");
	scanf_s("%d", &menu);

	switch (menu)
	{
	case 1:
		printf("------------------------------------\n");
		GameStart();
		break;
	case 2:
		exit(-1);
		break;
	default:
		break;
	}
}

void GameStart()
{
	char name[10];

	printf("사용자의 이름을 입력하세요. ");
	scanf_s("%s", name, sizeof(name));
	printf("------------------------------------\n");
	printf("[AI] %s님 반갑습니다.\n", name);
	printf("     게임을 시작하겠습니다.\n");
	printf("------------------------------------\n");
	ProcessModule(name, CreateAiNumber());
}

int* CreateAiNumber() 
{
	int aiNum[3];
	int i;

	for (i = 0; i < 3; i++) {
		aiNum[i] = rand() % 10;		// 0~9사이의 숫자 생성
		printf("%d ", aiNum[i]);
	}

	printf("\n");

	return aiNum;
}

void ProcessModule(char* name, int* aiNum)
{
	int playerNum[3];
	int num, strikeCount, ballCount;
	int i, j;

	while (1) {
		printf("[%s] ", name);
		scanf_s("%d", &num);
		if (num > 999) {	// 세자리수를 넘어가면 경고
			printf("------------------------------------\n");
			printf("[AI] 세자리 숫자로 입력하세요.");
		}

		// 사용자 입력 숫자를 쪼갬
		playerNum[0] = num / 100;
		playerNum[1] = (num % 100) / 10;
		playerNum[2] = (num % 100) % 10;

		printf("%d %d %d\n", playerNum[0], playerNum[1], playerNum[2]);

		// 스트라이크, 볼 카운트 초기화
		strikeCount = 0;
		ballCount = 0;

		// 사용자 입력 숫자와 비교
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (aiNum[i] == playerNum[j]) {		// 동일한 숫자일 경우
					if (i == j)		// 동일한 자리일 경우
						strikeCount++;
					else
						ballCount++;
				}
			}
		}

		// 결과 출력
		printf("------------------------------------\n");
		printf("[AI] %d 스트라이크 %d 볼입니다.\n", strikeCount, ballCount);
		printf("------------------------------------\n");
	}
}
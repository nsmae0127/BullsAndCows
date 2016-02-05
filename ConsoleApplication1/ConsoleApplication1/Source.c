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
	printf("          ���ھ߱� ���� v1.0\n\n");
	printf("                       �� Alvin Lee.\n");
	printf("====================================\n");
	printf("           1. ���ӽ���\n\n");
	printf("           2. ��������\n");
	printf("====================================\n");
	printf("====================================\n");

	MenuOption();
}

void MenuOption()
{
	int menu;

	printf("�޴��� �����ϼ���. ");
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

	printf("������� �̸��� �Է��ϼ���. ");
	scanf_s("%s", name, sizeof(name));
	printf("------------------------------------\n");
	printf("[AI] %s�� �ݰ����ϴ�.\n", name);
	printf("     ������ �����ϰڽ��ϴ�.\n");
	printf("------------------------------------\n");
	ProcessModule(name, CreateAiNumber());
}

int* CreateAiNumber() 
{
	int aiNum[3];
	int i;

	for (i = 0; i < 3; i++) {
		aiNum[i] = rand() % 10;		// 0~9������ ���� ����
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
		if (num > 999) {	// ���ڸ����� �Ѿ�� ���
			printf("------------------------------------\n");
			printf("[AI] ���ڸ� ���ڷ� �Է��ϼ���.");
		}

		// ����� �Է� ���ڸ� �ɰ�
		playerNum[0] = num / 100;
		playerNum[1] = (num % 100) / 10;
		playerNum[2] = (num % 100) % 10;

		printf("%d %d %d\n", playerNum[0], playerNum[1], playerNum[2]);

		// ��Ʈ����ũ, �� ī��Ʈ �ʱ�ȭ
		strikeCount = 0;
		ballCount = 0;

		// ����� �Է� ���ڿ� ��
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (aiNum[i] == playerNum[j]) {		// ������ ������ ���
					if (i == j)		// ������ �ڸ��� ���
						strikeCount++;
					else
						ballCount++;
				}
			}
		}

		// ��� ���
		printf("------------------------------------\n");
		printf("[AI] %d ��Ʈ����ũ %d ���Դϴ�.\n", strikeCount, ballCount);
		printf("------------------------------------\n");
	}
}
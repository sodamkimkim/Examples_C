#include <stdio.h>

int main()
{
	// ���ǹ�(Condition)
	// �б⹮(Branch)
	// if��
	// if (����) ��, ����
	int lhs = 3; // left-hand side
	int rhs = 4; // right-hand side
	if (lhs < rhs)
	{
		printf("True");
	}
	else
	{
		printf("False");
	}

	//
	printf("\n");

	// A < B
	// A <= B
	// A > B
	// A >= B
	// A == B
	// A != B

	int inputValue = 0;
	int coin = 0;
	int reorder = 1;
	printf("coin�Է��ϼ���: ");
	scanf_s("%d", &coin);
	while (coin >= 0) {
		printf("--Vending Machine--\n");
		printf("1.Coke(800) 2.Water(500) 3.Soda(1000) 4.MountainDew(1300)\n");
		scanf_s("%d", &inputValue);

		if (inputValue == 1) {
			if (coin >= 800) {
				printf("Coke�� �����Ͽ����ϴ�.\n");
				printf("coin %d�� ���, %d�� ���ҽ��ϴ�.", 800, coin - 800);
				coin = coin - 800;
			}
			else {
				printf("coin %d�� �����Ͽ� ������ �� �����ϴ�.\n", (coin - 800) * -1);
				printf("���ֹ��Ͻðڽ��ϱ�? yes: 1, no: 2 \n");
				scanf_s("%d", &reorder);
				if (reorder == 1) {
					int recoin = 0;
					int adcoin = 0;
					printf("���� coin: %d��\n", coin);
					printf("coin �� �����ðڽ��ϱ�? yes: 1, no: 2 \n");
					scanf_s("%d", &recoin);
					if (recoin == 1) {
						printf("coin �� ���� �� �Է�\n");
						scanf_s("%d", &adcoin);
						coin += adcoin;
						printf("���� coin: %d��\n", coin);
						continue;
					}
					else {
						continue;
					}
				}
				else {
					break;
				}

			}
		}
		else if (inputValue == 2) {
			if (coin >= 500) {
				printf("Water�� �����Ͽ����ϴ�.\n");
				printf("coin %d�� ���, %d�� ���ҽ��ϴ�.", 500, coin - 500);
				coin = coin - 500;
			}
			else {
				printf("coin %d�� �����Ͽ� ������ �� �����ϴ�.\n", (coin - 500) * -1);
				printf("���ֹ��Ͻðڽ��ϱ�? yes: 1, no: 2 \n");
				scanf_s("%d", &reorder);
				if (reorder == 1) {
					int recoin = 0;
					int adcoin = 0;
					printf("���� coin: %d��\n", coin);
					printf("coin �� �����ðڽ��ϱ�? yes: 1, no: 2 \n");
					scanf_s("%d", &recoin);
					if (recoin == 1) {
						printf("coin �� ���� �� �Է�\n");
						scanf_s("%d", &adcoin);
						coin += adcoin;
						printf("���� coin: %d��\n", coin);
						continue;
					}
					else {
						continue;
					}
				}
				break;

			}
		}
		else if (inputValue == 3) {
			if (coin >= 1000) {
				printf("Soda�� �����Ͽ����ϴ�.\n");
				printf("coin %d�� ���, %d�� ���ҽ��ϴ�.", 1000, coin - 1000);
				coin = coin - 1000;
			}
			else {
				printf("coin %d�� �����Ͽ� ������ �� �����ϴ�.\n", (coin - 1000) * -1);
				printf("���ֹ��Ͻðڽ��ϱ�? yes: 1, no: 2 \n");
				scanf_s("%d", &reorder);
				if (reorder == 1) {
					int recoin = 0;
					int adcoin = 0;
					printf("���� coin: %d��\n", coin);
					printf("coin �� �����ðڽ��ϱ�? yes: 1, no: 2 \n");
					scanf_s("%d", &recoin);
					if (recoin == 1) {
						printf("coin �� ���� �� �Է�\n");
						scanf_s("%d", &adcoin);
						coin += adcoin;
						printf("���� coin: %d��\n", coin);
						continue;
					}
					else {
						continue;
					}

				}
				else {
					break;
				}
			}
		}
		else if (inputValue == 4) {
			if (coin >= 1300) {
				printf("MountainDew�� �����Ͽ����ϴ�.\n");
				printf("coin %d�� ���, %d�� ���ҽ��ϴ�.", 1300, coin - 1300);
				coin = coin - 1300;
			}
			else {
				printf("coin %d�� �����Ͽ� ������ �� �����ϴ�.\n", (coin - 1300) * -1);
				printf("���ֹ��Ͻðڽ��ϱ�? yes: 1, no: 2 \n");
				scanf_s("%d", &reorder);
				if (reorder == 1) {
					int recoin = 0;
					int adcoin = 0;
					printf("���� coin: %d��\n", coin);
					printf("coin �� �����ðڽ��ϱ�? yes: 1, no: 2 \n");
					scanf_s("%d", &recoin);
					if (recoin == 1) {
						printf("coin �� ���� �� �Է�\n");
						scanf_s("%d", &adcoin);
						coin += adcoin;
						printf("���� coin: %d��\n", coin);
						continue;
					}
					else {
						continue;
					}
				}
				else {
					break;
				}
			}
		}
		else {
			printf("����� �Է����ּ���");
		}
		printf("inputValue : %d\n", inputValue);
	}



	//switch��
	int num = 0;
	const int num1 = 1;
	printf("--Vending Machine--\n");
	printf("1.Coke(800) 2.Water(500) 3.Soda(1000) 4.MountainDew(1300)\n");
	scanf_s("%d", &num);

	switch (num)
	{
	case 1 : // ���ͷ� ���(Literal Constant Value)
		printf("coke�̾ҽ��ϴ�.");
		break;

	case 2 :
		printf("water �̾ҽ��ϴ�.");
		break;

	case 3 :
		printf("soda �̾ҽ��ϴ�.");
		break;

	case 4: 
		printf("MountainDew �̾ҽ��ϴ�.");
		break;
	default:

		break;
	}


}

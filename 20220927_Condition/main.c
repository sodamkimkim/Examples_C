#include <stdio.h>

int main()
{
	// 조건문(Condition)
	// 분기문(Branch)
	// if문
	// if (조건) 참, 거짓
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
	printf("coin입력하세요: ");
	scanf_s("%d", &coin);
	while (coin >= 0) {
		printf("--Vending Machine--\n");
		printf("1.Coke(800) 2.Water(500) 3.Soda(1000) 4.MountainDew(1300)\n");
		scanf_s("%d", &inputValue);

		if (inputValue == 1) {
			if (coin >= 800) {
				printf("Coke를 선택하였습니다.\n");
				printf("coin %d원 사용, %d원 남았습니다.", 800, coin - 800);
				coin = coin - 800;
			}
			else {
				printf("coin %d원 부족하여 구매할 수 없습니다.\n", (coin - 800) * -1);
				printf("재주문하시겠습니까? yes: 1, no: 2 \n");
				scanf_s("%d", &reorder);
				if (reorder == 1) {
					int recoin = 0;
					int adcoin = 0;
					printf("현재 coin: %d원\n", coin);
					printf("coin 더 넣으시겠습니까? yes: 1, no: 2 \n");
					scanf_s("%d", &recoin);
					if (recoin == 1) {
						printf("coin 더 넣을 값 입력\n");
						scanf_s("%d", &adcoin);
						coin += adcoin;
						printf("현재 coin: %d원\n", coin);
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
				printf("Water를 선택하였습니다.\n");
				printf("coin %d원 사용, %d원 남았습니다.", 500, coin - 500);
				coin = coin - 500;
			}
			else {
				printf("coin %d원 부족하여 구매할 수 없습니다.\n", (coin - 500) * -1);
				printf("재주문하시겠습니까? yes: 1, no: 2 \n");
				scanf_s("%d", &reorder);
				if (reorder == 1) {
					int recoin = 0;
					int adcoin = 0;
					printf("현재 coin: %d원\n", coin);
					printf("coin 더 넣으시겠습니까? yes: 1, no: 2 \n");
					scanf_s("%d", &recoin);
					if (recoin == 1) {
						printf("coin 더 넣을 값 입력\n");
						scanf_s("%d", &adcoin);
						coin += adcoin;
						printf("현재 coin: %d원\n", coin);
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
				printf("Soda를 선택하였습니다.\n");
				printf("coin %d원 사용, %d원 남았습니다.", 1000, coin - 1000);
				coin = coin - 1000;
			}
			else {
				printf("coin %d원 부족하여 구매할 수 없습니다.\n", (coin - 1000) * -1);
				printf("재주문하시겠습니까? yes: 1, no: 2 \n");
				scanf_s("%d", &reorder);
				if (reorder == 1) {
					int recoin = 0;
					int adcoin = 0;
					printf("현재 coin: %d원\n", coin);
					printf("coin 더 넣으시겠습니까? yes: 1, no: 2 \n");
					scanf_s("%d", &recoin);
					if (recoin == 1) {
						printf("coin 더 넣을 값 입력\n");
						scanf_s("%d", &adcoin);
						coin += adcoin;
						printf("현재 coin: %d원\n", coin);
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
				printf("MountainDew를 선택하였습니다.\n");
				printf("coin %d원 사용, %d원 남았습니다.", 1300, coin - 1300);
				coin = coin - 1300;
			}
			else {
				printf("coin %d원 부족하여 구매할 수 없습니다.\n", (coin - 1300) * -1);
				printf("재주문하시겠습니까? yes: 1, no: 2 \n");
				scanf_s("%d", &reorder);
				if (reorder == 1) {
					int recoin = 0;
					int adcoin = 0;
					printf("현재 coin: %d원\n", coin);
					printf("coin 더 넣으시겠습니까? yes: 1, no: 2 \n");
					scanf_s("%d", &recoin);
					if (recoin == 1) {
						printf("coin 더 넣을 값 입력\n");
						scanf_s("%d", &adcoin);
						coin += adcoin;
						printf("현재 coin: %d원\n", coin);
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
			printf("제대로 입력해주세요");
		}
		printf("inputValue : %d\n", inputValue);
	}



	//switch문
	int num = 0;
	const int num1 = 1;
	printf("--Vending Machine--\n");
	printf("1.Coke(800) 2.Water(500) 3.Soda(1000) 4.MountainDew(1300)\n");
	scanf_s("%d", &num);

	switch (num)
	{
	case 1 : // 리터럴 상수(Literal Constant Value)
		printf("coke뽑았습니다.");
		break;

	case 2 :
		printf("water 뽑았습니다.");
		break;

	case 3 :
		printf("soda 뽑았습니다.");
		break;

	case 4: 
		printf("MountainDew 뽑았습니다.");
		break;
	default:

		break;
	}


}

#include <stdio.h>
int main() {

	int num;
	const int min = -7;
	const int max = 7;

	while (1) {
		printf("음양수판별 숫자 입력하세요( %d ~ %d ): ", min, max);
		scanf_s("%d", &num);

		// 예외처리
		if (num < min || num > max)
		{
			printf("%d ~ %d사이 숫자로 다시 입력해 주세요. (예외처리 from if문)\n", min, max);
			continue;
		}

		if (num >= min && num < 0) {
			printf("음수입니다.\n");
		}
		else if (num >= 0 && num <= max) {
			printf("양수입니다.\n");
		}

		//switch (num)
		//{
		//case -5:
		//case -4:
		//case -3:
		//case -2:
		//case -1:
		//	printf("음수입니다.\n");
		//	break;
		//case 0:
		//case 1:
		//case 2:
		//case 3:
		//case 4:
		//case 5:
		//	printf("양수입니다.\n");
		//	break;
		//default:
		//	printf("-5~5사이의 수를 입력해 주세요.(defalut from switch)\n");
		//	break;
		//} // end of switch
	} // end of while

	return 0;


}
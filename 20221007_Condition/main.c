#include <stdio.h>
int main() {

	int num;
	const int min = -7;
	const int max = 7;

	while (1) {
		printf("������Ǻ� ���� �Է��ϼ���( %d ~ %d ): ", min, max);
		scanf_s("%d", &num);

		// ����ó��
		if (num < min || num > max)
		{
			printf("%d ~ %d���� ���ڷ� �ٽ� �Է��� �ּ���. (����ó�� from if��)\n", min, max);
			continue;
		}

		if (num >= min && num < 0) {
			printf("�����Դϴ�.\n");
		}
		else if (num >= 0 && num <= max) {
			printf("����Դϴ�.\n");
		}

		//switch (num)
		//{
		//case -5:
		//case -4:
		//case -3:
		//case -2:
		//case -1:
		//	printf("�����Դϴ�.\n");
		//	break;
		//case 0:
		//case 1:
		//case 2:
		//case 3:
		//case 4:
		//case 5:
		//	printf("����Դϴ�.\n");
		//	break;
		//default:
		//	printf("-5~5������ ���� �Է��� �ּ���.(defalut from switch)\n");
		//	break;
		//} // end of switch
	} // end of while

	return 0;


}
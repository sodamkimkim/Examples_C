#include <stdio.h>
int main()
{
	int star = 0; // star�� Ŀ����
	int space = 0; // space�� ������ ����
	int step = 0; // while�� �ݺ�Ƚ��
	int i = 0;
	printf("�Ƕ�̵� �� ���� �Է��ϼ���: ");
	scanf_s("%d", &step);
	space = step;

	while (star <= step) // 0 ~ step������ �ݺ�
	{
		if (star <= space) // ���� ��� ����
		{
			printf(" ");
			star++;
		}
		if (star >= space) // * ��� ���� -> step����ŭ�� �ݺ� �߿��� star�� ��� �����ϴٰ� star>=space�Ǵ� �������� *���
			// �׷��ϱ� step - space + 1 ����ŭ(star == space �� ���� *����ϱ� ������ +1) ����ϰԵ�
		{
			printf("* ");
			star++;
		}
		if (star - space > i) // �ٹٲ� ����
		{
			// space�� * ����� star - space > i �˻��ؼ�
			// left�� Ŭ �� \n ����Ѵ�.
			// ���� ���� if�� ����Ǳ� ������ �� ��µȴٰ� ���� �ȴ�.
			printf("\n");
			printf("star: %d\n", star);
			printf("space: %d\n", space);
			printf("star - space: %d\n", star - space);
			printf("i: %d\n", i);
			printf("============\n");
			i++;
			space--; // �� �ٲ� �� space-- ���ش�. => �� ���� ���� ������ 1���� �پ��� �ȴ�. & step������ -- �ȴ�.
			//space--�Ǵٰ� space == 0�Ǿ������ ������ ���α׷� ���� if���� Ÿ�ԵǸ鼭 ������.
			star = 0; 
		}
		if (space <= 0) // ���α׷� ���� ����
		{
			printf("�����ٿ�");
			printf("star: %d\n", star);
			printf("space: %d\n", space);
			printf("star - space: %d\n", star - space);
			printf("i: %d\n", i);
			break;
		}
	}
	return 0;
}
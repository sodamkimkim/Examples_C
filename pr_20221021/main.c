#include <stdio.h>
#include <stdlib.h>
int main() {
	// # 2���� ���� �迭

	// 2���� �����͸� ���� �� �ִ� ���� ������ �ּ��Ҵ�.
	int** ppArr2D = (int**)malloc(sizeof(int*) * 2);

	// ppArr2D + 0byte �ǳʶ� ��ġ�� ���ο� �޸� �ּ� ����
	ppArr2D[0] = (int*)malloc(sizeof(int) * 3);

	// ppArr2D + 4byte �ǳʶ� ��ġ�� ���ο� �޸� �ּ� ����
	*(ppArr2D + 1) = (int*)malloc(sizeof(int) * 3);


	// �� �ٵ� �̷��� �ϸ� [0] ~ [1] ����� �ּҴ� ���� ���Ѵ�.
	// ���ӵǰ� �������� int*6��¥�� �����ϰ� �ּ� ���� �Ҵ��ϴ� ��� ����ؾ� �Ѵ�.
	// �ּ� Ȯ��
	printf("ppArr2D : %p\n", ppArr2D);
	printf("ppArr2D[0] : %p\n", ppArr2D[0]);
	printf("ppArr2D[1] : %p\n", *(ppArr2D + 1));

	// ppArr2D[0]���� 0byte������ ��ġ�� �� ����
	ppArr2D[0][0] = 11;

	// ppArr2D[1]���� 0byte������ ��ġ�� �� ����
	*(*(ppArr2D + 1) + 0) = 21;

	printf("ppArr2D[0][0] : %d (%p) \n", ppArr2D[0][0], &ppArr2D[0][0]);
	printf("*(*(ppArr2D+1)+0): %d (%p)\n", *(*(ppArr2D + 1) + 0), &(*(*(ppArr2D + 1) + 0)));

	// # ������ ������ ����.
// malloc 3�� ������ 3�� �� ���� �� ��� �Ѵ�. 
	for (int i = 0; i < 2; ++i) {
		if (ppArr2D[i] != NULL) {
			free(ppArr2D[i]);
			ppArr2D[i] = NULL;
		}
	}
	if (ppArr2D != NULL) {
		free(ppArr2D);
		ppArr2D = NULL;
	}
	return 0;
}

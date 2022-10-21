#include <stdio.h>
#include <stdlib.h>
int main() {
	// # 2차원 동적 배열

	// 2개의 포인터를 담을 수 있는 공간 생성과 주소할당.
	int** ppArr2D = (int**)malloc(sizeof(int*) * 2);

	// ppArr2D + 0byte 건너뛴 위치에 새로운 메모리 주소 저장
	ppArr2D[0] = (int*)malloc(sizeof(int) * 3);

	// ppArr2D + 4byte 건너뛴 위치에 새로운 메모리 주소 저장
	*(ppArr2D + 1) = (int*)malloc(sizeof(int) * 3);


	// ㄴ 근데 이렇게 하면 [0] ~ [1] 연결된 주소는 갖지 못한다.
	// 연속되게 가지려면 int*6개짜리 선언하고 주소 각각 할당하는 방식 사용해야 한다.
	// 주소 확인
	printf("ppArr2D : %p\n", ppArr2D);
	printf("ppArr2D[0] : %p\n", ppArr2D[0]);
	printf("ppArr2D[1] : %p\n", *(ppArr2D + 1));

	// ppArr2D[0]에서 0byte떨어진 위치에 값 저장
	ppArr2D[0][0] = 11;

	// ppArr2D[1]에서 0byte떨어진 위치에 값 저장
	*(*(ppArr2D + 1) + 0) = 21;

	printf("ppArr2D[0][0] : %d (%p) \n", ppArr2D[0][0], &ppArr2D[0][0]);
	printf("*(*(ppArr2D+1)+0): %d (%p)\n", *(*(ppArr2D + 1) + 0), &(*(*(ppArr2D + 1) + 0)));

	// # 해제는 생성의 역순.
// malloc 3번 했으면 3번 다 해제 해 줘야 한다. 
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

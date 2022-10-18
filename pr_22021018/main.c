#include <stdio.h>
typedef char HP;
typedef struct _SData {
	int i;
	float f;
	HP hp;
	double d; // ********double 위치 한단계 앞으로 해줌
	char mp;
}SData;
int main() {
	SData data;
	data.i = 200;
	data.f = 200.5f;
	data.hp = 5;
	data.mp = 6;
	data.d = 127.5;

	printf("data Address : %p\n", &data);
	printf("data size: %d\n", sizeof(data));
	printf("\n");
	printf("data.i : %d (%p)\n", data.i, &data.i);
	printf("data.f : %.5f (%p)\n", data.f, &data.f);
	printf("data.hp : %d (%p)\n", data.hp, &data.hp);
	printf("data.d : %.5lf (%p)\n", data.d, &data.d);
	printf("data.mp : %d (%p)\n", data.mp, &data.mp);
	return 0;
}

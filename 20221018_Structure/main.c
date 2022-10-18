#include <stdio.h>

typedef char HP; // �⺻ �ڷ����� typedef�� ���ؼ� �ٸ������� �θ� �� �ִ�.
// HP�ڷ����� �ٲ� �̰͸� �ٲٸ� �ȴ�.

// ����ü (Structure) - ����� ���� �ڷ���
typedef struct _SData {

	// ����ü �������(Member Variables)
	// ����� ���ÿ� �ʱ�ȭ�� �Ұ���.
	// ����ü�� �е�(padding)
	// cpu�� ������ 4byte�� �д´�. 
	// �� �ѹ��� ���� �� �ֵ��� ������ �κ��� paddingó���� �ش�.
	int i;
	float f;
	HP hp; // 1byte�ε� 4byte����
	char mp; // 1byte�ε� 4byte���� => �޸� ����
	double d;

	// ����ü�� ������ ��, �е��� ����ؼ� �޸� ���� �ּ�ȭ �� �� �ֵ��� ����.
} SData; // ����ü ��Ī����

//typedef struct _SData SData;

////////////////////////////////////////////////////////////////////////////////////////////
// ����ü(Union)
union UMem
{
	// ����ü�� �޸� ������ ������� �������� ����ϴ� ���̴�.
	// Union�� �޸� ������� ū �� �������� ���´�.
	// �������� ���� �ڷ������� �ٲ� ��µȴ�.
	int i;
	float f;
	char c;
	double d;
};
////////////////////////////////////////////////////////////////////////////////////////////
// ����ü(������, Enumerated Type, Enumeration)
enum EIdx { A, B = 100, C, D, LEN };
enum Anim{ kIdle, kRun, kAttack, kJump, kLen }; // �ִϸ��̼� ����� Ȱ���ϱ�
enum EOption{ // BitFlags�� Ȱ���ϱ�
	FullScreen = 1,
	UseController = 2,
	MouseClick = 4,
	Move = 8
};

void main() {
	//struct _SData data;
	SData data;
	// ' .  '-> ����ü ��� ���� ������(Member Access Operator)
	data.i = 100;
	data.f = 3.14f;
	printf("data.f : %f\n", data.f);

	struct _SData info;
	info.i = 123;
	printf("info.i: %d\n", info.i);

	printf("\n");
	SData sData = { 200, 200.5f, 5,8, 123.5f };
	printf("sData Address: %p\n", &sData);
	printf("sData size: %d byte\n", sizeof(sData));
	printf("\n");
	printf("sData.i : %d (%p)\n", sData.i, &sData.i);
	printf("sData.f : %f (%p)\n", sData.f, &sData.f);
	printf("sData.hp : %d (%p)\n", sData.hp, &sData.hp);
	printf("sData.mp : %d (%p)\n", sData.mp, &sData.mp);
	printf("sData.d : %lf (%p)\n", sData.d, &sData.d);

	////////////////////////////////////////////////////////////////////////
	printf("\n");

	// ����ü �����ϱ�
	SData dataCpy = sData;
	printf("dataCpy.i : %d\n", dataCpy.i);
	printf("dataCpy.d : %lf\n", dataCpy.d);

	////////////////////////////////////////////////////////////////////////
	printf("\n");
	union UMem mem;
	mem.f = 3.14f;
	mem.i = 100;
	mem.d = 3.14;

	printf("mem Size : %d byte\n", sizeof(mem));
	printf("mem Address: %p\n", &mem);
	printf("mem.i : %d (%p)\n", mem.i, &mem.i);
	printf("mem.f : %f (%p)\n", mem.f, &mem.f);
	printf("mem.d : %lf (%p)\n", mem.d, &mem.d);

	////////////////////////////////////////////////////////////////////////
	printf("\n");
	enum EIdx idx;
	printf("idx Size: %d byte\n", sizeof(idx));
	printf("idx Address: %p\n", &idx);

	// ���� �ʱ�ȭ ���� �ʾƵ� 0, 1, 2, 3���� ���� �� �ִ�.
	printf("A: %d\n", A);
	printf("B: %d\n", B);
	printf("C: %d\n", C);
	printf("D: %d\n", D);
	//A = 100; // -> ����ü�� ��Ҵ� ����� �ٲ��� �ʴ´�.

	// switch - case���� ���� ����Ѵ�. (���ͷ� ����� �����߾���)
	idx = A;
	switch (idx)
	{
	case A: printf("idx = A"); break;
	case B: printf("idx = B"); break;
	case C: printf("idx = C"); break;
	defalut: break;
	}

	// �迭���� ����� �����ϴ�. (�迭���� ���ͷ� ����� �����߾���)
	int arr[LEN];
	// arr[HP] = 100; //�̷������� ����ϸ� arr[0]�̷��� ���� �������� ����.
	arr[B] = 100;
	arr[C] = 40;
	
}

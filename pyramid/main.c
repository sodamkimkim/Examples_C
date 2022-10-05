#include <stdio.h>
int main()
{
	int star = 0; // star은 커지고
	int space = 0; // space는 적어질 예정
	int step = 0; // while문 반복횟수
	int i = 0;
	printf("피라미드 층 수를 입력하세요: ");
	scanf_s("%d", &step);
	space = step;

	while (star <= step) // 0 ~ step수까지 반복
	{
		if (star <= space) // 공백 출력 조건
		{
			printf(" ");
			printf("star: %d\n", star);
			printf("space: %d\n", space);
			star++;
		}
		if (star >= space) // * 출력 조건 -> step수만큼의 반복 중에서 star가 계속 증가하다가 star>=space되는 지점에서 *출력
			// 그러니까 step - space + 1 수만큼(star == space 일 때도 *출력하기 때문에 +1) 출력하게됨
		{
			printf("* ");
			star++;
		}
		if (star - space > i) // 줄바꿈 조건
		{
			// space나 * 찍고나서 star - space > i 검사해서
			// left가 클 때만 \n 출력한다.
			// 즉 피라미드 마지막 줄에서는 \n출력 안한다.
			printf("\n");
			//printf("============\n");
			//printf("star - space: %d\n", star - space);
			//printf("i: %d\n", i);
			i++;
			space--; // 줄 바꿀 때 space --해준다. => 그 다음 줄은 공백이 1개씩 줄어들게 된다.
			star = 0; 
		}
		if (space <= 0) // 프로그램 종료 조건
		{
			printf("나간다요");
			break;
		}
	}
	return 0;
}
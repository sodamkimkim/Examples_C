#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char** ps); // 동적 할당 영역의 문자열을 출력하는 함수
int main() {
	char temp[80];
	char* str[21] = { 0 }; // 문자열을 연결한 포인터 배열, 널 포인터로 초기화
	int i = 0;

	while (i < 20) {
		printf("문자열을 입력하세요 : ");
		gets(temp);
		if (strcmp(temp, "end") == 0) break; // end입력되면 반복 종료
		str[i] = (char*)malloc(strlen(temp) + 1); // 문자열 저장 공간 할당
		strcpy_s(str[i], sizeof(temp), temp);
		i++;
	}
	print_str(str);
	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	return 0;
}
void print_str(char** ps) {
	while (*ps != NULL)
	{
		printf("%s, %p\n", *ps, ps);
		ps++; // 포인터 크기만큼 증가
	}
}
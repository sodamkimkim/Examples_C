#include <stdio.h>
//#include <stdlib.h>
struct profile
{
	int age;
	double height;
};

struct student
{
	struct profile pf;
	int id;
	double* grade;
};
int main(void) {
	struct student dami;
	printf("나이 입력: ");
	scanf_s("%d",&dami.pf.age);
	dami.pf.height = 180.5;
	dami.id = 315;
	dami.grade = (double*)malloc(sizeof(double*));
	printf("학점 입력: ");
	scanf_s("%lf", dami.grade);
	printf("\n");
	printf("나이: %d\n", dami.pf.age);
	printf("키: %.1lf\n", dami.pf.height);
	printf("id: %d\n", dami.id);
	printf("학점: %.1lf\n", *dami.grade);
	free(dami.grade);

}
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
	printf("���� �Է�: ");
	scanf_s("%d",&dami.pf.age);
	dami.pf.height = 180.5;
	dami.id = 315;
	dami.grade = (double*)malloc(sizeof(double*));
	printf("���� �Է�: ");
	scanf_s("%lf", dami.grade);
	printf("\n");
	printf("����: %d\n", dami.pf.age);
	printf("Ű: %.1lf\n", dami.pf.height);
	printf("id: %d\n", dami.id);
	printf("����: %.1lf\n", *dami.grade);
	free(dami.grade);

}
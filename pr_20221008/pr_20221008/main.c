#include <stdio.h>
int main()
{
	int* p;
	//int a = 5;
	//p = &a;
	*p = 10;
	printf("%d\n", *p);
}
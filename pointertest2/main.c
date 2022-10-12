#include <stdio.h>
int main() {
	int a = 123;
	int* ptr = &a;
	printf("%X\n", ptr);

	printf("%X\n", --ptr);
	printf("%X\n", ++ptr);
}
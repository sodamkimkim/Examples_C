#include <stdio.h>
int main() {

	int* ptr = 0x1004;
	printf("%X\n", ptr); // 1004
	printf("%X\n", --ptr);
}
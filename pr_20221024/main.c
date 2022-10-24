#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char** ps);
int main() {
	
	return 0;
}
void print_str(char** ps) {
	while (*ps != NULL)
	{
		printf("%s\n", *ps);
		ps++;
	}
}
// Scott Kuhl
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void changeToX(char *str)
{
	*str = 'X'; // change first byte of char to an X
}

int main(void)
{
	// This will work fine, strdup() will malloc some space.
	char *str = strdup("Hello world");
	*str = 'X';
	printf("%s\n", str);
	free(str);

	// This will work fine, the array is initialized with contents of the string.
	char array[] = "Hello world";
	array[0] = 'X';
	printf("%s\n", array);

	// String literals are global and we shouldn't change them. For
	// example, if the same string literal appeared multiple times in
	// your program, the compiler may only put a single global string
	// in your code and refer to that string from multiple places.:
	char *literal = "Hello world";
	// A better way to declare this variable that would reduce the
	// chances of you making a mistake:
	// const char *literal = "Hello world";
	*literal = 'X'; // This WON'T WORK because we are changing the string literal itself!
	printf("%s\n", literal);

	return 0;
}

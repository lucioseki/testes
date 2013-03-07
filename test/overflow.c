#include <stdio.h>
#include <stdlib.h>

int main(){
	char a = 'a';
	size_t size = (size_t) &a;
	char *p;

	p = (char *) malloc(size+1);
	p[size] = 'b';

	printf("%c\n", a);
	return 0;
}

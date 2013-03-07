#include <stdio.h>
#include <string.h>

int main(){
	char *p = "teste";
	// p[0] = 'a'; // invalido

	char q[] = "teste";
	q[0] = 'a';

	printf("%s %s\n", p, q);
	return 0;
}

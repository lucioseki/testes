/* bit field: campos que usam n bits de um tipo */
#include <stdio.h>

typedef long int lint;

struct coiso{
	unsigned short int first:8, second:8;
	lint third:8;
};

struct coisa{
	// coiso fourth:1; // nao permitido
	struct coiso fourth;
};
	
int main(){
	struct coiso coiso;
	coiso.first = 255;
	coiso.second = 255;
	printf("%d\n%d\n", coiso.first, coiso.second);
	printf("sizeof(coiso) = %lu\n", sizeof(coiso));
	return 0;
}

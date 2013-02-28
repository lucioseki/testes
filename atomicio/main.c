/**
* Tenho que aprender como mexe com read() e write()
**/

#include <stdio.h>
#include <unistd.h> // para chamar read() e write()
#include <errno.h> // definicoes de tipo de erro 
#include <fcntl.h> // modo que vai abrir o arquivo

// retorna quantos bytes ler/escrever
// retorna -1 se der erro
// retorna 0 se EOF
ssize_t atomicio(f, fd, _s, n)
	ssize_t (*f)(); // ponteiro pra funcao read() ou write()
	int fd; // arquivo
	void *_s; // buffer
	size_t n; // tamanho do buffer
{
	char *s = _s; // ponteiro pra avacar sobre o buffer
	ssize_t res, // tamanho lido/escrito
					pos = 0; // posicao sendo lido/escrito

	while (n > pos){ // enquanto nao percorrer o arquivo todo
		res = (f)(fd, s + pos, n - pos); // le/escreve quanto couber no buffer
		switch (res) {
			case -1: // deu erro
				#ifdef EWOULDBLOCK
					if (errno == EINTR || errno == EAGAIN || errno == EWOULDBLOCK)
				#else
					if (errno == EINTR || errno == EAGAIN)
				#endif
					continue;
			case 0: // EOF
				return (res);
			default: // leu certinho
				pos += res;
		}
	}
	return (pos);
}

int main(){

	char buff[30];

	ssize_t temp, size = 0;
	ssize_t (*f)(int, void*, size_t); // ponteiro pra read()/write()
	f = &read;

	int fd = open("main.c", S_IRUSR); // read
	while( (temp = atomicio(f, fd, buff, 30)) != 0){
		size += temp;
	}
	close(fd);
	printf("read size: %zd\n", size);

	f = &write;
	fd = open("main.c", S_IWUSR); // write 
	while( (temp = atomicio(f, fd, buff, 30)) != 0){
		size += temp;
	}
	close(fd);
	printf("write size: %zd\n", size);

	return 0;
}

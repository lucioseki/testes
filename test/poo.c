#include <stdio.h>
#include <stdlib.h>

struct class{
	char name;
	int (*get)();
	int n;
	void (*set)();
	void (*delete)();
};

int get(struct class *this){
	printf("getted %c->n = %d\n", this->name, this->n);
	return this->n;
}

void set(struct class *this, int num){
	this->n = num;
	printf("setted %c->n = %d\n", this->name, this->n);
}

void delete(struct class *this){
	printf("deleted %c\n", this->name);
	if(this) free(this);
	this = NULL;
}

struct class *new(char name){
	struct class *c = malloc(sizeof(struct class));
	c->name = name;
	c->get = get;
	c->n = 0;
	c->set = set;
	c->delete = delete;
	printf("created %c\n", c->name);
	return c;
}

int main(){
	struct class *c = new('c');
	struct class *d = new('d');
	c->set(c, 3);
	c->get(c);
	c->delete(c);
	d->get(d);
	d->delete(d);
	return 0;
}

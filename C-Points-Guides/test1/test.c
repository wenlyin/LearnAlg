#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("argc::%d\n", argc);
	// declare an variable ptr which holds the value-at-address of an int type
	int *ptr;
	// declare assign an int the literal value of 1
	int val = 1;
	// assign to ptr the address-of the val variable
	ptr = &val;
	// dereference and get the value-at-address stored in ptr
	int deref = *ptr;
	printf("%d\n", deref);

	// print out dereferenced(*) values
	printf("dereference *ptr = %d\n", *ptr);
	printf("dereference address of val *(&val) = %d\n", *(&val));
	return 0;
}

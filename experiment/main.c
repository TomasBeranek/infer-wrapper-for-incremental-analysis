#include "changed.h"
#include <stdio.h>
#include <stdlib.h>
#include "constant.h"


int main(){
	int a = 0;
	int b = a;										// DEAD_STORE
	int* p = NULL;

	if (c())
		printf("No error");

	if (f() == 1)
		printf("No error");

	if (f() == 2)
		*p = 0;											// NULL_DEREFERENCE only when 'f' returns 2
}

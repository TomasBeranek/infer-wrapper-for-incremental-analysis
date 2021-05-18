#include "callee.h"
#include <stdlib.h>

void g(int x){
	int a = 0;
	int b = a;					// DEAD_STORE
	int* ptr = NULL;

	if (x == 2)
		*ptr = 0;					// NULL_DEREFERENCE
	return;
}

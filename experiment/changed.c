#include "changed.h"
#include "callee.h"

int r(){}

int f(){
	int a = 0;
	int b = a;						// DEAD_STORE

	g(1);

	if (r())
		return 1;
	else
		return 1; 					// change the return value from 1 to 2
}

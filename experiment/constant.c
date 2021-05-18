#include "constant.h"

int c (){
	int a = 0;
  int b = a; 				// DEAD_STORE

	return 1;
}

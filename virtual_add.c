#include <stdio.h>
#include <stdlib.h>

// Remember : all addresses printed out is virtual. Only the OS and hardware know truth
int main (int argc, char *argv[]) {
	printf("location of code : %p\n", (void *) main);
	printf("location of heap : %p\n", (void *) malloc(1));
	// "effective" location of stack, as it's really the only variable allocated in memory (so at the start!). Same applies to heap
	int x = 3;
	printf ("location of stack : %p\n", (void *) &x);
	return x;
}

// You might notice the code and heap are not too far apart. Indeed, this is a small program, and it doesn't take up a lot of space. Recall the address space distribution from this section of OSTEP

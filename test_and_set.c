// ATOMIC EXCHANGE (test-and-set!): a simple flag for lock-unlock

#include <pthread.h>

typedef struct __lock_t { int flag; } lock_t;

void init(lock_t *mutex) {
	// 0 -> lock is available, 1 -> held
	mutex->flag = 0;
}

// this operation is guaranteed to be atomic by modern hardware systems
int TestAndSet(int *ptr, int new) {
	int old = *ptr;	// fetch old value at ptr
	*ptr = new;   	// store 'new' into ptr
	return old	// return old value

void lock(lock_t *mutex) {
	while (TestAndSet(&mutex->flag, 1) == 1)	// test the flag
		;	// spin-wait (do nothing)
}

void unlock(lock_t *mutex) {
	mutex->flag = 0;
}


// big picture: an interleaving of threads exists that violates correctness!

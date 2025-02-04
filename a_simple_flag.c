// NO ATOMIC EXCHANGE: a simple, failed flag for lock-unlock

#include <pthread.h>

typedef struct __lock_t { int flag; } lock_t;

void init(lock_t *mutex) {
	// 0 -> lock is available, 1 -> held
	mutex->flag = 0;
}

void lock(lock_t *mutex) {
	while (mutex->flag == 1)	// test the flag
		;	// spin-wait (do nothing)
	mutex->flag = 1;		// now SET it!
}

void unlock(lock_t *mutex) {
	mutex->flag = 0;
}


// big picture: an interleaving of threads exists that violates correctness!

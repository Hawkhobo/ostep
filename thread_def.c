#include <pthread.h>

int
pthread_create(		pthread_t *	   thread, 		     // pointer to a structure of type pthread_t (this structure is what is used to interact with the thread itself!)
		  const pthread_attr_t *   attr,		     // specify any attributes this thread might have (setting stack size, or scheduling priority of the thread), which initialize at a pthread_attr_init() call
			void * 		   (*start_routine)(void*),  // complex! but it asks: "which function should this thread start running in?" This is a FUNCTION POINTER; says start_routine, passed void argument, and returns a void pointer
			void *		   arg);		     // this is the argument to be passed to start_routine (where the function begins execution)  	


// Having a void pointer to the function pointer allows a user to pass in ANY type of argument. And having it as the return value allows you to return ANY type of result!

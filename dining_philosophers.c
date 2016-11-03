//Michael Rose
//Dining Philosophers with 5 philosophers
#include <pthread.h>
#include <semaphore.h>

//first too letters are the first initial of the philosophers on either side
pthread_mutex_t tp_fork;
pthread_mutex_t pp_fork;
pthread_mutex_t ps_fork;
pthread_mutex_t sa_fork;
pthread_mutex_t at_fork;
pthread_mutex_t table;

void * life_of_a_philosopher(void *arg){
	
}


int main(int argc, char **argv)
{
	pthread_t thales_of_miletus;
	pthread_t pythagoras;
	pthread_t plato;
	pthread_t socrates;
	pthread_t aristotle;
	return 0;
}

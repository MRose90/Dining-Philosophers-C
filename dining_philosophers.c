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
	char * name = "Thales of Miletus";
	if(pthread_create(&thales_of_miletus, NULL, produce, (void*)name)){
		printf("Error creating producer.\n");
		return 1;
	}
	name = "Pythagoras";
	if(pthread_create(&pythagoras, NULL, produce, (void*)name)){
		printf("Error creating producer.\n");
		return 1;
	}
	char * name = "Plato";
	if(pthread_create(&plato, NULL, produce, (void*)name)){
		printf("Error creating producer.\n");
		return 1;
	}
	char * name = "Socrates";
	if(pthread_create(&socrates, NULL, produce, (void*)name)){
		printf("Error creating producer.\n");
		return 1;
	}
	char * name = "Aristotle";
	if(pthread_create(&aristotle, NULL, produce, (void*)name)){
		printf("Error creating producer.\n");
		return 1;
	}
	pthread_join(aristotle,NULL)
	pthread_join(socrates,NULL);
	pthread_join(plato,NULL);
	pthread_join(pythagoras,NULL);
	pthread_join(thales_of_miletus,NULL);
	return 0;
}

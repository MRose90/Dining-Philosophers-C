//Michael Rose
//Dining Philosophers with 5 philosophers
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
//first too letters are the first initial of the philosophers on either side
pthread_mutex_t tp_fork;
pthread_mutex_t pp_fork;
pthread_mutex_t ps_fork;
pthread_mutex_t sa_fork;
pthread_mutex_t at_fork;
pthread_mutex_t table;


struct param{
	char * name;
};
void * life_of_a_philosopher(void *arg){
	struct param *p = (struct param *) arg;
	struct forks *f = p->f;
	char * name = p->name;
	int thinking;
	int hungry;
	int eat;
	while(1){
		//think
		
		thinking = rand()%20+1;
		printf("%s is thinking for %d seconds.\n",name,thinking);
		sleep(thinking);
		//get_forks
		hungry = 1;
		while(hungry == 1){
			pthread_mutex_lock(&table);
			if(strcmp(""Thales of Miletus"",name) == 0){
				if(pthread_mutex_trylock(at_fork) == 0){
					if(pthread_mutex_trylock(tp_fork) == 0){
						hungry = 0;
					} else {
						pthread_mutex_unlock(at_fork);
					}
				}	
			}
			if(strcmp("Pythagoras",name) == 0){
				if(pthread_mutex_trylock(tp_fork) == 0){
					if(pthread_mutex_trylock(pp_fork) == 0){
						hungry = 0;
					} else {
						pthread_mutex_unlock(tp_fork);
					}
				}
			}
			if(strcmp("Plato",name) == 0){
				if(pthread_mutex_trylock(pp_fork) == 0){
					if(pthread_mutex_trylock(ps_fork) == 0){
						hungry = 0;
					} else {
						pthread_mutex_unlock(pp_fork);
					}
				}
			}
			if(strcmp("Socrates",name) == 0){
				if(pthread_mutex_trylock(ps_fork) == 0){
					if(pthread_mutex_trylock(sa_fork) == 0){
						hungry = 0;
					} else {
						pthread_mutex_unlock(ps_fork);
					}
				}
			}
			if(strcmp("Aristotle",name) == 0){
				if(pthread_mutex_trylock(sa_fork) == 0){
					if(pthread_mutex_trylock(at_fork) == 0){
						hungry = 0;
					} else {
						pthread_mutex_unlock(sa_fork);
					}
				}
			}
		}
		pthread_mutex_unlock(&table);
		//eat
		eat = rand()%7+2;
		printf("%s is eating for %d seconds.\n",name,eat);
		sleep(eat);
		//put_forks
		pthread_mutex_lock(&table);
			if(strcmp(""Thales of Miletus"",name) == 0){
				pthread_mutex_unlock(at_fork);
				pthread_mutex_unlock(tp_fork);
			}
			if(strcmp("Pythagoras",name) == 0){

				pthread_mutex_unlock(tp_fork);
				pthread_mutex_unlock(pp_fork);
			}
			if(strcmp("Plato",name) == 0){
				pthread_mutex_unlock(pp_fork);
				pthread_mutex_unlock(ps_fork);
			}
			if(strcmp("Socrates",name) == 0){
				pthread_mutex_unlock(ps_fork);
				pthread_mutex_unlock(sa_fork);
			}
			if(strcmp("Aristotle",name) == 0){
				pthread_mutex_unlock(sa_fork);
				pthread_mutex_unlock(at_fork);
			}
	}
}


int main(int argc, char **argv)
{
	
	pthread_t thales_of_miletus;
	pthread_t pythagoras;
	pthread_t plato;
	pthread_t socrates;
	pthread_t aristotle;
	struct param *p;
	p = (struct param *)malloc(sizeof(struct param));
	struct forks *f;
	f = (struct forks *)malloc(sizeof(struct forks));
	p->forks = f;
	p->name = "Thales of Miletus";
	if(pthread_create(&thales_of_miletus, NULL, life_of_a_philosopher, (void*)p)){
		printf("Error creating producer.\n");
		return 1;
	}
	sleep(1);
	p->name = "Pythagoras";
	if(pthread_create(&pythagoras, NULL, life_of_a_philosopher, (void*)p)){
		printf("Error creating producer.\n");
		return 1;
	}
	sleep(1);
	p->name = "Plato";
	if(pthread_create(&plato, NULL, life_of_a_philosopher, (void*)p)){
		printf("Error creating producer.\n");
		return 1;
	}
	sleep(1);
	p->name = "Socrates";
	if(pthread_create(&socrates, NULL, life_of_a_philosopher, (void*)p)){
		printf("Error creating producer.\n");
		return 1;
	}
	sleep(1);
	p->name = "Aristotle";
	if(pthread_create(&aristotle, NULL, life_of_a_philosopher, (void*)p)){
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

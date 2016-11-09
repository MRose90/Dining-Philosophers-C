//Michael Rose - Matthew Zakrevsky
//Oregon State University - CS 444 - Concurrency Assignment 2
//Dining Philosophers with 5 philosophers
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	clock_t last_eaten = clock();
	struct param *p = (struct param *) arg;
	char * name = p->name;
	int thinking;
	int hungry;
	int eat;
	while(1){
		//think
		thinking = rand()%20+1;
		t = time(NULL);
		tm = *localtime(&t);
		printf("[%d:%02d:%02d] %s is thinking for %d seconds.\n"
				,tm.tm_hour, tm.tm_min, tm.tm_sec,name,thinking);
		sleep(thinking);
		//get_forks
		hungry = 1;
		while(hungry == 1){
			if((int)(clock() - last_eaten) / CLOCKS_PER_SEC > 100){
				printf("WARNING: %s last ate over 100 seconds ago.\n",name);
				exit(0);
			}
			pthread_mutex_lock(&table);
			if(strcmp("Thales of Miletus",name) == 0){
				if(pthread_mutex_trylock(&at_fork) == 0){
					if(pthread_mutex_trylock(&tp_fork) == 0){
						hungry = 0;
					} else {
						pthread_mutex_unlock(&at_fork);
					}
				}	
			}
			if(strcmp("Pythagoras",name) == 0){
				if(pthread_mutex_trylock(&tp_fork) == 0){
					if(pthread_mutex_trylock(&pp_fork) == 0){
						hungry = 0;
					} else {
						pthread_mutex_unlock(&tp_fork);
					}
				}
			}
			if(strcmp("Plato",name) == 0){
				if(pthread_mutex_trylock(&pp_fork) == 0){
					if(pthread_mutex_trylock(&ps_fork) == 0){
						hungry = 0;
					} else {
						pthread_mutex_unlock(&pp_fork);
					}
				}
			}
			if(strcmp("Socrates",name) == 0){
				if(pthread_mutex_trylock(&ps_fork) == 0){
					if(pthread_mutex_trylock(&sa_fork) == 0){
						hungry = 0;
					} else {
						pthread_mutex_unlock(&ps_fork);
					}
				}
			}
			if(strcmp("Aristotle",name) == 0){
				if(pthread_mutex_trylock(&sa_fork) == 0){
					if(pthread_mutex_trylock(&at_fork) == 0){
						hungry = 0;
					} else {
						pthread_mutex_unlock(&sa_fork);
					}
				}
			}
			pthread_mutex_unlock(&table);
		}
		//eat
		eat = rand()%7+2;
		t = time(NULL);
		tm = *localtime(&t);
		printf("[%d:%02d:%02d] EATING: %s holds the forks for %d seconds.\n"
				,tm.tm_hour, tm.tm_min, tm.tm_sec,name,eat);
		last_eaten = clock();
		sleep(eat);
		//put_forks
		if(strcmp("Thales of Miletus",name) == 0){
			pthread_mutex_unlock(&at_fork);
			pthread_mutex_unlock(&tp_fork);
		}
		if(strcmp("Pythagoras",name) == 0){
			pthread_mutex_unlock(&tp_fork);
			pthread_mutex_unlock(&pp_fork);
		}
		if(strcmp("Plato",name) == 0){
			pthread_mutex_unlock(&pp_fork);
			pthread_mutex_unlock(&ps_fork);
		}
		if(strcmp("Socrates",name) == 0){
			pthread_mutex_unlock(&ps_fork);
			pthread_mutex_unlock(&sa_fork);
		}
		if(strcmp("Aristotle",name) == 0){
			pthread_mutex_unlock(&sa_fork);
			pthread_mutex_unlock(&at_fork);
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
	printf("If any philosopher goes 100 seconds without eating, "
	"the program terminates.\n");
	p->name = "Thales of Miletus";
	if(pthread_create(&thales_of_miletus, NULL, life_of_a_philosopher, (void*)p)){
		printf("Error creating Thales.\n");
		return 1;
	}
	sleep(1);
	p->name = "Pythagoras";
	if(pthread_create(&pythagoras, NULL, life_of_a_philosopher, (void*)p)){
		printf("Error creating Pythagoras.\n");
		return 1;
	}
	sleep(1);
	p->name = "Plato";
	if(pthread_create(&plato, NULL, life_of_a_philosopher, (void*)p)){
		printf("Error creating Plato.\n");
		return 1;
	}
	sleep(1);
	p->name = "Socrates";
	if(pthread_create(&socrates, NULL, life_of_a_philosopher, (void*)p)){
		printf("Error creating Socrates.\n");
		return 1;
	}
	sleep(1);
	p->name = "Aristotle";
	if(pthread_create(&aristotle, NULL, life_of_a_philosopher, (void*)p)){
		printf("Error creating Aristotle.\n");
		return 1;
	}
	pthread_join(aristotle,NULL);
	pthread_join(socrates,NULL);
	pthread_join(plato,NULL);
	pthread_join(pythagoras,NULL);
	pthread_join(thales_of_miletus,NULL);
	return 0;
}

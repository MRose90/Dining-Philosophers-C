all: conc

conc: dining_philosophers.c
	gcc -pthread -o df dining_philosophers.c

clean:
	$(RM) *.o df



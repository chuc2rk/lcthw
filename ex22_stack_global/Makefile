CFLAGS=-Wall -g

clean:
	rm -f ex22 ex22.o ex22_main ex22_main.o

ex22.o: ex22.c
	cc $(CFLAGS) -DNDEBUG -c ex22.c

ex22_main.o: ex22_main.c
	cc $(CFLAGS) -DNDEBUG -c ex22_main.c
	
ex22_main: ex22_main.o ex22.o
	cc $(CFLAGS) -DNDEBUG -o ex22_main ex22_main.o ex22.o
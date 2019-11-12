all: rand.c
	gcc rand.c

run:
	./a.out

clean:
	rm *.o
	rm program

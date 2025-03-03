OBJECTS = objects/create_candidate.o objects/get_vote.o objects/reveal_winner.o

all: main.exe

main.exe: main.c $(OBJECTS)
	gcc main.c $(OBJECTS) -o main

objects/create_candidate.o: src/create_candidate.c
	gcc -c src/create_candidate.c -o objects/create_candidate.o

objects/reveal_winner.o: src/reveal_winner.c
	gcc -c src/reveal_winner.c -o objects/reveal_winner.o

objects/get_vote.o: src/get_vote.c
	gcc -c src/get_vote.c -o objects/get_vote.o

run: main.exe
	main.exe

clean:
	del main.exe objects\*.o
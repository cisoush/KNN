CC = gcc

CFLAGS = -Wall -Wextra -std=c89

LIBS = -lMLV -lm

OBJETS = main.o interface.o point.o donnees.o

EXEC = projet

all: $(EXEC)

$(EXEC): $(OBJETS)
	$(CC) $(CFLAGS) $(OBJETS) -o $(EXEC) $(LIBS)

main.o: main.c interface.h
	$(CC) $(CFLAGS) -c main.c

interface.o: interface.c interface.h point.h donnees.h
	$(CC) $(CFLAGS) -c interface.c

point.o: point.c point.h
	$(CC) $(CFLAGS) -c point.c

donnees.o: donnees.c donnees.h point.h
	$(CC) $(CFLAGS) -c donnees.c

clean:
	rm -f *.o $(EXEC)

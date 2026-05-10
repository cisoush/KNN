CC = gcc
CFLAGS = -W -Wall -pedantic -std=c89 -O2
LIBS = -lMLV -lm

all : projet

projet : main.o interface.o point.o donnees.o
    $(CC) $(CFLAGS) -o projet main.o interface.o point.o donnees.o $(LIBS)

main.o : main.c interface.h
    $(CC) $(CFLAGS) -c main.c -o main.o

interface.o : interface.c interface.h point.h donnees.h
    $(CC) $(CFLAGS) -c interface.c -o interface.o

point.o : point.c point.h
    $(CC) $(CFLAGS) -c point.c -o point.o

donnees.o : donnees.c donnees.h point.h
    $(CC) $(CFLAGS) -c donnees.c -o donnees.o

clean :
    rm -rf *.o *~ projet


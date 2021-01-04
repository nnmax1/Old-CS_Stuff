CC = g++
CFLAGS  = -Wall

# Name of Executable File
default: hangman.exe

#create the executable file
hangman.exe: word.o hangman.o main.o
	$(CC) word.o main.o hangman.o -o hangman.exe

# create object files:
hangman.o: hangman.cpp hangman.h word.h
	$(CC) -c $(CFLAGS)  hangman.cpp

word.o: word.cpp word.h
	$(CC) -c $(CFLAGS)  word.cpp

main.o:  main.cpp hangman.h
	$(CC) -c $(CFLAGS) main.cpp

# rm executable file and object files
clean: 
	$(RM) hangman.exe *.o *~
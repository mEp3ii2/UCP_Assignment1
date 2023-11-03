CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o box.o printer.o movement.o gameState.o terminal.o cars.o random.o carMovement.o newSleep.o commands.o validator.o setup.o
EXEC = traffic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c main.h validator.h setup.h
	$(CC) -c main.c $(CFLAGS)

printer.o : printer.c printer.h newSleep.h commands.h newSleep.h
	$(CC) -c printer.c $(CFLAGS)

newSleep.o : newSleep.c newSleep.h
	$(CC) -c newSleep.c $(CFLAGS)

box.o : box.c box.h
	$(CC) -c box.c $(CFLAGS)

movement.o : movement.c movement.h gameState.h terminal.h carMovement.h
	$(CC) -c movement.c $(CFLAGS)

gameState.o : gameState.c gameState.h
	$(CC) -c gameState.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

random.o : random.c random.h
	$(CC) -c random.c $(CFLAGS)

cars.o : cars.c cars.h
	$(CC) -c cars.c $(CFLAGS)

carMovement.o : carMovement.c carMovement.h
	$(CC) -c carMovement.c $(CFLAGS)

commands.o : commands.c commands.h
	$(CC) -c commands.c $(CFLAGS)

validator.o: validator.c validator.h 
	$(CC) -c validator.c $(CFLAGS)

setup.o: setup.c setup.h box.h printer.h movement.h cars.h
	$(CC) -c setup.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)

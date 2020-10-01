

OBJS = hw6.o hw6_test.o client.o 

CC = gcc 
FLAGS = -Wall 

clean : all
	@rm -f $(OBJS) 

all : client 
	./client 


client : $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ -lm

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<


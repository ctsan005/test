#variables
COMPILE=g++
FLAG= -W -Wall -Werror -std=c++11
OBJS	=	command.o	client.o

#Targets
myprog.exe	: tests/rshell.cpp $(OBJS)
	$(COMPILE) $(FLAG) tests/rshell.cpp $(OBJS) -o myprog.exe


command.o : src/command.cpp src/command.h
	$(COMPILE) $(FLAG) -c src/command.cpp 
	
client.o	:	src/client.cpp	src/client.h
	$(COMPILE)	$(FLAG)	-c	src/client.cpp 
    
clean :
	rm *.o myprog.exe
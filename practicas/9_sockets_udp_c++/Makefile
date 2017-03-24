CC = g++
CFLAGS  = -g -Wall

Cliente:  Cliente.o PaqueteDatagrama.h SocketDatagrama.h
	$(CC) $(CFLAGS) -o cliente Cliente.o

Servidor:  Servidor.o PaqueteDatagrama.h SocketDatagrama.h
		$(CC) $(CFLAGS) -o servidor Servidor.o

Servidor.o:  PaqueteDatagrama.h SocketDatagrama.h
		$(CC) $(CFLAGS) -c Servidor.cpp

Cliente.o:  PaqueteDatagrama.h SocketDatagrama.h
		$(CC) $(CFLAGS) -c Cliente.cpp

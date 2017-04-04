CC = g++
CFLAGS  = -g -Wall

Servidor:  Servidor.o PaqueteDatagrama.o SocketDatagrama.o
		$(CC) $(CFLAGS) Servidor.o PaqueteDatagrama.o SocketDatagrama.o -o servidor

Servidor.o:  PaqueteDatagrama.o SocketDatagrama.o
		$(CC) $(CFLAGS) -c Servidor.cpp

Cliente:  Cliente.o PaqueteDatagrama.o SocketDatagrama.o
		$(CC) $(CFLAGS)  Cliente.o PaqueteDatagrama.o SocketDatagrama.o -o cliente

Cliente.o:  PaqueteDatagrama.h SocketDatagrama.h
		$(CC) $(CFLAGS) -c Cliente.cpp

clean:
		rm *.o

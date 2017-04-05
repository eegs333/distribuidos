CC = g++
CFLAGS  = -g -Wall

Servidor:  Servidor.o PaqueteDatagrama.o SocketDatagrama.o
		$(CC) $(CFLAGS) Servidor.o PaqueteDatagrama.o SocketDatagrama.o -o servidor

Servidor.o:  PaqueteDatagrama.o SocketDatagrama.o
		$(CC) $(CFLAGS) -c Servidor.cpp

Cliente:  Cliente.o PaqueteDatagrama.o SocketDatagrama.o gfx.o
		$(CC) $(CFLAGS)  Cliente.o PaqueteDatagrama.o SocketDatagrama.o gfx.o -o cliente -lX11 -lm

Cliente.o:  PaqueteDatagrama.h SocketDatagrama.h gfx.h
		$(CC) $(CFLAGS) -c Cliente.cpp

gfx.o:  gfx.h
				g++ -c gfx.c -lX11 -lm

clean:
		rm *.o


Servidor: SocketDatagrama.o PaqueteDatagrama.o
	g++ Servidor.cpp SocketDatagrama.o PaqueteDatagrama.o -o servidor

server: SocketDatagrama.o PaqueteDatagrama.o
	g++ server.cpp SocketDatagrama.o PaqueteDatagrama.o -o server

SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c

clean:
	rm *.o server

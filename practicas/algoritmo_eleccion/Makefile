
servidor: SocketDatagrama.o PaqueteDatagrama.o gfxModified.o
	g++ Servidor.cpp PaqueteDatagrama.o SocketDatagrama.o gfxModified.o gfxModified.h -o servidor -lX11 -lm

cliente: SocketDatagrama.o PaqueteDatagrama.o
	g++ Cliente.cpp SocketDatagrama.o PaqueteDatagrama.o -o cliente

SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c

gfxModified.o: gfxModified.c gfxModified.h
	gcc -c gfxModified.c -lx11 -lm

clean:
	rm *.o

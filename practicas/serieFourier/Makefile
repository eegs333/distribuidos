
SerieFourier: SocketDatagrama.o PaqueteDatagrama.o SerieFourier.o gfxModified.o
	g++ -std=c++11 SerieFourier.o gfxModified.o SocketDatagrama.o PaqueteDatagrama.o -o SerieFourier -lX11 -lm 
SerieFourier.o: SerieFourier.cpp gfxModified.o
	gcc SerieFourier.cpp -c
gfxModified.o: gfxModified.c gfxModified.h
	gcc gfxModified.c -c

SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c 

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c


clean:
	rm *.o servidor cliente



	

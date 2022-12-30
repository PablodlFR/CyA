p11: main.o cam.o
	g++ main.o cam.o -o p11

main.o: main.cc
	g++ -c main.cc

cam.o: cam.cc cam.h
	g++ -c cam.cc

clean:
	rm *.o p11
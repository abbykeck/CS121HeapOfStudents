CFLAGS = -g -Wall
heapStudents: address.o date.o main.o
	g++ $(CFLAGS) address.o date.o main.o -o heapStudents

address.o: address.cpp address.h
	g++ $(CFLAGS) -c address.cpp

date.o: date.cpp date.h
	g++ $(CFLAGS) -c date.cpp

main.o: main.cpp address.h
	g++ $(CFLAGS) -c main.cpp

run: heapStudents
	./heapStudents

clean:
	rm *.o
	rm heapStudents

debug: heapStudents
	gdb heapStudents

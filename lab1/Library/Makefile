all: Worker.cpp LibraryTest.cpp
	gcc -c Worker.cpp
	gcc -c LibraryTest.cpp
	g++ -o main Worker.o LibraryTest.o
clean:
	rm -f *.o 
	rm -f *.c
	rm main
run:
	./main
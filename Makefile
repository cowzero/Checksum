all: checksum.o main.o
	gcc -o main checksum.o main.o
	./main

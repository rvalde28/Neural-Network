# a simple Makefile for compiling this program

# optimization is on
CC=g++
STD=-std=c++11
# for debugging use this
#CC = c++ -g -o


all: AI

AI: main.o Network.o Layer.o Neuron.o
	$(CC) $(STD) -o AI main.o Network.o Layer.o Neuron.o

main.o: main.cpp Network.o
	$(CC) $(STD) -c main.cpp

Network.o: Network.h Network.cpp Layer.o
	$(CC) $(STD) -c Network.cpp

Layer.o: Layer.h Layer.cpp Neuron.o
	$(CC) $(STD) -c Layer.cpp

Neuron.o: Neuron.h Neuron.cpp
	$(CC) $(STD) -c Neuron.cpp

clean:
	/bin/rm -f *.o AI 



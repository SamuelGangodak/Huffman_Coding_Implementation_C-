all : bitStream.o decoder.o dynamicHeap.o encoder.o node.o main.o
	g++ bitStream.o decoder.o dynamicHeap.o encoder.o node.o main.o -o final.exe

bitStream.o : bitStream.cpp
	g++ -c bitStream.cpp

decoder.o : decoder.cpp
	g++ -c decoder.cpp

dynamicHeap.o : dynamicHeap.cpp
	g++ -c dynamicHeap.cpp

encoder.o : encoder.cpp
	g++ -c encoder.cpp

node.o : node.cpp
	g++ -c node.cpp

main.o : main.cpp
	g++ -c main.cpp

clean : 
	del *.o *.exe
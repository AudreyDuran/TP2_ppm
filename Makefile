

all: ppm.out      

ppm.out :  ppm.cpp Image.o
	g++ -o ppm.out ppm.cpp Image.o -Wall

#pour créer Vector.o, il faut faire ça
Image.o : Image.h Image.cpp 
	g++ -Wall -o Image.o Image.cpp -c

clean:
	rm *.o

mrproper: clean
	rm ppm.out 
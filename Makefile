

all: ppm.out      

ppm.out :  ppm.c Image.o
	g++ -o ppm.out ppm.c Image.o -Wall

#pour créer Vector.o, il faut faire ça
Image.o : Image.h Image.c 
	g++ -Wall -o Image.o Image.c -c

clean:
	rm *.o

mrproper: clean
	rm ppm.out 
inc = -lm 

all: main.o myFunction.o myLibrary.h
	gcc -w -o my_exe main.o myFunction.o -Wno-deprecated -I ${inc} 

main.o: main.c myLibrary.h
	gcc -c main.c -Wno-deprecated -I ${inc}

myFunction.o:  myFunction.c myLibrary.h 
	gcc -c myFunction.c -Wno-deprecated -I ${inc}
clean:
	rm -f *.o

######################################################
#This Makefile is created to help IC250 students
#Created By:
#Aditya Nigam
#SCEE
#IIT Mandi
#Please modify according to your need 
######################################################

inc =  -lm 

all: main.o myFunction.o myLibrary.h
	gcc -w -o my_exe main.o myFunction.o -Wno-deprecated -I ${inc} 

main.o: main.c myLibrary.h
	gcc -c main.c -Wno-deprecated -I ${inc}

myFunction.o:  myFunction.c myLibrary.h 
	gcc -c myFunction.c -Wno-deprecated -I ${inc}
clean:
	rm -f *.o

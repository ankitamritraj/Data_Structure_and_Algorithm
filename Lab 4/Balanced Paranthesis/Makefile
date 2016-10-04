all : balance.o stacky.h all_Library.h
	gcc -w -o balance_exe balance.o -Wno-deprecated -lm
balance.o : balance.c stacky.h all_Library.h
	gcc -c balance.c -Wno-deprecated -lm
# function.o : function.c stack.h all_Library.h                                             
#                               gcc -c function.c stack.h all_Library.h                     
clean :
	rm -f *.o

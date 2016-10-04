
all : stack_reversal.o stacky.h all_Library.h
		gcc -w -o stack_reversal_exe stack_reversal.o -Wno-deprecated -lm
stack_reversal.o : stack_reversal.c stacky.h all_Library.h 
				gcc -c stack_reversal.c -Wno-deprecated -lm
# function.o : function.c stack.h all_Library.h
# 				gcc -c function.c stack.h all_Library.h
clean :
		rm -f *.o 
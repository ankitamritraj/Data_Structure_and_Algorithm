
all : Stacks_using_queue.o queue.h all_Library.h
		gcc -w -o stack_reversal_exe Stacks_using_queue.o -Wno-deprecated -lm
Stacks_using_queue.o : Stacks_using_queue.c queue.h all_Library.h 
				gcc -c Stacks_using_queue.c -Wno-deprecated -lm
# function.o : function.c stack.h all_Library.h
# 				gcc -c function.c stack.h all_Library.h
clean :
		rm -f *.o 
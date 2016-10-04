
all : palindrome.o stacky.h all_Library.h
		gcc -w -o palindrome_exe palindrome.o -Wno-deprecated -lm
palindrome.o : palindrome.c stacky.h all_Library.h 
				gcc -c palindrome.c -Wno-deprecated -lm
# function.o : function.c stack.h all_Library.h
# 				gcc -c function.c stack.h all_Library.h
clean :
		rm -f *.o 
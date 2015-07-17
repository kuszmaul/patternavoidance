# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++
CFLAGS  = -O2 -std=c++11 -g

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)	
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: test

test:  fastavoidance.o hashdb.o test.o
	$(CC) $(CFLAGS) -o test test.o hashdb.o fastavoidance.o

fastavoidance.o:  fastavoidance.cpp fastavoidance.h hashdb.o
	$(CC) $(CFLAGS) -o fastavoidance.cpp

hashdb.o:  hashdb.cpp hashdb.h 
	$(CC) $(CFLAGS) -o hashdb.cpp

hashdb.o:  test.cpp
	$(CC) $(CFLAGS) -o test.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) count *.o *~
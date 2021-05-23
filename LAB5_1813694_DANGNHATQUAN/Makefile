all: pi_multi-thread pi_serial code

code: code.o
		gcc code.o -o code
code.o:
		gcc -c code.c
pi_serial: pi_serial.o
		gcc pi_serial.o -o pi_serial
pi_serial.o:
		gcc -c pi_serial.c
pi_multi-thread: pi_multi-thread.o
		gcc pi_multi-thread.o -o pi_multi-thread
pi_multi-thread.o:
		gcc -c pi_multi-thread.c
clean:
		rm -f *.o pi_multi-thread pi_serial code
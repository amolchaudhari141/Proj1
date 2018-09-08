

proj1: et_crt ep_crt para_mm

et_crt: et.o timing.o
	gcc -o et_crt et.o timing.o -lpthread

et.o: et.c
	gcc -c et.c -o et.o

ep_crt: ep.o timing.o
	gcc -o ep_crt ep.o timing.o

ep.o: ep.c
	gcc -c ep.c -o ep.o

para_mm: mm_thr.o timing.o
	gcc -o para_mm mm_thr.o timing.o -lpthread

mm_thr.o: mm_thr.c
	gcc -c mm_thr.c -o mm_thr.o

timing.o: timing.c timing.h
	gcc -c timing.c -o timing.o

clean:
	rm et.o ep.o mm_thr.o timing.o

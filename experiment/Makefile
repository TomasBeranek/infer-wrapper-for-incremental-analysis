all: changed.o main.o constant.o callee.o
	gcc changed.o callee.o main.o constant.o -o changed

constant.o: constant.c
	gcc -c constant.c

changed.o: changed.c
	gcc -c changed.c

callee.o: callee.c
	gcc -c callee.c

main.o:
	gcc -c main.c

reset: clean infer

clean:
	rm -f changed.o main.o constant.o callee.o changed

infer:
	rm -Rf infer-out/

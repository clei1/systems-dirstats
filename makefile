all: filestat.c dirstats.c
	gcc dirstats.c
run: all
	./a.out
clean: 
	rm *.out
	rm *~

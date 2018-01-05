all: compile

compile:
	
	gcc FunctionsTrab4.c -c -O0 -g3 -Wall -fmessage-length=0 -std=c99
	gcc FunctionsTrab4.o trab4.c -Wall -g -lm -o trab4	
	
	gcc gera.c -o gera

	pdflatex artigo.tex
run:
		
	./trab4
	
clean:
	rm trab4 FunctionsTrab4.o artigo.pdf gera artigo.aux artigo.log artigo.out
		

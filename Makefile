#My first makefile

trabalho: main.o vetoresReais.o vetoresComplexos.o complexoNaoFracionario.o complexo_rac.o racional.o naoFracionario.o
	clang main.o vetoresReais.o vetoresComplexos.o complexoNaoFracionario.o complexo_rac.o racional.o naoFracionario.o -o trabalho -lm

main.o: main.c 
	clang -c main.c

vetoresReais.o: vetoresReais.c
	clang -c vetoresReais.c

VetoresComplexos.o: vetoresComplexos.c
	clang -c vetoresComplexos.c

ComplexoNaoFracionario.o: complexoNaoFracionario.c
	lang -c complexoNaoFracionario.c

complexo_rac.o: complexo_rac.c
	clang -c complexo_rac.c

racional.o: racional.c
	clang -c racional.c

naoFracionario.o: naoFracionario.c
	clang -c naoFracionario.c

clean:
	rm -rf *.o *~ trabalho
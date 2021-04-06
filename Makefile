build: board data eval generator init main move print pvTable search test
	gcc objects/*.o -o chessEngine

board:
	gcc sources/board.c -o objects/board.o -c
data:
	gcc sources/data.c -o objects/data.o -c
eval:
	gcc sources/eval.c -o objects/eval.o -c
generator:
	gcc sources/generator.c -o objects/generator.o -c
init:
	gcc sources/init.c -o objects/init.o -c
main:
	gcc sources/main.c -o objects/main.o -c
move:
	gcc sources/move.c -o objects/move.o -c
print:
	gcc sources/print.c -o objects/print.o -c
pvTable:
	gcc sources/pvTable.c -o objects/pvTable.o -c
search:
	gcc sources/search.c -o objects/search.o -c
test:
	gcc sources/test.c -o objects/test.o -c

run:
	./chessEngine

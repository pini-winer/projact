main: main.o  data.o
	gcc  -g main.o  data.o trees.o select.o add.o  -o main

main.o: main.c
	gcc -Wall -c main.c


data.o: data.c
	gcc -Wall -c data.c

trees.o: trees.c
	gcc -Wall -c trees.c

select.o: select.c
	gcc -Wall -c select.c
add.o: add.c
	gcc -Wall -c add.c



clean:
	@rm -f *.o main

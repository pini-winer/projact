mainServer: mainServer.o data.o trees.o select.o add.o
		gcc  -g mainServer.o  data.o trees.o select.o add.o  -o mainServer -pthread

main: main.o data.o trees.o select.o add.o
		gcc  -g main.o  data.o trees.o select.o add.o  -o main


mainServer.o: mainServer.c
	gcc -Wall -g -c mainServer.c

main.o: main.c
	gcc -Wall -g -c main.c

data.o: data.c
	gcc -Wall -g -c data.c

trees.o: trees.c
	gcc -Wall -g -c trees.c

select.o: select.c
	gcc -Wall -g -c select.c

add.o: add.c
	gcc -Wall -g -c add.c


clean:
	rm -f *.o mainServer

mainClient:
	gcc mainClient.c -o mainClient

serverRun:
	./mainServer 12932 customers.txt

mainRun:
	./main customers.txt

clientRun:
	./mainClient 12932

debug:
	gdb --args ./mainServer 12932 customers.txt
all: main.c Sources/menu.c Sources/voo.c Sources/ListadeVoos.c Sources/ItemMatriz.c Sources/MatrizVoos.c
	gcc main.c -g Sources/menu.c Sources/voo.c Sources/ListadeVoos.c Sources/ItemMatriz.c Sources/MatrizVoos.c

run: a.out
	./a.out
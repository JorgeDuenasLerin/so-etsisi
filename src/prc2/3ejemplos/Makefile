# Variables
CC = cc

# No funcionó en Minix. $< $@

all: punteros size 1cadena 2cadena 3cadena 4cadena 5cadena arraypuntero dinamica funcionpuntero aritmeticapuntero estructuras

1cadena: 1cadena.c
	$(CC) -o 1cadena 1cadena.c

2cadena: 2cadena.c
	$(CC) -o 2cadena 2cadena.c

3cadena: 3cadena.c
	$(CC) -o 3cadena 3cadena.c

4cadena: 4cadena.c
	$(CC) -o 4cadena 4cadena.c

5cadena: 5cadena.c
	$(CC) -o 5cadena 5cadena.c

size: size.c
	$(CC) -o size size.c

punteros: punteros.c
	$(CC) -o punteros punteros.c

arraypuntero: arraypuntero.c
	$(CC) -o arraypuntero arraypuntero.c

dinamica: dinamica.c
	$(CC) -o dinamica dinamica.c

funcionpuntero: funcionpuntero.c
	$(CC) -o funcionpuntero funcionpuntero.c

aritmeticapuntero: aritmeticapuntero.c
	$(CC) -o aritmeticapuntero aritmeticapuntero.c

estructuras: estructuras.c
	$(CC) -o estructuras estructuras.c

# Limpieza
clean:
	rm -f punteros size 1cadena 2cadena 3cadena 4cadena 5cadena arraypuntero dinamica funcionpuntero aritmeticapuntero estructuras

# Ojo con el final de fichero. Make requiere que haya una línea en blanco al final del fichero.

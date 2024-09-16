# Cuenta una historia basada en los ficheros intro.txt, presentacion.txt, suceso.txt y desenlace.txt

STAT_COMMAND=wc

cuenta: historia.txt
	echo "Te voy a contar una historia..."
	cat historia.txt

historia.txt: intro.txt presentacion.txt suceso.txt desenlace.txt 
	echo "Construyendo el fichero historia"
	cat intro.txt > historia.txt
	cat presentacion.txt >> historia.txt
	cat suceso.txt >> historia.txt
	cat desenlace.txt >> historia.txt
	echo "El fichero historia se ha generado correctamente"

limpiar:
	rm -rf historia.txt

estadisticas: historia.txt
	$(STAT_COMMAND) historia.txt

# Ojo con el final de fichero. Make requiere que haya una línea en blanco al final del fichero.

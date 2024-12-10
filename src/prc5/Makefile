# Nombre del ejecutable final
TARGET = enlace

# Archivos objeto existentes
OBJS = driver.o 

# Archivo fuente que los alumnos deben modificar
SRC = enlace.c

# Compilador
CC = cc

# Regla para compilar el ejecutable final
$(TARGET): $(OBJS) $(SRC)
	$(CC) -o $(TARGET) $(OBJS) $(SRC)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) *.o

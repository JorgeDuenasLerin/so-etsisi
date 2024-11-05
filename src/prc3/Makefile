#Makefile practica SO->prc3

N_doCPU = doCPU_1 doCPU_2 doCPU_3 doCPU_4 doCPU_5 doCPU_6 doCPU_7 doCPU_8 doCPU_9 

all: prueba_a prueba_b $(N_doCPU)

prueba_a: prueba_a.c
	cc prueba_a.c -o prueba_a

prueba_b: prueba_b.c
	cc prueba_b.c -o prueba_b

doCPU_0: doCPU.c
	cc doCPU.c -o doCPU_0

$(N_doCPU): doCPU_0
	ln doCPU_0 $@

clean:
	rm -f prueba_a prueba_b doCPU_0 $(N_doCPU)

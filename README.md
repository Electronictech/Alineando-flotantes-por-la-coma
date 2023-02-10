# Alineando-flotantes-por-la-coma
Aca desarrollo, un algoritmo, en este caso en C, para Keil, Eclipse o cualquier otro, el algoritmo lo desarrollé porque necesitava presentar en una pantalla
LCD de 4 Filas 20 Columnas, en la Linea 2, los valores de voltaje de un sistema trifasico y en la Linea 3, los valores de corriente.
Los valores de corriente y voltaje podian estar en un rango de 3 digitos y un decimal, o sea de 0.0 a 999.9. Ahora cuando usas la impresion con formato sprintf, y usas el formato para flotantes (%f), aunque le digas %3.1f (3 digitos en la parte entera y un digito decimal) el valor se escribe alineado a la izquierda y los ceros
a la izquierda no se imprimen, lo cual hara que si en la linea de arriba tengo un valor de 125.3 y la linea de abajo tengo un valor de 1.3, los valores no apareceran
alineados verticalmente. Lo voy a mostrar graficamente con tres valores de voltaje de: 123.3 124.5 126.6 en la linea 2 y 1.3 1.2 1.6 en la linea 3, e imprimiendo
desde las mismas posiciones iniciales con sprintf obtenia en la pantalla LCD esta presentacion (La letra V o C, la imprimo al inicio con los dos puntos:
V:123.3 124.5 126.6
C:1.3   1.2   1.6
Pero yo queria que se vizualizará asi:
V:123.3 124.5 126.6
C:  1.3   1.2   1.6

Ahora les dejo los dos codigos base, para que vean la diferencia. La primera parte es usando sprintf y la segunda es con mi rutina de separacion y alineado

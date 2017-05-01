
#ifndef stdio_h
#define stdio_h
#include <stdio.h>
#endif /* stdio_h */

#ifndef stdlib_h
#define stdlib_h
#include <stdlib.h>
#endif /* stdlib_h */

#ifndef Abb_h
#define Abb_h
#include "Abb.h"
#endif /* abb_h */


/* SALIDA ESPERADA
 >> file10
 cantidad:10
 520932930
 28925691
 822784415
 890459872
 145532761
 2132723841
 1040043610
 1643550337
 68362598
 66433441
 
 
 >> file10ordenado
 cantidad:10
 28925691
 66433441
 68362598
 145532761
 520932930
 822784415
 890459872
 1040043610
 1643550337
 2132723841
 
 
 >> file10e6ordenado
 cantidad:1000000
 1213
 215503492
 429927709
 643918142
 859435684
 1074487782
 1289425675
 1504499051
 1718754442
 1933930661
 
 >> file10d
 cantidad:10
 2
 4
 3
 3
 0
 2
 4
 3
 3
 4
 
 
 >> file10dordenado
 cantidad:4
 0
 2
 3
 4
 
 
 >> file10e6dordenado
 cantidad:432481
 0
 57709
 115582
 173408
 231213
 289095
 346962
 404647
 462448
 */

void muestraArchivo(const char *nombreArchivo, int paso){
    int n, *numeros; int i;
    FILE *archivo = fopen(nombreArchivo,"rb");
    fread(&n, sizeof(int), 1, archivo);
    numeros = malloc(sizeof(int)*n);
    printf("\n>> %s\ncantidad:%i\n",nombreArchivo, n);
    fread(numeros, sizeof(int), n, archivo);
    for(i = 0; i < n; i+=paso){
        printf("%i\n",numeros[i]);
    }
    free(numeros);
}

int main() {
	
    //Prueba con archivo de 10 enteros sin duplicados
 //   muestraArchivo("file10", 1);

    Abb *arbol1=leeArchivoEnABB("file10");
    generaArchivoOrdenado(arbol1, "file10ordenado");
    muestraArchivo("file10ordenado", 1);
    eliminaAbb(arbol1);

    //Prueba con archivo de 1000000 enteros sin duplicados
    Abb *arbol2 = leeArchivoEnABB("file10e6");
    printf("\n");
    generaArchivoOrdenado(arbol2, "file10e6ordenado");
    muestraArchivo("file10e6ordenado", 100000);
    eliminaAbb(arbol2);

    //Prueba con archivo de 10 enteros con duplicados
    muestraArchivo("file10d", 1);
    Abb *arbol3 = leeArchivoEnABB("file10d");
    printf("\n");
    generaArchivoOrdenado(arbol3, "file10dordenado");
    muestraArchivo("file10dordenado", 1);
    eliminaAbb(arbol3);

    //Prueba con archivo de 1000000 enteros con duplicados
    Abb *arbol4 = leeArchivoEnABB("file10e6d");
    printf("\n");
    generaArchivoOrdenado(arbol4, "file10e6dordenado");
    muestraArchivo("file10e6dordenado", 50000);
    eliminaAbb(arbol4);

    return 0;
}

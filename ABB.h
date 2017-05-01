#ifndef stdio_h
#include<stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdlib_h
#endif


typedef struct nodo
{
	int dato;
	struct nodo *izq,*der;
}Abb;

void eliminaAbb(Abb *a){
    if (a != NULL)
	{
        eliminaAbb (a->izq);
        eliminaAbb (a->der);
        free (a);
        a = NULL;
    }
}

Abb *Inselem(Abb *a,int elem)
{
	if(a==NULL)
	{
		a=malloc(sizeof(Abb));
		a->dato=elem;
		a->izq = a->der = NULL;
	}
	else if(a->dato >elem)
	{
		a->izq=Inselem(a->izq,elem);
	}
	else if(a->dato < elem)
	{
		a->der=Inselem(a->der, elem);
	}
	return a;
}

Abb *leeArchivoEnABB(const char *nombreArchivo)
{
	FILE *archivo;
	Abb *a;
	a=NULL;
	int dato, cont, total;
	archivo=fopen(nombreArchivo,"rb");
	fread(&(total),sizeof(int),1,archivo);//obtiene y guarda la cantidad de elementos en el archivo 
	for(cont =0;cont<total;cont++)
	{
		fread(&(dato),sizeof(int),1,archivo); //cada elemento es insertado en el arbol
		a=Inselem(a,dato); 
	}
	fclose(archivo);
	return (a);
}

void Recorre(Abb *a,FILE *archivo)
{
	if (a->izq != NULL){
        Recorre(a->izq,archivo);
    }
	fwrite(&(a->dato),sizeof(int),1,archivo);	
	if(a->der!=NULL)
	{
		Recorre(a->der,archivo);
	}
}


int generaArchivoOrdenado(Abb *a,char *ArchivoOrdenado)
{
	int cant;int i;
	FILE *archivo;
	archivo=fopen(ArchivoOrdenado,"wb");
	cant=cantidad(a);
	fwrite(&(cant),sizeof(int),1,archivo);
	Recorre(a,archivo);
	fclose(archivo);
}

int cantidad(Abb *a)
{
	if(a==NULL)
	{
		return 0;
	}
	else
	{
		return (cantidad(a->izq)+1+cantidad(a->der));
	}
}

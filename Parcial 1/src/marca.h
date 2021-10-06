/*
 * marca.h
 *
 *
 *
 */

//#ifndef MARCA_H_
//#define MARCA_H_

//#endif /* MARCA_H_ */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int idMarca;
	char descripcion[20];
	int isEmpty;

}eMarca;

int hardcodearMarcas(eMarca array[], int TAM);
int mostrarMarca(eMarca unaMarca);
int listarMarcas(eMarca array[], int TAM);
int buscarMarca_segunDescrip(eMarca array[], int TAM, char descripcion[]);

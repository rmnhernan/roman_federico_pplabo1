/*
 * marca.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Pc And the boyz
 */
#include "marca.h"


int hardcodearMarcas(eMarca array[], int TAM)
{
	int retorno = -1;

	int auxID[4] = {1000, 1001, 1002, 1003};
	char auxDescripMarca[4][20] = {"Boeing","Airbus","ATR","Bombardier"};


	int i;
	if(array != NULL && array > 0)
	{
		for(i=0; i<TAM; i++)
		{
			array[i].idMarca = auxID[i];
			strcpy(array[i].descripcion, auxDescripMarca[i]);
			array[i].isEmpty = 1;
		}
		retorno = 1;
	}

	return retorno;
}



int mostrarMarca(eMarca unaMarca)
{
	int retorno = -1;

	if(unaMarca.isEmpty == 1)
	{
		printf("%d %16s\n", unaMarca.idMarca, unaMarca.descripcion);
		retorno = 1;
	}

	return retorno;
}
int listarMarcas(eMarca array[], int TAM)
{
	int retorno = -1;
	int i;
	if(array != NULL && array > 0)
	{
		printf("\nID    -    Descripcion\n");
		for(i=0; i<TAM; i++)
		{
			mostrarMarca(array[i]);
		}
		retorno = 1;
	}
	return retorno;
}

int buscarMarca_segunDescrip(eMarca array[], int TAM, char descripcion[])
{
	int i;
	int auxID = -1;
	if(array != NULL && array > 0)
	{
		for(i=0;i<TAM; i++)
		{
			if(strcmp(array[i].descripcion, descripcion) == 0)
			{
				auxID = array[i].idMarca;
				break;
			}

		}
	}
	return auxID;
}


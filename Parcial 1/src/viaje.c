/*
 * viaje.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Pc And the boyz
 */


#include "viaje.h"


int hardcodearViajes(eViaje array[], int TAM)
{
	int retorno = -1;

	int auxID[5] = {100, 101, 102, 103,104};
	char auxDescripViaje[5][20] = {"Salta","Tucuman","Neuquen","Chubut", "Corrientes"};
	float aux_kms[5] = {1462.5, 1247.6, 1139.4, 670, 1735.8};



	int i;

	if(array != NULL && array > 0)
	{
		for(i=0; i<TAM; i++)
		{
			array[i].idViaje = auxID[i];
			strcpy(array[i].descripcion, auxDescripViaje[i]);
			array[i].kms = aux_kms[i];
			array[i].isEmpty = 1;
		}
		retorno = 1;
	}

	return retorno;
}

int mostrarViaje(eViaje unViaje)
{
	int retorno = -1;
	if(unViaje.isEmpty == 1)
	{
		printf("%d %14s %16.2f\n", unViaje.idViaje, unViaje.descripcion, unViaje.kms);
		retorno = 1;
	}

	return retorno;
}

int listarViajes(eViaje array[], int TAM)
{
	int retorno = -1;
	int i;
	if(array != NULL && array > 0)
	{
		printf("\nID    -    Descripcion   -   Kms.\n");
		for(i=0; i<TAM; i++)
		{
			mostrarViaje(array[i]);
		}
		retorno = 1;
	}
	return retorno;
}

int buscarViaje_segunDescrip(eViaje array[], int TAM, char descripcion[])
{
	int i;
	int auxID = -1;
	if(array != NULL && array > 0)
	{
		for(i=0;i<TAM; i++)
		{
			if(strcmp(array[i].descripcion, descripcion) == 0)
			{
				auxID = array[i].idViaje;
				break;
			}

		}
	}
	return auxID;
}

/*
 * avion.c
 *
 *  Created on: 6 oct. 2021
 *
 */
#include "avion.h"

eAvion crearAvion()
{
	eAvion avionIngresado;
	eFecha fechaAvion;

	char auxViaje[25];
	char auxMarca[20];

	printf("Ingrese la matricula (numerico):");
	scanf("%d", &avionIngresado.matricula);

	printf("Ingrese el dia:");
	scanf("%d", &fechaAvion.dia);

	printf("Ingrese el mes:");
	scanf("%d", &fechaAvion.mes);

	printf("Ingrese el anio:");
	scanf("%d", &fechaAvion.anio);

	avionIngresado.fecha = fechaAvion;

	printf("Ingrese el viaje:");
	fflush(stdin);
	scanf("%[^\n]", auxViaje);


	printf("Ingrese la marca:");
	fflush(stdin);
	scanf("%[^\n]", auxMarca);

	printf("Ingrese el modelo (anio de fabricacion):");
	scanf("%d", &avionIngresado.modelo);

	printf("Ingrese la cantidad de asientos:");
	scanf("%d", &avionIngresado.cantAsientos);

	avionIngresado.isEmpty = 1;

	return avionIngresado;
}


int inicializarAviones(eAvion array[], int TAM)
{
	int retorno = -1;
	int i;
	if(array != NULL && array > 0)
	{
		for(i=0; i<TAM; i++)
		{
			array[i].isEmpty = 0;
		}
		retorno = 1;
	}
	return retorno;
}


int buscarLibre (eAvion array[], int TAM)
{
    int index;
    index = -1;

    int i;
    for (i = 0; i < TAM; i++)
    {
      if (array[i].isEmpty == 0)
	  {
	     index = i;
	     break;
	  }

    }
    return index;
}

int cargarAvion(eAvion array[], int TAM, int* idAvion)
{
	int index;
	int retorno = -1;

	index = buscarLibre(array, TAM);

	if(index != -1)
	{
		array[index] = crearAvion();
		array[index].idAvion = *idAvion;
		(*idAvion)++;
	}
	retorno = 1;

	return retorno;
}

int mostrarAvion(eAvion unAvion)
{
	int retorno = -1;
	if(unAvion.isEmpty == 1)
	{
		printf("%d - %6d - %10d/%d/%d - %4d - %8d - %8d - %8d\n", unAvion.idAvion,
														unAvion.matricula,
														unAvion.fecha,
														unAvion.idMarca,
														unAvion.idViaje,
														unAvion.modelo,
														unAvion.cantAsientos);
		retorno = 1;
	}
	return retorno;
}

int listarAviones(eAvion array[], int TAM)
{
	int retorno = -1;
	int i;
	if(array != NULL && array > 0)
	{
		printf("\nID  - Matricula    -   Fecha   -   Viaje  -  Marca  -  Modelo  -  Asientos\n");
		for(i=0; i<TAM; i++)
		{
			mostrarAvion(array[i]);
		}
		retorno = 1;
	}
	return retorno;
}

int buscarAvion_porID(eAvion array[], int TAM, int ID)
{
	int posicion = -1;
	int i;
	if(array != NULL && array > 0)
	{
		for(i=0; i<TAM; i++)
		{
			if(ID == array[i].idAvion)
			{
				posicion = i;
				break;
			}
		}
	}
	return posicion;
}


int modificarAvion(eAvion array[], int TAM)
{
	int retorno = -1;
	int auxID;
	eFecha auxFecha;
	char auxViaje[25];
	char auxMarca[20];
	int posicion;
	int opcion;
	char confirmacion;

	listarAviones(array, TAM);

	printf("Ingrese el ID del avion a modificar:");
	scanf("%d", &auxID);

	posicion = buscarAvion_porID(array, TAM, auxID);
	if(posicion == -1)
	{
		printf("\nError, ID no encontrado.\n");
	}else
	{
		printf("\nID encontrado, que dato desea modificar?\n1.Matricula\n2.Fecha\n3.Viaje\n4.Marca\n5.Modelo\n6.Cant. asientos\n\nSu opcion:");
	}

	scanf("%d", &opcion);

	do
	{
		switch(opcion)
		{
			case 1:
			printf("Ingrese la nueva matricula:");
			scanf("%d", &array[posicion].matricula);
			break;


			case 2:
			printf("Ingrese la nueva fecha:");
			printf("\nDia:");
			scanf("%d", &auxFecha.dia);
			printf("\nMes:");
			scanf("%d", &auxFecha.mes);
			printf("\nAnio:");
			scanf("%d", &auxFecha.anio);
			array[posicion].fecha = auxFecha;

			break;

			case 3:
			printf("Ingrese el nuevo viaje:");
			fflush(stdin);
			scanf("%[^\n]", auxMarca);
			break;

			case 4:
			printf("Ingrese la nueva marca:");
			fflush(stdin);
			scanf("%[^\n]", auxViaje);
			break;

			case 5:
			printf("Ingrese el nuevo modelo:");
			scanf("%d", &array[posicion].modelo);
			break;

			case 6:
			printf("Ingrese la nueva cantidad de asientos:");
			scanf("%d", &array[posicion].cantAsientos);
			break;
		}

		retorno = 1;
		printf("Desea confirmar la modificacion? (s/n):");
		fflush(stdin);
		scanf("%c", &confirmacion);

	}while(confirmacion != 's');

	return retorno;
}

int eliminarAvion(eAvion array[], int TAM)
{
	int retorno = -1;
	int posicion;
	int auxID;
	char confirmacion;


	listarAviones(array, TAM);

	printf("Ingrese el ID del avion a eliminar:");
	scanf("%d", &auxID);

	posicion = buscarAvion_porID(array, TAM, auxID);
	if(posicion != -1)
	{
		printf("\nID encontrado:\n");
		mostrarAvion(array[posicion]);
		printf("\n\nEsta seguro de que desea eliminar este elemento? (s/n)\nConfirmacion:");
		fflush(stdin);
		scanf("%c", &confirmacion);
	}else
	{

		printf("\nError, ID no encontrado.\n");
	}

	if(confirmacion == 's')
	{
		array[posicion].isEmpty = 0;
		retorno = 1;
	}


	return retorno;
}


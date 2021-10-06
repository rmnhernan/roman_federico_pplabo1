/*
 ============================================================================
(1) Las instancias validas son: 1er Parcial (PP), Recuperatorio 1er Parcial (RPP), 2do Parcial (SP), Recuperatorio 2do
Parcial (RSP), Final (FIN).
(2) Campos a ser completados por el docente.
Desarrollar en ANSI C:

Se necesita administrar la asignaci�n de los vuelos realizados por aviones en un d�a y para eso se deber� desarrollar
lo siguiente:

ENTIDADES:

Marca:
� id (comienza en 1000)
� descripci�n (m�x 20 caracteres)

Avion:
� idAvion
� matricula
� fecha
� idViaje
� idMarca (Validar-debe existir en Marca)
� modelo (a�o de fabricaci�n)
� cantAsientos

Viaje:
� idViaje (comienza en 100)
� descripci�n (m�ximo 25 caracteres)
� kms

DATOS PREVIOS:
Los arrays de marca y viaje deber�n ser hardcodeados.

Marca ({1000, Boeing}
{1001, Airbus}
{1002, ATR}
{1003, Bombardier})

Viaje ({100, Salta, 1462,5 kms}
{101, Tucuman, 1247,6 kms}
{102, Neuquen, 1139,4 kms}
{103, Corrientes, 670 kms}
{104, Chubut, 1735,8 kms})

MENU DE OPCIONES:
A. ALTA AVION: El idAvion debe comenzar en 1 y ser autonum�rico y secuencial.
B. MODIFICAR AVION: Se ingresar� la matr�cula, permitiendo en un submen� modificar:
� Modelo
� Cantidad de asientos
C. BAJA AVION: Se ingresar� la matr�cula del avi�n y se realizar� una baja l�gica.
D. LISTAR AVIONES: Hacer un �nico listado de todos los aviones ordenados por marca y
por matr�cula.
E. LISTAR VIAJES
F. LISTAR MARCAS

NOTAS:
I. Se deber� desarrollar bibliotecas por cada entidad, las cuales contendr�n las funciones Alta, Baja,
Modificar y Listar.
II. Las validaciones (input), deber�n estar en una biblioteca aparte.
III. Tener en cuenta que no se podr� ingresar a los casos Modificar, Baja y Listar; sin antes haber realizado al
menos un Alta (utilizar banderas y/o contadores).
IV. El c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y respetar las
reglas de estilo de la c�tedra.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"
#include "marca.h"
#include "viaje.h"
#define TAM_AV 5
#define TAM_V 5
#define TAM_MARC 4

int main(void) {

	setbuf(stdout, NULL);
	int id_avion = 1; //ID autoincremental

	eAvion arrayAviones[TAM_AV];
	eViaje arrayViajes[TAM_V];
	eMarca arrayMarcas[TAM_MARC];

	hardcodearViajes(arrayViajes, TAM_V);
	hardcodearMarcas(arrayMarcas, TAM_MARC);
	inicializarAviones(arrayAviones, TAM_AV);

	int opcion;

	    do
	    {
	        printf("\n------MENU PRINCIPAL------\n");
	        printf("\nElija su opcion: \n\n");

	        printf("1.Alta de avion. \n");
	        printf("2.Modificar avion. \n");
	        printf("3.Dar de baja avion. \n");
	        printf("4.Listar aviones. \n");
	        printf("5.Listar viajes. \n");
	        printf("6.Listar marcas. \n");

	        printf("7. Salir.\n");


	        printf("\nSu opcion:");
	        scanf("%d", &opcion);

	        switch(opcion)
	        {
	            case 1:
	            if(cargarAvion(arrayAviones, TAM_AV, &id_avion) != -1)
	            {
	            	printf("\nAvion cargado correctamente.\n");
	            }else
	            {
	            	printf("\nNo se pudo cargar, array lleno/no disponible.\n");
	            }
	            break;


	            case 2:
	            if(modificarAvion(arrayAviones, TAM_AV) == 1)
	            {
	            	printf("\nAvion modificado.\n");
	            }else
	            {
	            	printf("Error al modificar.");
	            }
	            break;

	            case 3:
	            if(eliminarAvion(arrayAviones, TAM_AV) == 1)
	            {
	            	printf("\nElemento eliminado.\n");
	            }else
	            {
	            	printf("\nNo se elimino el elemento.\n");
	            }
	            break;

	            case 4:
	            listarAviones(arrayAviones, TAM_AV);
	            break;

	            case 5:
	            listarViajes(arrayViajes, TAM_V);
	            break;

	            case 6:
	            listarMarcas(arrayMarcas, TAM_MARC);
	            break;
	        }

	    }while (opcion != 7);

	return EXIT_SUCCESS;
}

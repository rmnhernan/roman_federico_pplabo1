/*
 * avion.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Pc And the boyz
 */

#ifndef AVION_H_
#define AVION_H_



#endif /* AVION_H_ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"


typedef struct
{
	int idAvion;
	int matricula;
	eFecha fecha;
	int idViaje; //FK
	int idMarca; //FK(Validar-debe existir en Marca)
	int modelo; //(año de fabricación)
	int cantAsientos;
	int isEmpty;

}eAvion;

int inicializarAviones(eAvion array[], int TAM);
eAvion crearAvion();
int buscarLibre(eAvion array[], int TAM);
int cargarAvion(eAvion array[], int TAM, int* idAvion);
int mostrarAvion(eAvion unAvion);
int listarAviones(eAvion array[], int TAM);
int buscarAvion_porID(eAvion array[], int TAM, int ID);

int modificarAvion(eAvion array[], int TAM);
int eliminarAvion(eAvion array[], int TAM);

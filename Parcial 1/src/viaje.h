/*
 * viaje.h
 *
 *  Created on: 6 oct. 2021
 *
 */

#ifndef VIAJE_H_
#define VIAJE_H_



#endif /* VIAJE_H_ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int idViaje;
	char descripcion[25];
	float kms;
	int isEmpty;

}eViaje;

int hardcodearViajes(eViaje array[], int TAM);

int mostrarViaje(eViaje unaMarca);
int listarViajes(eViaje array[], int TAM);
int buscarViaje_segunDescrip(eViaje array[], int TAM, char descripcion[]);

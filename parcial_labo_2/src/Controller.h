/*
 * Controller.h
 *
 *  Created on: 15 nov. 2022
 *      Author: nicolas
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_listarJugadores(LinkedList* pArrayListJugador);

#endif /* CONTROLLER_H_ */

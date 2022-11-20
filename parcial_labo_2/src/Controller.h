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
int controller_agregarJugador(LinkedList* pArrayListJugador , int* contadorID);
int controller_removerVenta(LinkedList* pArrayListVenta);
int controller_editarJugador(LinkedList* pArrayListVenta);
int controller_saveAsText(char* path, LinkedList* pArrayListLibro);
int controller_contarPorPrecio(LinkedList* pArrayListLibro, int* cantidad, int* cantidad2, int* cantidadVendidos, int* cantidadModelo);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
#endif /* CONTROLLER_H_ */

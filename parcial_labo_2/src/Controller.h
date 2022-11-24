/*
 * Controller.h
 *
 *  Created on: 15 nov. 2022
 *      Author: nicolas
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListVenta);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListVenta);
int controller_listarVentas(LinkedList* pArrayListVenta);
int controller_agregarJugador(LinkedList* pArrayListVenta);
int controller_removerVenta(LinkedList* pArrayListVenta);
int controller_editarJugador(LinkedList* pArrayListVenta);
int controller_GuardarComoTexto(char* path, LinkedList* pArrayListVenta);
int controller_contarPorPrecio(LinkedList* pArrayListVenta, int* cantidadDiez, int* cantidadVeinte, int* cantidadVendidos, int* cantidadModelo);
int controller_guardarVentasModoTexto(char* path , LinkedList* pArrayListVenta);
int controller_guardarVentasModoBinario(char* path , LinkedList* pArrayListVenta);
int controllerCargarId(char* path, char* auxiliarID);
#endif /* CONTROLLER_H_ */

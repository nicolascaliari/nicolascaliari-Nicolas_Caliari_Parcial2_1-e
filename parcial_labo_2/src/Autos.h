/*
 * Autos.h
 *
 *  Created on: 15 nov. 2022
 *      Author: nicolas
 */

#ifndef AUTOS_H_
#define AUTOS_H_

typedef struct
{
	int ID_venta;
	int fecha_venta;
	char modelo_auto[30];
	int cantidad;
	int precio_unitario;
	int tarjeta_credito;
}Auto;
#include "LinkedList.h"

Auto* auto_new();
Auto* auto_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);
void auto_delete(Auto* this);
int auto_setId(Auto* this,int id);
int auto_getId(Auto* this,int* id);
int auto_setFecha_venta(Auto* this,int fecha_venta);
int auto_getFecha_venta(Auto* this,int* fecha_venta);
int auto_setModelo(Auto* this,char* modelo);

int auto_getModelo(Auto* this,char* modelo);

int auto_setCantidad(Auto* this,int cantidad);

int auto_getCantidad(Auto* this,int* cantidad);
int auto_setPrecio_unitario(Auto* this,int precio);
int auto_getPrecio_unitario(Auto* this,int* precio);

int auto_setTarjeta_credito(Auto* this,int tarjeta);

int auto_getTarjeta_credito(Auto* this,int* tarjeta);


int imprimirAuto(LinkedList* pArrayListaJugadores , int indice);

#endif /* AUTOS_H_ */

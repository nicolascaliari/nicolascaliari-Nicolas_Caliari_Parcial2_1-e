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
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct
{
	int ID_venta;
	Fecha unaFecha;
	char modelo_auto[30];
	int cantidad;
	float precio_unitario;
	char tarjeta_credito[30];
}Venta;
#include "LinkedList.h"

Venta* venta_new();
Venta* venta_newParametros(char* idStr,char* fechaStrDia,char* fechaStrMes, char* fechaStrAnio,char* modeloStr, char* cantidadStr, char* precioStr, char* tarjetaStr);
void venta_delete(Venta* this);
int imprimirAuto(LinkedList* pArrayListaJugadores , int indice);


int venta_setId(Venta* this,int id);

int venta_getId(Venta* this,int* id);

int venta_setModelo(Venta* this,char* modelo);

int venta_getModelo(Venta* this,char* modelo);

int venta_setCantidad(Venta* this,int cantidad);

int venta_getCantidad(Venta* this,int* cantidad);

int venta_setPrecio_unitario(Venta* this ,float precio);

int venta_getPrecio_unitario(Venta* this,float* precio);

int venta_setTarjeta_credito(Venta* this,char* tarjeta);

int venta_getTarjeta_credito(Venta* this,char* tarjeta);

int venta_setFecha_dia(Venta* this,int id);

int venta_getFecha_dia(Venta* this,int* id);

int venta_setFecha_mes(Venta* this,int id);

int venta_getFecha_mes(Venta* this,int* id);

int venta_setFecha_anio(Venta* this,int id);

int venta_getFecha_anio(Venta* this,int* id);


int ventaContadorMayorADiezMil(void* libro);
int ventaContadorMayorAVeinteMil(void* libro);
int ventaAcumuladorUnidadesVendidas(void* libro);
int ventaAcumuladorVentasDeModelo(void* libro);


int encontrarVenta(LinkedList* pArrayListaJugadores, int indice);

#endif /* AUTOS_H_ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autos.h"
#include "Controller.h"
#include "Validaciones.h"
#include "LinkedList.h"


/**
 * \brief Reserva espacio en memoria para el tipo de dato Jugador.
 * \param void
 * \return Puntero a Jugador.
**/
Auto* auto_new()
{
	Auto* pJugador;

	pJugador =(Auto*)malloc(sizeof(Auto));

	if(pJugador != NULL)
	{
		auto_setId(pJugador, 0);
		auto_setFecha_venta(pJugador, 0);
		auto_setModelo(pJugador, " ");
		auto_setCantidad(pJugador, 0);
		auto_setPrecio_unitario(pJugador, 0);
		auto_setTarjeta_credito(pJugador, 0);
	}
	return pJugador;
}


/**
 * \brief Setea los datos en los campos.
 * \param 6 punteros a char.
 * \return Puntero a jugador.
**/
Auto* auto_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Auto *pJugador = auto_new();

	if(pJugador != NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL)
	{
				if(!(auto_setId(pJugador, atoi(idStr)) &&
				auto_setFecha_venta(pJugador, atoi(nombreCompletoStr)) &&
				auto_setModelo(pJugador, edadStr) &&
				auto_setCantidad(pJugador,atoi(posicionStr)) &&
				auto_setPrecio_unitario(pJugador, atoi(nacionalidadStr)) &&
				auto_setTarjeta_credito(pJugador, atoi(idSelccionStr))))
				{
					auto_delete(pJugador);
					pJugador = NULL;
				}

	}
	return pJugador;
}

/**
 * \brief Libera el espacio en memoria de un tipo de dato Jugador.
 * \param Puntero a Jugador
 * \return void.
**/
void auto_delete(Auto* this)
{
	if(this != NULL)
	{
		free(this);
	}
}



/**
 * \brief Carga un dato de tipo int en el campo id de jugador.
 * \param puntero a jugador
 * \param int
 * \return int 1 Bien, 0 ERROR.
**/
int auto_setId(Auto* this,int id)
{
	int retorno = 0;
	if(this != NULL && id >= 0)
	{
		this->ID_venta = id;
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief Consigue un dato de tipo int en el campo id de jugador.
 * \param puntero a jugador
 * \param puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
int auto_getId(Auto* this,int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->ID_venta;
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief Carga un dato de tipo char en el campo nombreCompleto de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
int auto_setFecha_venta(Auto* this,int fecha_venta)
{
	int retorno = 0;
	if(this != NULL && fecha_venta > 0)
	{
		this->fecha_venta = fecha_venta;
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief Consigue un dato de tipo char en el campo nombreCompleto de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
int auto_getFecha_venta(Auto* this,int* fecha_venta)
{
	int retorno = 0;
	if(this != NULL && fecha_venta != NULL)
	{
		*fecha_venta = this->fecha_venta;
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief Carga un dato de tipo char en el campo posicion de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
int auto_setModelo(Auto* this,char* modelo)
{
	int retorno = 0;
	if(this != NULL && modelo != NULL)
	{
		strncpy(this->modelo_auto, modelo,30);
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief Consigue un dato de tipo char en el campo posicion de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
int auto_getModelo(Auto* this,char* modelo)
{
	int retorno = 0;
	if(this != NULL && modelo != NULL)
	{
		strncpy(modelo, this->modelo_auto, 30);
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief Carga un dato de tipo char en el campo nacionalidad de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
int auto_setCantidad(Auto* this,int cantidad)
{
	int retorno = 0;
	if(this != NULL && cantidad > 0)
	{
		this->cantidad = cantidad;
		retorno = 1;
	}
	return retorno;
}


/**
 * \brief Consigue un dato de tipo char en el campo nacionalidad de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
int auto_getCantidad(Auto* this,int* cantidad)
{
	int retorno = 0;
	if(this != NULL && cantidad != NULL)
	{
		*cantidad = this->cantidad;
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief Carga un dato de tipo int en el campo edad de jugador.
 * \param puntero a jugador
 * \param int
 * \return int 1 Bien, 0 ERROR.
**/
int auto_setPrecio_unitario(Auto* this,int precio)
{
	int retorno = 0;
	if(this != NULL && precio > 1)
	{
		this->precio_unitario = precio;
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief Consigue un dato de tipo int en el campo edad de jugador.
 * \param puntero a jugador
 * \param puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
int auto_getPrecio_unitario(Auto* this,int* precio)
{
	int retorno = 0;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio_unitario;
		retorno = 1;
	}
	return retorno;
}


/**
 * \brief Carga un dato de tipo int en el campo idSeleccion de jugador.
 * \param puntero a jugador
 * \param int
 * \return int 1 Bien, 0 ERROR.
**/
int auto_setTarjeta_credito(Auto* this,int tarjeta)
{
	int retorno = 0;
	if(this != NULL && tarjeta > 0)
	{
		this->tarjeta_credito = tarjeta;
		retorno = 1;
	}
	return retorno;
}


/**
 * \brief Consigue un dato de tipo int en el campo idSeleccion de jugador.
 * \param puntero a jugador
 * \param puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
int auto_getTarjeta_credito(Auto* this,int* tarjeta)
{
	int retorno = 0;
	if(this != NULL && tarjeta != NULL)
	{
		*tarjeta = this->tarjeta_credito;
		retorno = 1;
	}
	return retorno;
}




/*
 * \brief Imprime jugador
 * \param puntero a Linkedlist
 * \param int
 * \return 0 si funciono, -1 si hubo un error
 */

int imprimirAuto(LinkedList* pArrayListaJugadores , int indice)
{
	int retorno = -1;
	  int axuId;
	    int auxiliarFecha;
	    char axuModelo[30];
	    int cantidad;
	    int auxPrecio;
	    int tarjeta_credito;
	Auto* auxJugador =NULL;

	 if(pArrayListaJugadores != NULL && indice >= 0 && indice < ll_len(pArrayListaJugadores))
	 {
		 auxJugador = (Auto*)ll_get(pArrayListaJugadores, indice);

		if(auxJugador != NULL)
		{
			 if(auto_getId(auxJugador, &axuId)
			     && auto_getFecha_venta(auxJugador, &auxiliarFecha)
			     && auto_getModelo(auxJugador, axuModelo)
			     && auto_getCantidad(auxJugador, &cantidad)
			     && auto_getPrecio_unitario(auxJugador, &auxPrecio)
				 && auto_getTarjeta_credito(auxJugador, &tarjeta_credito)){



	        	printf("|%10d | %20d | %10s | %20d | %10d |  %10d  |\n", axuId, auxiliarFecha, axuModelo, cantidad,auxPrecio, tarjeta_credito);
	        	retorno  = 0;
	        }
		}
	 }
	 return retorno;
}

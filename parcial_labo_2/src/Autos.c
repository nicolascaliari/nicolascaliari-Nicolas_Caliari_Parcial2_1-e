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
Venta* venta_new()
{
	Venta* pVenta;

	pVenta =(Venta*)malloc(sizeof(Venta));

	if(pVenta != NULL)
	{
		venta_setId(pVenta, 0);
		venta_setFecha_dia(pVenta, 0);
		venta_setFecha_mes(pVenta, 0);
		venta_setFecha_anio(pVenta, 0);
		venta_setModelo(pVenta, " ");
		venta_setCantidad(pVenta, 0);
		venta_setPrecio_unitario(pVenta, 0);
		venta_setTarjeta_credito(pVenta, " ");
	}
	return pVenta;
}


/**
 * \brief Setea los datos en los campos.
 * \param 6 punteros a char.
 * \return Puntero a jugador.
**/
Venta* venta_newParametros(char* idStr,char* fechaStrDia,char* fechaStrMes, char* fechaStrAnio,char* modeloStr, char* cantidadStr, char* precioStr, char* tarjetaStr)
{
	Venta *pVenta = venta_new();

	if(pVenta != NULL && idStr != NULL && fechaStrDia != NULL && modeloStr != NULL && cantidadStr != NULL && precioStr != NULL && tarjetaStr != NULL)
	{
				if(venta_setId(pVenta, atoi(idStr)) == 0 ||
				venta_setFecha_dia(pVenta, atoi(fechaStrDia)) == 0 ||
				venta_setFecha_mes(pVenta, atoi(fechaStrMes)) == 0 ||
				venta_setFecha_anio(pVenta, atoi(fechaStrAnio)) == 0 ||
				venta_setModelo(pVenta, modeloStr) == 0 ||
				venta_setCantidad(pVenta,atoi(cantidadStr)) == 0 ||
				venta_setPrecio_unitario(pVenta, atof(precioStr)) == 0 ||
				venta_setTarjeta_credito(pVenta, tarjetaStr) == 0)
				{
					venta_delete(pVenta);
					pVenta = NULL;
				}

	}
	return pVenta;
}

/**
 * \brief Libera el espacio en memoria de un tipo de dato Jugador.
 * \param Puntero a Jugador
 * \return void.
**/
void venta_delete(Venta* this)
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
int venta_setId(Venta* this,int id)
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
int venta_getId(Venta* this,int* id)
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
 * \brief Carga un dato de tipo char en el campo posicion de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
int venta_setModelo(Venta* this,char* modelo)
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
int venta_getModelo(Venta* this,char* modelo)
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
int venta_setCantidad(Venta* this,int cantidad)
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
int venta_getCantidad(Venta* this,int* cantidad)
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
int venta_setPrecio_unitario(Venta* this,float precio)
{
	int retorno = 0;
	if(this != NULL && precio > 0)
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
int venta_getPrecio_unitario(Venta* this,float* precio)
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
int venta_setTarjeta_credito(Venta* this,char* tarjeta)
{
	int retorno = 0;
	if(this != NULL && tarjeta > 0)
	{
		strncpy(this->tarjeta_credito, tarjeta,30);
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
int venta_getTarjeta_credito(Venta* this,char* tarjeta)
{
	int retorno = 0;
	if(this != NULL && tarjeta != NULL)
	{
		strncpy(tarjeta, this->tarjeta_credito, 30);
		retorno = 1;
	}
	return retorno;
}

//------------------------------
int venta_setFecha_dia(Venta* this,int id)
{
	int retorno = 0;
	if(this != NULL && id >= 0)
	{
		this->unaFecha.dia = id;
		retorno = 1;
	}
	return retorno;
}


int venta_getFecha_dia(Venta* this,int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->unaFecha.dia;
		retorno = 1;
	}
	return retorno;
}


int venta_setFecha_mes(Venta* this,int id)
{
	int retorno = 0;
	if(this != NULL && id >= 0)
	{
		this->unaFecha.mes = id;
		retorno = 1;
	}
	return retorno;
}


int venta_getFecha_mes(Venta* this,int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->unaFecha.mes;
		retorno = 1;
	}
	return retorno;
}




int venta_setFecha_anio(Venta* this,int id)
{
	int retorno = 0;
	if(this != NULL && id >= 0)
	{
		this->unaFecha.anio = id;
		retorno = 1;
	}
	return retorno;
}


int venta_getFecha_anio(Venta* this,int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->unaFecha.anio;
		retorno = 1;
	}
	return retorno;
}

//------------------------------

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
		int fecha_dia;
		int fecha_mes;
		int fecha_anio;
	    char axuModelo[30];
	    int cantidad;
	    float auxPrecio;
	    char tarjeta_credito[30];
	    Venta* pVenta =NULL;

	 if(pArrayListaJugadores != NULL && indice >= 0 && indice < ll_len(pArrayListaJugadores))
	 {
		 pVenta = (Venta*)ll_get(pArrayListaJugadores, indice);

		if(pVenta != NULL)
		{
			 if(venta_getId(pVenta, &axuId)
				&& venta_getFecha_dia(pVenta, &fecha_dia)
				&& venta_getFecha_mes(pVenta, &fecha_mes)
				&& venta_getFecha_anio(pVenta, &fecha_anio)
			     && venta_getModelo(pVenta, axuModelo)
			     && venta_getCantidad(pVenta, &cantidad)
			     && venta_getPrecio_unitario(pVenta, &auxPrecio)
				 && venta_getTarjeta_credito(pVenta, tarjeta_credito)){


	        	printf("|%5d |%2d/%2d/%4d|%20s|%20d|$%20f|%20s|\n", axuId, fecha_dia, fecha_mes, fecha_anio,  axuModelo, cantidad,auxPrecio, tarjeta_credito);
	        	retorno  = 0;
	        }
		}
	 }
	 return retorno;
}




//
///*
// * \brief cuenta la cantidad de libros que hay con precio mayor a 500
// * \param recibe un puntero a void
// * \return int la cantidad contada
// */
int ventaContadorMayorADiezMil(void* libro)
{
	int retorno = -1;
	float auxPrecio;
	int auxCantidad;
	int total;
	Venta* auxVenta = (Venta*) libro;

	if(auxVenta != NULL)
	{
		venta_getPrecio_unitario(auxVenta, &auxPrecio);
		venta_getCantidad(auxVenta, &auxCantidad);

		total = auxPrecio*auxCantidad;

		if(total > 10000)
		{

			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}


int ventaContadorMayorAVeinteMil(void* libro)
{
	int retorno = -1;
	float auxPrecio;
	int auxCantidad;
	int total;
	Venta* auxVenta = (Venta*) libro;

	if(auxVenta != NULL)
	{
		venta_getPrecio_unitario(auxVenta, &auxPrecio);
		venta_getCantidad(auxVenta, &auxCantidad);

		total = auxPrecio*auxCantidad;

		if(total > 20000)
		{

			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}


int ventaAcumuladorUnidadesVendidas(void* libro)
{
	int retorno = -1;
	int auxPrecio;
	Venta* auxVenta = (Venta*) libro;

	if(auxVenta != NULL)
	{
		venta_getCantidad(auxVenta, &auxPrecio);

		if(auxPrecio > 0)
		{
			retorno = auxPrecio;
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}



int ventaAcumuladorVentasDeModelo(void* libro)
{
	int retorno = -1;
	int auxPrecio;
	char modeloDeAuto[30] = "Ram 3500";
	char auxModelo[30];
	Venta* auxVenta = (Venta*) libro;

	if(auxVenta != NULL)
	{
		venta_getModelo(auxVenta, auxModelo);

		if(strncmp(modeloDeAuto , auxModelo, 30) == 0)
		{
			venta_getCantidad(auxVenta, &auxPrecio);
			retorno = auxPrecio;
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}




/**
 * \brief Chequea la existencia de jugador.
 * \param Puntero a Linkedlist
 * \param int
 * \return -1 error, si encuentra retorna el indice.
**/
int encontrarVenta(LinkedList* pArrayListaJugadores, int indice)
{
	int retorno =-1;
	int idJugador;
	Venta* pJugador;
	int i;

	if(pArrayListaJugadores != NULL && indice >=0)
	{

	for(i= 0 ; i < ll_len(pArrayListaJugadores); i++)
	{
		pJugador = (Venta*)ll_get(pArrayListaJugadores, i);

		venta_getId(pJugador, &idJugador);

			if(idJugador == indice)
			{
				retorno = ll_indexOf(pArrayListaJugadores, pJugador);
				break;
			}
		}
	}
	return retorno;
}


/**
 * \brief Autoincremente el id
 * \param VOID
 * \return retorna el id
**/
int idAutoincremental()
{
	static int idJugador;
	static int bandera=0;
	char auxId[1000];

	if(bandera== 0)
	{
		if(controllerCargarId("ID.csv", auxId) == 0)
		{
			bandera = 1;
			idJugador = atoi(auxId);
		}
	}

	idJugador++;


	return idJugador;
}

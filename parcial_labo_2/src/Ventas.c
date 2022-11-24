#include "Ventas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "Validaciones.h"
#include "LinkedList.h"


/**
 * \brief Reserva espacio en memoria para el tipo de dato Venta.
 * \param void
 * \return Puntero a Venta.
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
 * \param 8 punteros a char.
 * \return Puntero a Venta.
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
 * \brief Libera el espacio en memoria de un tipo de dato Venta.
 * \param Puntero a Venta
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
 * \brief Carga un dato de tipo int en el campo id de venta.
 * \param puntero a Venta
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
 * \brief Consigue un dato de tipo int en el campo id de Venta.
 * \param puntero a Venta
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
 * \brief Carga un dato de tipo char en el campo modelo de Venta.
 * \param puntero a Venta
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
 * \brief Consigue un dato de tipo char en el campo modelo de Venta.
 * \param puntero a Venta
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
 * \brief Carga un dato de tipo int en el campo cantidad de Venta.
 * \param puntero a Venta
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
 * \brief Consigue un dato de tipo int en el campo cantidad de Venta.
 * \param puntero a Venta
 * \param puntero a int
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
 * \brief Carga un dato de tipo float en el campo precio de Venta.
 * \param puntero a Venta
 * \param float
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
 * \brief Consigue un dato de tipo float en el campo precio de Venta.
 * \param puntero a Venta
 * \param puntero a float
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
 * \brief Carga un dato de tipo char en el campo tarjeta de credito de Venta.
 * \param puntero a Venta
 * \param char
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
 * \brief Consigue un dato de tipo char en el campo tarjeta de credito de Venta.
 * \param puntero a Venta
 * \param char
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

/**
 * \brief Carga un dato de tipo int en el campo dia de Fecha.
 * \param puntero a Venta
 * \param int
 * \return int 1 Bien, 0 ERROR.
**/
int venta_setFecha_dia(Venta* this,int dia)
{
	int retorno = 0;
	if(this != NULL && dia >= 0)
	{
		this->unaFecha.dia = dia;
		retorno = 1;
	}
	return retorno;
}


/**
 * \brief Consigue un dato de tipo int en el campo dia de Fecha.
 * \param puntero a Venta
 * \param puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
int venta_getFecha_dia(Venta* this,int* dia)
{
	int retorno = 0;
	if(this != NULL && dia != NULL)
	{
		*dia = this->unaFecha.dia;
		retorno = 1;
	}
	return retorno;
}


/**
 * \brief Carga un dato de tipo int en el campo mes de Fecha.
 * \param puntero a Venta
 * \param int
 * \return int 1 Bien, 0 ERROR.
**/
int venta_setFecha_mes(Venta* this,int mes)
{
	int retorno = 0;
	if(this != NULL && mes >= 0)
	{
		this->unaFecha.mes = mes;
		retorno = 1;
	}
	return retorno;
}


/**
 * \brief Consigue un dato de tipo int en el campo mes de Fecha.
 * \param puntero a Venta
 * \param puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
int venta_getFecha_mes(Venta* this,int* mes)
{
	int retorno = 0;
	if(this != NULL && mes != NULL)
	{
		*mes = this->unaFecha.mes;
		retorno = 1;
	}
	return retorno;
}



/**
 * \brief Carga un dato de tipo int en el campo anio de Fecha.
 * \param puntero a Venta
 * \param int
 * \return int 1 Bien, 0 ERROR.
**/
int venta_setFecha_anio(Venta* this,int anio)
{
	int retorno = 0;
	if(this != NULL && anio >= 0)
	{
		this->unaFecha.anio = anio;
		retorno = 1;
	}
	return retorno;
}


/**
 * \brief Consigue un dato de tipo int en el campo anio de Fecha.
 * \param puntero a Venta
 * \param puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
int venta_getFecha_anio(Venta* this,int* anio)
{
	int retorno = 0;
	if(this != NULL && anio != NULL)
	{
		*anio = this->unaFecha.anio;
		retorno = 1;
	}
	return retorno;
}

//------------------------------

/*
 * \brief Imprime una venta
 * \param puntero a Linkedlist
 * \param int
 * \return 0 si funciono, -1 si hubo un error
 */

int imprimirVenta(LinkedList* pArrayListaJugadores , int indice)
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


	        	printf("\n|%5d |%2d/%2d/%4d|%20s|%20d|$%20f|%20s|\n", axuId, fecha_dia, fecha_mes, fecha_anio,  axuModelo, cantidad,auxPrecio, tarjeta_credito);
	        	retorno  = 0;
	        }
		}
	 }
	 return retorno;
}




//
///*
// * \brief cuenta la cantidad de ventas que hay con precio mayor a 10.000
// * \param recibe un puntero a void
// * \return int la cantidad contada
// */
int ventaContadorMayorADiezMil(void* venta)
{
	int retorno = 0;
	float auxPrecio;
	int auxCantidad;
	int total;
	Venta* auxVenta = (Venta*) venta;

	if(auxVenta != NULL)
	{
		if(venta_getPrecio_unitario(auxVenta, &auxPrecio) == 1 && venta_getCantidad(auxVenta, &auxCantidad) == 1)
		{
			total = auxPrecio*auxCantidad;
			if(total > 10000)
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

///*
// * \brief cuenta la cantidad de ventas que hay con precio mayor a 20.000
// * \param recibe un puntero a void
// * \return int la cantidad contada
// */
int ventaContadorMayorAVeinteMil(void* venta)
{
	int retorno = 0;
	float auxPrecio;
	int auxCantidad;
	int total;
	Venta* auxVenta = (Venta*) venta;

	if(auxVenta != NULL)
	{
		if(venta_getPrecio_unitario(auxVenta, &auxPrecio) == 1 && venta_getCantidad(auxVenta, &auxCantidad) == 1)
		{
			total = auxPrecio*auxCantidad;

			if(total > 20000)
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}



///*
// * \brief cuenta la cantidad de unidades vendidas totales que hay.
// * \param recibe un puntero a void
// * \return int la cantidad contada
// */
int ventaAcumuladorUnidadesVendidas(void* venta)
{
	int retorno =0;
	int auxCantidad;
	Venta* auxVenta = (Venta*)venta;

	if(auxVenta != NULL)
	{
		if(venta_getCantidad(auxVenta, &auxCantidad) == 1)
		{
			if(auxCantidad > 0)
			{
				retorno = auxCantidad;
			}
		}
	}
	return retorno;
}



///*
// * \brief cuenta la cantidad de unidades vendidas totales que hay de la ram 3500.
// * \param recibe un puntero a void
// * \return int la cantidad contada
// */
int ventaAcumuladorVentasDeModelo(void* libro)
{
	int retorno =0;
	int auxPrecio;
	char modeloDeAuto[30] = "Ram 3500";
	char auxModelo[30];
	Venta* auxVenta = (Venta*) libro;

	if(auxVenta != NULL)
	{
		if(venta_getModelo(auxVenta, auxModelo) == 1)
		{
			if(strncmp(modeloDeAuto , auxModelo, 30) == 0)
			{
				venta_getCantidad(auxVenta, &auxPrecio);
				retorno = auxPrecio;
			}
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

		if(venta_getId(pJugador, &idJugador) == 1)
		{
			if(idJugador == indice)
			{
				retorno = ll_indexOf(pArrayListaJugadores, pJugador);
				break;
			}
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




/**
 * \brief Ordena por id las ventas.
 * \param void* elementoA
 * \param void* elementoB
 * \return 0 error, 1 creciente, -1 decreciente
**/
int ordenarID(void* elementoA, void* elementoB)
{
	int retorno = 0;
	Venta* ventaIdUno;
	Venta* ventaIdDos;
	int idUno;
	int idDos;

	ventaIdUno = (Venta*)elementoA;
	ventaIdDos = (Venta*)elementoB;

	venta_getId(ventaIdUno, &idUno);
	venta_getId(ventaIdDos, &idDos);


		if(idUno > idDos)
		{
			retorno = 1;

		}else if(idUno < idDos)
		{
			retorno = -1;
		}

	return retorno;
}




/**
 * \brief :
 * \param :
 * \return:
**/
int elegirModeloDeAuto(char ModeloElegido[])
{

	int retorno = 0;
	int opcion;

	if(ModeloElegido != NULL){

		if(utn_getNumero(&opcion, "  \nIngrese el modelo del auto"
								"\n1-Mustang"
								"\n2-Peugeot 207"
								"\n3-Volskwagen bora"
								"\n4-Chevrolet corsa"
								"\n5-Crevrolet onix"
								"\n6-Chevrolet cruze"
								"\n7-Fiat cronos"
								"\n8-Peugeot 208"
								"\n9-Fiat 147 ", "\nERROR opcion no validar\nReingrese\n", 1, 9, 2) == 0){

			switch(opcion){

			case 1:
				strncpy(ModeloElegido, "Mustang", 200);
				break;

			case 2:
				strncpy(ModeloElegido, "Pegeout 207", 200);
				break;

			case 3:
				strncpy(ModeloElegido, "Volskwagen BORA", 200);
				break;

			case 4:
				strncpy(ModeloElegido, "Chevrolet CORSA", 200);
				break;

			case 5:
				strncpy(ModeloElegido, "Chevrolet ONIX", 200);
				break;

			case 6:
				strncpy(ModeloElegido, "Chevrolet CRUZE", 200);
				break;

			case 7:
				strncpy(ModeloElegido, "FIAT CRONOS", 200);
				break;

			case 8:
				strncpy(ModeloElegido, "Peugeot 208", 200);
				break;

			case 9:
				strncpy(ModeloElegido, "FIAT 147", 200);
				break;
			}
			retorno = 0;

		}else{

			retorno = -1;
		}

	}
	return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Autos.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_AutoFromText(FILE* pFile , LinkedList* pArrayListVenta)
{
	int retorno = -1;
	char auxID[100];
	char axuFecha[30];
	char auxFecha_dia[100];
	char auxFecha_mes[100];
	char auxFecha_anio[100];
	char auxModelo[100];
	char auxCantidad[100];
	char auxPrecio_unitario[100];
	char auxTarjeta_credito[100];
	int retornoVariable;
	Venta* pAutomovil = NULL;


	if(pFile != NULL && pArrayListVenta != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, axuFecha, auxModelo, auxCantidad, auxPrecio_unitario, auxTarjeta_credito);

		do
		{
		retornoVariable = fscanf(pFile,"%[^,],%[^/]/%[^/]/%[^,], %[^,],%[^,],%[^,],%[^\n]\n", auxID, auxFecha_dia, auxFecha_mes, auxFecha_anio, auxModelo, auxCantidad, auxPrecio_unitario, auxTarjeta_credito);
		if(retornoVariable == 8)
		{
			pAutomovil = venta_newParametros(auxID, auxFecha_dia, auxFecha_mes, auxFecha_anio, auxModelo, auxCantidad, auxPrecio_unitario, auxTarjeta_credito);
			if(pAutomovil != NULL)
			{
				if(ll_add(pArrayListVenta,pAutomovil) == 0)
				{
					retorno = 0;
				}
			}
		}else
		{
			retorno = -1;
			break;
		}

		}while(!feof(pFile));
	}
    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_AutoFromBinary(FILE* pFile, LinkedList* pArrayListJugador){

    int retorno = 0;
    int axuId;
    int fecha_dia;
	int fecha_mes;
	int fecha_anio;
    char axuModelo[30];
    int cantidad;
    float auxPrecio;
    char tarjeta_credito[30];
    Venta* pAutomovil = NULL;
    int retornoVariable;

    if(pFile != NULL && pArrayListJugador != NULL){


        do{

        	pAutomovil = venta_new();

            if(pAutomovil != NULL){

                retornoVariable = fread(pAutomovil, sizeof(Venta), 1, pFile);

                if(retornoVariable == 1){

                    if(!(venta_getId(pAutomovil, &axuId)
                    && venta_getFecha_dia(pAutomovil, &fecha_dia)
					&& venta_getFecha_mes(pAutomovil, &fecha_mes)
					&& venta_getFecha_anio(pAutomovil, &fecha_anio)
                    && venta_getModelo(pAutomovil, axuModelo)
                    && venta_getCantidad(pAutomovil, &cantidad)
                    && venta_getPrecio_unitario(pAutomovil, &auxPrecio)
                    && venta_getTarjeta_credito(pAutomovil ,tarjeta_credito))){

                        retorno = 0;
                        break;

                    }
                    retorno = 1;
                }
            }

        }while(!feof(pFile));
    }
    return retorno;
}

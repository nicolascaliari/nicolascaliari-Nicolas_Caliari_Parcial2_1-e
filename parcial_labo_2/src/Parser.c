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
				printf("%s" , auxTarjeta_credito);
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
//int parser_AutoFromBinary(FILE* pFile, LinkedList* pArrayListJugador){
//
//    int retorno = 0;
//    int axuId;
//    char auxiliarFecha[30];
//    char axuModelo[30];
//    int cantidad;
//    char auxPrecio[30];
//    int tarjeta_credito;
//    Auto* pAutomovil = NULL;
//    int retornoVariable;
//
//    if(pFile != NULL && pArrayListJugador != NULL){
//
//
//        do{
//
//        	pAutomovil = auto_new();
//
//            if(pAutomovil != NULL){
//
//                retornoVariable = fread(pAutomovil, sizeof(Auto), 1, pFile);
//
//                if(retornoVariable == 1){
//
//                    if(!(auto_getId(pAutomovil, &axuId)
//                    && auto_getFecha_venta(pAutomovil, auxiliarFecha)
//                    && auto_getModelo(pAutomovil, axuModelo)
//                    && auto_getCantidad(pAutomovil, &cantidad)
//                    && auto_getPrecio_unitario(pAutomovil, auxPrecio)
//                    && auto_getTarjeta_credito(pAutomovil, &tarjeta_credito))){
//
//                        retorno = 0;
//                        break;
//
//                    }
//                    retorno = 1;
//                }
//            }
//
//        }while(!feof(pFile));
//    }
//    return retorno;
//}

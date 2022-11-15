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
int parser_AutoFromText(FILE* pFile , LinkedList* pArrayListAuto)
{
	int retorno = -1;
	char auxID[100];
	char auxFecha[100];
	char auxModelo[100];
	char auxCantidad[100];
	char auxPrecio_unitario[100];
	char auxTarjeta_credito[100];
	int retornoVariable;
	Auto* jugadorNuevo = NULL;


	if(pFile != NULL && pArrayListAuto != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxFecha, auxModelo, auxCantidad, auxPrecio_unitario, auxTarjeta_credito);

		do
		{
		retornoVariable = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxFecha, auxModelo, auxCantidad, auxPrecio_unitario, auxTarjeta_credito);
		printf("LLegue");
		if(retornoVariable == 6)
		{
			printf("LLegue");
			jugadorNuevo = auto_newParametros(auxID, auxFecha, auxModelo, auxCantidad, auxPrecio_unitario, auxTarjeta_credito);
			if(jugadorNuevo != NULL)
			{
				if(ll_add(pArrayListAuto,jugadorNuevo) == 0)
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
    int auxiliarFecha;
    char axuModelo[30];
    int cantidad;
    int auxPrecio;
    int tarjeta_credito;
    Auto* auxJugador;
    int retornoVariable;

    if(pFile != NULL && pArrayListJugador != NULL){


        do{

            auxJugador = auto_new();

            if(auxJugador != NULL){

                retornoVariable = fread(auxJugador, sizeof(Auto), 1, pFile);

                if(retornoVariable == 1){

                    if(!(auto_getId(auxJugador, &axuId)
                    && auto_getFecha_venta(auxJugador, &auxiliarFecha)
                    && auto_getModelo(auxJugador, axuModelo)
                    && auto_getCantidad(auxJugador, &cantidad)
                    && auto_getPrecio_unitario(auxJugador, &auxPrecio)
                    && auto_getTarjeta_credito(auxJugador, &tarjeta_credito))){

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

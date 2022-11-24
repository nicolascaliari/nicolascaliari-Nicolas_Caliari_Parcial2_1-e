#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Ventas.h"

/** \brief Parsea los datos de los ventas desde el archivo MOCK_DATA.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
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

/** \brief Parsea los datos de los id desde el archivo ID.csv (modo texto).
 *
 * \param path char*
 * \param auxiliarID char*
 * \return int
 *
 */
int parser_ID(FILE* pFile , char* auxiliarID)
{
	int retorno = -1;
	int retornoVariable;

		if(pFile != NULL && auxiliarID != NULL)
		{

			retornoVariable = fscanf(pFile,"%[^\n]\n", auxiliarID);
			if(retornoVariable == 1)
			{
				printf("\nSe otorgo correctamente el ID");
				retorno = 0;
			}else
			{
				printf("\nError");
				retorno = -1;
			}
		}
	    return retorno;
}

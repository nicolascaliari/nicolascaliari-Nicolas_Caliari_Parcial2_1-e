#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autos.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Validaciones.h"
#include "Controller.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListJugador != NULL)
	{
		printf("Lleuge");
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			printf("LLegue");
			if(parser_AutoFromText(pArchivo, pArrayListJugador) == 0)
			{
				printf("\nEl archivo se leyo corrrectamente\n");
				retorno = 0;
			}else
			{
				printf("\nError al leer al archivo");
			}
		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pArchivo;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pArchivo = fopen(path, "rb");
		if(pArchivo != NULL)
		{
			if(parser_AutoFromBinary(pArchivo, pArrayListJugador))
			{
				printf("\nEl archivo se leyo corrrectamente\n");
				retorno = 0;
			}else
			{
				printf("\nError al leer al archivo");
			}
		}
		fclose(pArchivo);
	}
    return retorno;
}




/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */

int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
    Auto* pJugador = NULL;

    	if(pArrayListJugador != NULL)
    	{
    		printf("|%10s | %20s | %10s | %20s | %15s |\n", "ID", "NOMBRE JUGADOR", "EDAD",
    															"POSICION", "NACIONALIDAD");
    		for(int i = 0; i < ll_len(pArrayListJugador); i++)
    		{
    			pJugador = (Auto*)ll_get(pArrayListJugador, i);

    			if(pJugador != NULL)
    			{
    				if(imprimirAuto(pArrayListJugador,i) == 0)
    				{
    					retorno = 0;
    				}
    			}
    		}
    	}else
    	{
    		printf("No funciono bien");
    	}

    return retorno;
}
